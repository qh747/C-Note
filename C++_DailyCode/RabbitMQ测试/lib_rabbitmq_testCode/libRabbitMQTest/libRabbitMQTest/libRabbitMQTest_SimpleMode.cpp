#include "libRabbitMQTest.h"

/*�������̷߳���ֵ    **/
int GLOBAL_PUBLISH_THREAD_RESULT = 0;

/*�������̷߳���ֵ    **/
int GLOBAL_CONSUME_THREAD_RESULT = 0;


void simpleModeFunc()
{
	printf("************** RABBITMQ SIMPLE MODE FUNC START *************\n\n");

	/*�����������߳�    **/
	thread publishThread(simpleMode_PublishThreadFunc);

	/*�����������߳�    **/
	thread consumeThread(simpleMode_ConsumeThreadFunc);

	publishThread.join();
	consumeThread.join();

	printf("************** RABBITMQ SIMPLE MODE FUNC END *************\n\n");

	printf("Publish Thread Result: %d\n", GLOBAL_PUBLISH_THREAD_RESULT);
	printf("Consume Thread Result: %d\n", GLOBAL_CONSUME_THREAD_RESULT);
}

int simpleMode_PublishThreadFunc()
{
	/*����һ����RabbitMQ Server������    **/
	amqp_connection_state_t pConn = NULL;
	pConn = amqp_new_connection();

	if (NULL == pConn)
	{
		GLOBAL_PUBLISH_THREAD_RESULT = -1;
		return GLOBAL_PUBLISH_THREAD_RESULT;
	}

	/*����һ����RabbitMQ Serverͨ�ŵ�socket    **/
	amqp_socket_t* pSocket = NULL;
	pSocket = amqp_tcp_socket_new(pConn);

	if (NULL == pSocket)
	{
		GLOBAL_PUBLISH_THREAD_RESULT = -1;
		return GLOBAL_PUBLISH_THREAD_RESULT;
	}

	/*����RabbitMQ Serverͨ�ŵ�socket    **/
	string hostName = "192.168.0.188";
	int port = 5672;
	int openSockRet = amqp_socket_open(pSocket, hostName.c_str(), port);
	if (AMQP_STATUS_OK != openSockRet)
	{
		GLOBAL_PUBLISH_THREAD_RESULT = -1;
		return GLOBAL_PUBLISH_THREAD_RESULT;
	}

	/*��¼RabbitMQ Server, ����Ȩ�޹���    **/
	amqp_rpc_reply_t loginRet = amqp_login(pConn, "qhVHost", AMQP_DEFAULT_MAX_CHANNELS, AMQP_DEFAULT_FRAME_SIZE, 0, AMQP_SASL_METHOD_PLAIN, "quhan", "qhmm19971120");

	/*��ͨ�Źܵ�    **/
	amqp_channel_t channelId = 1;
	amqp_channel_open_ok_t* pCannelOpenRet = amqp_channel_open(pConn, channelId);

	/*������Ϣ    **/
	for (int i = 0; i < 3; ++i)
	{
		/*������Ϣ    **/
		char message[64] = "\0";
		sprintf(message, "%s: %d", "Data", i);

		amqp_bytes_t message_bytes;
		message_bytes.len = sizeof(message);
		message_bytes.bytes = message;

		/*������Ϣ    **/
		int publishRet = amqp_basic_publish(pConn, channelId, amqp_cstring_bytes(""), amqp_cstring_bytes("test_simple_queue"), 0, 0, nullptr, message_bytes);
		if (AMQP_STATUS_OK == publishRet)
			printf("Publisher Send Message : %s\n\n", message);

		Sleep(1000);
	}

	/*�ͷ��ڴ�ռ�    **/
	amqp_maybe_release_buffers(pConn);

	/*�ر�ͨ�Źܵ�    **/
	amqp_rpc_reply_t closeChannelRet = amqp_channel_close(pConn, channelId, AMQP_REPLY_SUCCESS);

	/*�ر�����    **/
	amqp_rpc_reply_t closeConnectRet = amqp_connection_close(pConn, AMQP_REPLY_SUCCESS);

	/*��������    **/
	int destoryRet = amqp_destroy_connection(pConn);
	if (AMQP_STATUS_OK != destoryRet)
	{
		GLOBAL_PUBLISH_THREAD_RESULT = -1;
		return GLOBAL_PUBLISH_THREAD_RESULT;
	}

	/*�����������н���������1    **/
	GLOBAL_PUBLISH_THREAD_RESULT = 1;
	return GLOBAL_PUBLISH_THREAD_RESULT;
}

int simpleMode_ConsumeThreadFunc()
{
	/*����һ����RabbitMQͨ�ŵ�����    **/
	amqp_connection_state_t pConn = NULL;
	pConn = amqp_new_connection();
	if (NULL == pConn)
	{
		GLOBAL_CONSUME_THREAD_RESULT = -1;
		return GLOBAL_CONSUME_THREAD_RESULT;
	}

	/*����һ����RabbitMQͨ�ŵ�socket    **/
	amqp_socket_t* pSocket = nullptr;
	pSocket = amqp_tcp_socket_new(pConn);
	if (NULL == pSocket)
	{
		GLOBAL_CONSUME_THREAD_RESULT = -1;
		return GLOBAL_CONSUME_THREAD_RESULT;
	}

	/*����RabbitMQͨ�ŵ�����    **/
	string hostName = "192.168.0.188";
	int port = 5672;

	int openRet = amqp_socket_open(pSocket, hostName.c_str(), port);
	if (AMQP_STATUS_OK != openRet)
	{
		GLOBAL_CONSUME_THREAD_RESULT = -1;
		return GLOBAL_CONSUME_THREAD_RESULT;
	}

	//��¼RabbitMQ
	amqp_rpc_reply_t loginRet = amqp_login(pConn, "qhVHost", AMQP_DEFAULT_MAX_CHANNELS, AMQP_DEFAULT_FRAME_SIZE, 0, AMQP_SASL_METHOD_PLAIN, "quhan", "qhmm19971120");
	if (AMQP_RESPONSE_NORMAL != loginRet.reply_type)
	{
		GLOBAL_CONSUME_THREAD_RESULT = -1;
		return GLOBAL_CONSUME_THREAD_RESULT;
	}

	/*����RabbitMQͨ�ŵĹܵ�    **/
	amqp_channel_t channelId = 1;
	amqp_channel_open_ok_t* openChannelRet = amqp_channel_open(pConn, channelId);

	/*������Ϣ    **/
	int msgCount = 0;

	amqp_basic_consume_ok_t *msg = amqp_basic_consume(pConn, channelId, amqp_cstring_bytes("test_simple_queue"), amqp_empty_bytes, 0, 1, 0, amqp_empty_table);
	
	while (1)
	{
		/*ָ���ȴ�ʱ��    **/
		amqp_envelope_t* pEnvelope = new amqp_envelope_t();
		timeval timeout = timeval{ 2, 0 };

		amqp_consume_message(pConn, pEnvelope, &timeout, 0);
		++msgCount;

		if (0 == pEnvelope->message.body.bytes)
			continue;

		printf("Consumer Receive Message : %s\n\n", (char *)pEnvelope->message.body.bytes);

		amqp_destroy_envelope(pEnvelope);

		if (msgCount >= 3)
			break;
	}

	/*�ͷ��ڴ�ռ�    **/
	amqp_maybe_release_buffers(pConn);

	/*�ر�ͨ�Źܵ�    **/
	amqp_rpc_reply_t closeChannelRet = amqp_channel_close(pConn, channelId, AMQP_REPLY_SUCCESS);

	/*�ر�����    **/
	amqp_rpc_reply_t closeConnectRet = amqp_connection_close(pConn, AMQP_REPLY_SUCCESS);

	/*��������    **/
	int destoryRet = amqp_destroy_connection(pConn);
	if (AMQP_STATUS_OK != destoryRet)
	{
		GLOBAL_CONSUME_THREAD_RESULT = -1;
		return GLOBAL_CONSUME_THREAD_RESULT;
	}

	/*�����������н���������1    **/
	GLOBAL_CONSUME_THREAD_RESULT = 1;
	return GLOBAL_CONSUME_THREAD_RESULT;
}

