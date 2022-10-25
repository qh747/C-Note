#include "libRabbitMQTest.h"

/*�������̷߳���ֵ    **/
int TOPIC_MODE_PUBLISH_THREAD_RESULT = 0;

/*��һ���������̷߳���ֵ    **/
int TOPIC_MODE_FIRST_CONSUME_THREAD_RESULT = 0;

/*�ڶ����������̷߳���ֵ    **/
int TOPIC_MODE_SECOND_CONSUME_THREAD_RESULT = 0;

void topicModeFunc()
{
	printf("************** RABBITMQ TOPIC MODE FUNC START *************\n\n");

	/*�����������߳�    **/
	thread publishThread(topicMode_PublishThreadFunc);

	/*����������Ϣ�������߳�    **/
	thread firstConsumeThread(topicMode_FirstConsumeThreadFunc);

	/*����������Ϣ�������߳�    **/
	thread secondConsumeThread(topicMode_SecondConsumeThreadFunc);

	publishThread.join();
	firstConsumeThread.join();
	secondConsumeThread.join();

	printf("************** RABBITMQ TOPIC MODE FUNC END *************\n\n");

	printf("Publish Thread Result: %d\n", TOPIC_MODE_PUBLISH_THREAD_RESULT);
	printf("First Consume Thread Result: %d\n", TOPIC_MODE_FIRST_CONSUME_THREAD_RESULT);
	printf("Second Consume Thread Result: %d\n", TOPIC_MODE_SECOND_CONSUME_THREAD_RESULT);
}

int topicMode_PublishThreadFunc()
{
	/*������RabbitMQ Server������    **/
	amqp_connection_state_t pConn = amqp_new_connection();
	if (NULL == pConn)
	{
		TOPIC_MODE_PUBLISH_THREAD_RESULT = -1;
		return TOPIC_MODE_PUBLISH_THREAD_RESULT;
	}

	/*������RabbitMQ Serverͨ�ŵ�socket    **/
	amqp_socket_t* pSocket = amqp_tcp_socket_new(pConn);
	if (NULL == pSocket)
	{
		TOPIC_MODE_PUBLISH_THREAD_RESULT = -1;
		return TOPIC_MODE_PUBLISH_THREAD_RESULT;
	}

	/*����RabbitMQ Serverͨ�ŵ�socket    **/
	int openSocketRet = amqp_socket_open(pSocket, "192.168.0.188", 5672);
	if (AMQP_STATUS_OK != openSocketRet)
	{
		TOPIC_MODE_PUBLISH_THREAD_RESULT = -1;
		return TOPIC_MODE_PUBLISH_THREAD_RESULT;
	}

	/*��¼RabbitMQ Server    **/
	amqp_rpc_reply_t loginRet = amqp_login(pConn, "qhVHost", AMQP_DEFAULT_MAX_CHANNELS, AMQP_DEFAULT_FRAME_SIZE, 0, AMQP_SASL_METHOD_PLAIN, "quhan", "qhmm19971120");
	if (AMQP_RESPONSE_NORMAL != loginRet.reply_type)
	{
		TOPIC_MODE_PUBLISH_THREAD_RESULT = -1;
		return TOPIC_MODE_PUBLISH_THREAD_RESULT;
	}

	/*��ͨ�Źܵ�    **/
	int channelId = 1;
	amqp_channel_open_ok_t* openChannelRet = amqp_channel_open(pConn, channelId);

	/*����������    **/
	string exchangeName = "test_topicMode_exchange";
	string exchangeType = "topic";
	amqp_exchange_declare_ok_t* pDeclareRet = amqp_exchange_declare(pConn, channelId, amqp_cstring_bytes(exchangeName.c_str()), amqp_cstring_bytes(exchangeType.c_str()), false, true, false, false, amqp_empty_table);

	/*������Ϣ   **/
	amqp_bytes_t messageBody;
	char messageBuf[32] = "\0";

	/*����һ�����з�����Ϣ    **/
	strcpy(messageBuf, "first queue receive 1.");
	messageBody.bytes = messageBuf;
	messageBody.len = sizeof(messageBuf);
	int publishRet = amqp_basic_publish(pConn, channelId, amqp_cstring_bytes(exchangeName.c_str()), amqp_cstring_bytes("to.first.queue"), 0, 0, NULL, messageBody);
	printf("Pubilsh Send: %s\n", messageBuf);

	Sleep(1000);
	memset(&messageBody, 0, sizeof(amqp_bytes_t));
	memset(messageBuf, 0, 32);

	strcpy(messageBuf, "first queue receive 2.");
	messageBody.bytes = messageBuf;
	messageBody.len = sizeof(messageBuf);
	publishRet = amqp_basic_publish(pConn, channelId, amqp_cstring_bytes(exchangeName.c_str()), amqp_cstring_bytes("send.first.thread"), 0, 0, NULL, messageBody);
	printf("Pubilsh Send: %s\n", messageBuf);

	Sleep(1000);
	memset(&messageBody, 0, sizeof(amqp_bytes_t));
	memset(messageBuf, 0, 32);

	strcpy(messageBuf, "quit");
	messageBody.bytes = messageBuf;
	messageBody.len = sizeof(messageBuf);
	publishRet = amqp_basic_publish(pConn, channelId, amqp_cstring_bytes(exchangeName.c_str()), amqp_cstring_bytes("let.first.quit"), 0, 0, NULL, messageBody);
	printf("Pubilsh Make First Queue Exit\n");

	Sleep(1000);
	memset(&messageBody, 0, sizeof(amqp_bytes_t));
	memset(messageBuf, 0, 32);

	/*���ڶ������з�����Ϣ**/
	strcpy(messageBuf, "second queue receive 1.");
	messageBody.bytes = messageBuf;
	messageBody.len = sizeof(messageBuf);
	publishRet = amqp_basic_publish(pConn, channelId, amqp_cstring_bytes(exchangeName.c_str()), amqp_cstring_bytes("2.to.queue"), 0, 0, NULL, messageBody);
	printf("Pubilsh Send: %s\n", messageBuf);

	Sleep(1000);
	memset(&messageBody, 0, sizeof(amqp_bytes_t));
	memset(messageBuf, 0, 32);

	strcpy(messageBuf, "second queue receive 2.");
	messageBody.bytes = messageBuf;
	messageBody.len = sizeof(messageBuf);
	publishRet = amqp_basic_publish(pConn, channelId, amqp_cstring_bytes(exchangeName.c_str()), amqp_cstring_bytes("send.message.to.queue"), 0, 0, NULL, messageBody);
	printf("Pubilsh Send: %s\n", messageBuf);

	Sleep(1000);
	memset(&messageBody, 0, sizeof(amqp_bytes_t));
	memset(messageBuf, 0, 32);

	strcpy(messageBuf, "quit");
	messageBody.bytes = messageBuf;
	messageBody.len = sizeof(messageBuf);
	publishRet = amqp_basic_publish(pConn, channelId, amqp_cstring_bytes(exchangeName.c_str()), amqp_cstring_bytes("quit.the.second.queue"), 0, 0, NULL, messageBody);
	printf("Pubilsh Make Second Queue Exit\n");

	Sleep(1000);
	memset(&messageBody, 0, sizeof(amqp_bytes_t));
	memset(messageBuf, 0, 32);

	/*�ر�ͨ�Źܵ�    **/
	amqp_channel_close(pConn, channelId, AMQP_REPLY_SUCCESS);

	/*������RabbitMȥServerͨ�ŵ�socket    **/
	amqp_connection_close(pConn, AMQP_REPLY_SUCCESS);

	/*�ͷ���RabbitMQ Server����ռ�õ��ڴ�ռ�    **/
	amqp_maybe_release_buffers(pConn);

	/*������RabbitMQ Server������    **/
	amqp_destroy_connection(pConn);

	TOPIC_MODE_PUBLISH_THREAD_RESULT = 1;
	return TOPIC_MODE_PUBLISH_THREAD_RESULT;
}

int topicMode_FirstConsumeThreadFunc()
{
	/*������RabbitMQ Server������    **/
	amqp_connection_state_t pConn = amqp_new_connection();
	if (NULL == pConn)
	{
		TOPIC_MODE_FIRST_CONSUME_THREAD_RESULT = -1;
		return TOPIC_MODE_FIRST_CONSUME_THREAD_RESULT;
	}

	/*������RabbitMQ Serverͨ�ŵ�socket    **/
	amqp_socket_t* pSocket = amqp_tcp_socket_new(pConn);
	if (NULL == pSocket)
	{
		TOPIC_MODE_FIRST_CONSUME_THREAD_RESULT = -1;
		return TOPIC_MODE_FIRST_CONSUME_THREAD_RESULT;
	}

	/*����RabbitMQ Serverͨ�ŵ�socket    **/
	int openSocketRet = amqp_socket_open(pSocket, "192.168.0.188", 5672);
	if (AMQP_STATUS_OK != openSocketRet)
	{
		TOPIC_MODE_FIRST_CONSUME_THREAD_RESULT = -1;
		return TOPIC_MODE_FIRST_CONSUME_THREAD_RESULT;
	}

	/*��¼RabbitMQ Server    **/
	amqp_rpc_reply_t loginRet = amqp_login(pConn, "qhVHost", AMQP_DEFAULT_MAX_CHANNELS, AMQP_DEFAULT_FRAME_SIZE, 0, AMQP_SASL_METHOD_PLAIN, "quhan", "qhmm19971120");
	if (AMQP_RESPONSE_NORMAL != loginRet.reply_type)
	{
		TOPIC_MODE_FIRST_CONSUME_THREAD_RESULT = -1;
		return TOPIC_MODE_FIRST_CONSUME_THREAD_RESULT;
	}

	/*��ͨ�Źܵ�    **/
	int channelId = 1;
	amqp_channel_open_ok_t* openChannelRet = amqp_channel_open(pConn, channelId);

	/*��������    **/
	amqp_queue_declare_ok_t* pDeclareRet = amqp_queue_declare(pConn, channelId, amqp_cstring_bytes("test_topicMode_first_queue"), false, true, false, false, amqp_empty_table);

	/*�󶨵�ǰ���е���������    **/
	amqp_queue_bind(pConn, channelId, amqp_cstring_bytes("test_topicMode_first_queue"), amqp_cstring_bytes("test_topicMode_exchange"), amqp_cstring_bytes("*.first.*"), amqp_empty_table);

	/*������Ϣ���ѷ�ʽΪ������������    **/
	amqp_basic_consume(pConn, channelId, amqp_cstring_bytes("test_topicMode_first_queue"), amqp_empty_bytes, false, true, false, amqp_empty_table);

	/*������Ϣ    **/
	while (true)
	{
		amqp_envelope_t envelope;
		amqp_rpc_reply_t ret = amqp_consume_message(pConn, &envelope, NULL, 0);
		if (0 == strcmp("quit", (char *)envelope.message.body.bytes))
			break;
		else
			printf("First Consume Receive: %s\n", (char *)envelope.message.body.bytes);

		amqp_destroy_envelope(&envelope);
		Sleep(1000);
	}

	/*�ر�ͨ�Źܵ�    **/
	amqp_channel_close(pConn, channelId, AMQP_REPLY_SUCCESS);

	/*������RabbitMȥServerͨ�ŵ�socket    **/
	amqp_connection_close(pConn, AMQP_REPLY_SUCCESS);

	/*�ͷ���RabbitMQ Server����ռ�õ��ڴ�ռ�    **/
	amqp_maybe_release_buffers(pConn);

	/*������RabbitMQ Server������    **/
	amqp_destroy_connection(pConn);

	TOPIC_MODE_FIRST_CONSUME_THREAD_RESULT = 1;
	return TOPIC_MODE_FIRST_CONSUME_THREAD_RESULT;
}

int topicMode_SecondConsumeThreadFunc()
{
	/*������RabbitMQ Server������    **/
	amqp_connection_state_t pConn = amqp_new_connection();
	if (NULL == pConn)
	{
		TOPIC_MODE_SECOND_CONSUME_THREAD_RESULT = -1;
		return TOPIC_MODE_SECOND_CONSUME_THREAD_RESULT;
	}

	/*������RabbitMQ Serverͨ�ŵ�socket    **/
	amqp_socket_t* pSocket = amqp_tcp_socket_new(pConn);
	if (NULL == pSocket)
	{
		TOPIC_MODE_SECOND_CONSUME_THREAD_RESULT = -1;
		return TOPIC_MODE_SECOND_CONSUME_THREAD_RESULT;
	}

	/*����RabbitMQ Serverͨ�ŵ�socket    **/
	int openSocketRet = amqp_socket_open(pSocket, "192.168.0.188", 5672);
	if (AMQP_STATUS_OK != openSocketRet)
	{
		TOPIC_MODE_SECOND_CONSUME_THREAD_RESULT = -1;
		return TOPIC_MODE_SECOND_CONSUME_THREAD_RESULT;
	}

	/*��¼RabbitMQ Server    **/
	amqp_rpc_reply_t loginRet = amqp_login(pConn, "qhVHost", AMQP_DEFAULT_MAX_CHANNELS, AMQP_DEFAULT_FRAME_SIZE, 0, AMQP_SASL_METHOD_PLAIN, "quhan", "qhmm19971120");
	if (AMQP_RESPONSE_NORMAL != loginRet.reply_type)
	{
		TOPIC_MODE_SECOND_CONSUME_THREAD_RESULT = -1;
		return TOPIC_MODE_SECOND_CONSUME_THREAD_RESULT;
	}

	/*��ͨ�Źܵ�    **/
	int channelId = 1;
	amqp_channel_open_ok_t* openChannelRet = amqp_channel_open(pConn, channelId);

	/*��������    **/
	amqp_queue_declare_ok_t* pDeclareRet = amqp_queue_declare(pConn, channelId, amqp_cstring_bytes("test_topicMode_second_queue"), false, true, false, false, amqp_empty_table);

	/*�󶨵�ǰ���е���������    **/
	amqp_queue_bind(pConn, channelId, amqp_cstring_bytes("test_topicMode_second_queue"), amqp_cstring_bytes("test_topicMode_exchange"), amqp_cstring_bytes("2.#"), amqp_empty_table);
	amqp_queue_bind(pConn, channelId, amqp_cstring_bytes("test_topicMode_second_queue"), amqp_cstring_bytes("test_topicMode_exchange"), amqp_cstring_bytes("*.*.*.queue"), amqp_empty_table);

	/*������Ϣ���ѷ�ʽΪ������������    **/
	amqp_basic_consume(pConn, channelId, amqp_cstring_bytes("test_topicMode_second_queue"), amqp_empty_bytes, false, true, false, amqp_empty_table);

	/*������Ϣ    **/
	while (true)
	{
		amqp_envelope_t envelope;
		amqp_rpc_reply_t ret = amqp_consume_message(pConn, &envelope, NULL, 0);
		if (0 == strcmp("quit", (char *)envelope.message.body.bytes))
			break;
		else
			printf("Second Consume Receive: %s\n", (char *)envelope.message.body.bytes);

		amqp_destroy_envelope(&envelope);
		Sleep(1000);
	}

	/*�ر�ͨ�Źܵ�    **/
	amqp_channel_close(pConn, channelId, AMQP_REPLY_SUCCESS);

	/*������RabbitMȥServerͨ�ŵ�socket    **/
	amqp_connection_close(pConn, AMQP_REPLY_SUCCESS);

	/*�ͷ���RabbitMQ Server����ռ�õ��ڴ�ռ�    **/
	amqp_maybe_release_buffers(pConn);

	/*������RabbitMQ Server������    **/
	amqp_destroy_connection(pConn);

	TOPIC_MODE_SECOND_CONSUME_THREAD_RESULT = 1;
	return TOPIC_MODE_SECOND_CONSUME_THREAD_RESULT;
}