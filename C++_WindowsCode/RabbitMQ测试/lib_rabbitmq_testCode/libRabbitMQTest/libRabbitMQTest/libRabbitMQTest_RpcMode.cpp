#include "libRabbitMQTest.h"

/*�ͻ����̷߳���ֵ    **/
int RPC_MODE_CLIENT_THREAD_RESULT = 0;

/*������̷߳���ֵ    **/
int RPC_MODE_SERVER_THREAD_RESULT = 0;

void rpcModeFunc()
{
	printf("************** RABBITMQ RPC MODE FUNC START *************\n\n");

	/*����������߳�    **/
	thread serverThread(rpcMode_serverThreadFunc);

	/*�����ͻ����߳�    **/
	thread clientThread(rpcMode_ClientThreadFunc);

	serverThread.join();
	clientThread.join();

	printf("\n************** RABBITMQ RPC MODE FUNC END *************\n\n");
	printf("Client Thread Result: %d\n", RPC_MODE_CLIENT_THREAD_RESULT);
	printf("Server Thread Result: %d\n", RPC_MODE_SERVER_THREAD_RESULT);
}

int rpcMode_ClientThreadFunc()
{
	amqp_connection_state_t conn = amqp_new_connection();
	if (NULL == conn)
	{
		RPC_MODE_CLIENT_THREAD_RESULT = -1;
		return RPC_MODE_CLIENT_THREAD_RESULT;
	}

	amqp_socket_t* socket = amqp_tcp_socket_new(conn);
	if (NULL == socket)
	{
		RPC_MODE_CLIENT_THREAD_RESULT = -1;
		return RPC_MODE_CLIENT_THREAD_RESULT;
	}

	int socketOpenRet = amqp_socket_open(socket, "192.168.0.188", 5672);
	if(AMQP_STATUS_OK != socketOpenRet)
	{
		RPC_MODE_CLIENT_THREAD_RESULT = -1;
		return RPC_MODE_CLIENT_THREAD_RESULT;
	}

	amqp_rpc_reply_t loginRet = amqp_login(conn, "qhVHost", AMQP_DEFAULT_MAX_CHANNELS, AMQP_DEFAULT_FRAME_SIZE, 0, AMQP_SASL_METHOD_PLAIN, "quhan", "qhmm19971120");
	if(AMQP_RESPONSE_NORMAL != loginRet.reply_type)
	{
		RPC_MODE_CLIENT_THREAD_RESULT = -1;
		return RPC_MODE_CLIENT_THREAD_RESULT;
	}

	/*��ͨ�Źܵ�    **/
	amqp_channel_open_ok_t* openChannelRet = amqp_channel_open(conn, 1);
	
	/*�������ڽ��շ���˷�����Ϣ�Ķ���    **/
	amqp_queue_declare_ok_t* declareQueueRet = amqp_queue_declare(conn, 1, amqp_cstring_bytes("test_rpcmode_client_queue"), 0, 1, 0, 0, amqp_empty_table);
	
	/*�������ն��е���Ϣ��ʽΪRabbitMQ�������������    **/
	amqp_basic_consume_ok_t* basicConsumeRet = amqp_basic_consume(conn, 1, amqp_cstring_bytes("test_rpcmode_client_queue"), amqp_empty_bytes, 0, 1, 0, amqp_empty_table);

	/*�����˽���5��    **/
	for (int i = 0; i < 5; ++i)
	{
		/*������Ϣ����    **/
		amqp_basic_properties_t props = { 0 };
		props._flags = AMQP_BASIC_CONTENT_TYPE_FLAG | AMQP_BASIC_DELIVERY_MODE_FLAG | AMQP_BASIC_REPLY_TO_FLAG | AMQP_BASIC_CORRELATION_ID_FLAG;
		props.content_type = amqp_cstring_bytes("text/plain");
		props.delivery_mode = 2;
		props.reply_to = amqp_bytes_malloc_dup(amqp_cstring_bytes("test_rpcmode_client_queue"));
		props.correlation_id = amqp_cstring_bytes("1");

		/*������Ϣ����    **/
		stringstream ss;
		ss << "Data" << i;

		char* pSendData = new char[ss.str().size() + 1];
		strcpy(pSendData, ss.str().c_str());
		pSendData[ss.str().size()] = '\0';

		/*������Ϣ    **/
		int pubRet = amqp_basic_publish(conn, 1, amqp_cstring_bytes(""), amqp_cstring_bytes("test_rpcmode_server_queue"), 0, 0, &props, amqp_cstring_bytes(pSendData));
		if (AMQP_STATUS_OK == pubRet)
			printf("CLIENT SEND: %s, LEN: %d\n", pSendData, strlen(pSendData));
		else
			printf("CLIENT SEND: ERROR\n");

		delete pSendData;
		pSendData = NULL;

		amqp_bytes_free(props.reply_to);
		amqp_maybe_release_buffers(conn);

		/*�ȴ�����˻ظ���Ϣ    **/
		while (true)
		{
			amqp_frame_t frame = { 0 };
			int result = amqp_simple_wait_frame(conn, &frame);
			if (result < 0)
				break;
			else if (frame.frame_type == AMQP_FRAME_BODY)
			{
				/*�յ���Ϣ���ݺ��˳����ν���ѭ���������´ε��û�����    **/
				char* pBody = new char[frame.payload.body_fragment.len + 1];
				memcpy(pBody, (char *)frame.payload.body_fragment.bytes, frame.payload.body_fragment.len);
				pBody[frame.payload.body_fragment.len] = '\0';

				printf("CLIENT RECEIVE : %s, LEN: %d\n\n", pBody, frame.payload.body_fragment.len);

				delete[] pBody;
				pBody = NULL;

				break;
			}
			else
			{
				/*�յ���Ϣ����ǰ�����յ���Ϣ��method����Ϣ��head    **/
				continue;
			}
		}
	}

	amqp_channel_close(conn, 1, AMQP_REPLY_SUCCESS);
	amqp_connection_close(conn, AMQP_REPLY_SUCCESS);
	amqp_destroy_connection(conn);

	RPC_MODE_CLIENT_THREAD_RESULT = 1;
	return RPC_MODE_CLIENT_THREAD_RESULT;
}

int  rpcMode_serverThreadFunc()
{
	amqp_connection_state_t conn = amqp_new_connection();
	if (NULL == conn)
	{
		RPC_MODE_SERVER_THREAD_RESULT = -1;
		return RPC_MODE_SERVER_THREAD_RESULT;
	}

	amqp_socket_t* socket = amqp_tcp_socket_new(conn);
	if (NULL == socket)
	{
		RPC_MODE_SERVER_THREAD_RESULT = -1;
		return RPC_MODE_SERVER_THREAD_RESULT;
	}

	int openSocketRet = amqp_socket_open(socket, "192.168.0.188", 5672);
	if (AMQP_STATUS_OK != openSocketRet)
	{
		RPC_MODE_SERVER_THREAD_RESULT = -1;
		return RPC_MODE_SERVER_THREAD_RESULT;
	}

	/*��¼*/
	amqp_rpc_reply_t loginRet = amqp_login(conn, "qhVHost", AMQP_DEFAULT_MAX_CHANNELS, AMQP_DEFAULT_FRAME_SIZE, 0, AMQP_SASL_METHOD_PLAIN, "quhan", "qhmm19971120");
	if (AMQP_RESPONSE_NORMAL != loginRet.reply_type)
	{
		RPC_MODE_SERVER_THREAD_RESULT = -1;
		return RPC_MODE_SERVER_THREAD_RESULT;
	}

	/*��ͨ��*/
	amqp_channel_open_ok_t* openChannelRet = amqp_channel_open(conn, 1);

	/*���ͨ���Ƿ�ɹ��򿪣��ȴ�rpc����������ͬrpcͨ��*/
	amqp_rpc_reply_t rpcFirstGetRpcReplyRet = amqp_get_rpc_reply(conn);

	/*�������ڽ��տͻ�����Ϣ�Ķ���    **/
	amqp_queue_declare_ok_t* r = amqp_queue_declare(conn, 1, amqp_cstring_bytes("test_rpcmode_server_queue"), 0, 1, 0, 0, amqp_empty_table);

	/*����������Ϣ�ķ�ʽΪ������������    **/
	amqp_basic_consume_ok_t* consumeRet = amqp_basic_consume(conn, 1, amqp_cstring_bytes("test_rpcmode_server_queue"), amqp_empty_bytes, 0, 1, 0, amqp_empty_table);

	/*��ͻ��˽���    **/
	while(true)
	{
		/*���տͻ��˵���Ϣ    **/
		amqp_maybe_release_buffers(conn);

		amqp_envelope_t envelope;
		memset(&envelope, 0, sizeof(amqp_envelope_t));

		/*���õȴ�ʱ��    **/
		timeval timeout;
		timeout.tv_sec = 5;
		timeout.tv_usec = 0;

		amqp_rpc_reply_t res = amqp_consume_message(conn, &envelope, &timeout, 0);
		if (AMQP_RESPONSE_NORMAL != res.reply_type) 
			break;

		char* pMessageData = new char[envelope.message.body.len + 1];
		memcpy(pMessageData, (char *)envelope.message.body.bytes, envelope.message.body.len);
		pMessageData[envelope.message.body.len] = '\0';

		printf("SERVER RECEIVE: %s, LEN: %d\n", pMessageData, envelope.message.body.len);
			
		/*���ͻ��˻ظ���Ϣ    **/
		if (0 != envelope.message.properties.reply_to.len)
		{
			/*������Ϣ����    **/
			amqp_basic_properties_t reply_props = { 0 };
			reply_props._flags = AMQP_BASIC_CONTENT_TYPE_FLAG | AMQP_BASIC_DELIVERY_MODE_FLAG;
			reply_props.content_type = amqp_cstring_bytes("text/plain");
			reply_props.delivery_mode = 2; 
			reply_props.correlation_id = envelope.message.properties.correlation_id;

			/*������Ϣ    **/
			int pubRet = amqp_basic_publish(conn, 1, amqp_cstring_bytes(""), amqp_cstring_bytes((const char *)envelope.message.properties.reply_to.bytes), 0, 0, &reply_props, amqp_cstring_bytes(pMessageData));
			if (AMQP_STATUS_OK == pubRet)
				printf("SERVER SEND: %s, LEN: %d\n", pMessageData, strlen(pMessageData));
			else
				printf("SERVER SEND: ERROR\n");
		}

		amqp_destroy_envelope(&envelope);

		delete pMessageData;
		pMessageData = NULL;
	}

	amqp_channel_close(conn, 1, AMQP_REPLY_SUCCESS);
	amqp_connection_close(conn, AMQP_REPLY_SUCCESS);
	amqp_destroy_connection(conn);

	RPC_MODE_SERVER_THREAD_RESULT = 1;
	return RPC_MODE_SERVER_THREAD_RESULT;
}

