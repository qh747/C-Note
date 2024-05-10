#include "libRabbitMQTest.h"

/*�������̷߳���ֵ    **/
int WORK_QUEUE_MODE_PUBLISH_THREAD_RESULT = 0;

/*�������̷߳���ֵ    **/
int WORK_QUEUE_MODE_CONSUME_THREAD_RESULT = 0;

/*�������̷߳���ֵ��    **/
mutex WORK_QUEUE_MODE_CONSUME_THREAD_RESULT_lock;

void workQueueModeFunc()
{
	printf("************** RABBITMQ WORK QUEUE MODE FUNC START *************\n\n");

	/*�����������߳�    **/
	thread publishThread(workQueueMode_PublishThreadFunc);

	/*������Ϣȫ���洢���������ڽ�������    **/
	Sleep(5 * 1000);

	/*������һ���������߳�    **/
	thread firstConsumeThread(workQueueMode_ConsumeThreadFunc);

	/*�����ڶ����������߳�, ͨ�����������߳���ɹ�ƽ�ַ��Ĺ���    **/
	thread secondConsumeThread(workQueueMode_ConsumeThreadFunc);

	publishThread.join();
	firstConsumeThread.join();
	secondConsumeThread.join();

	printf("************** RABBITMQ WORK QUEUE MODE FUNC END *************\n\n");

	printf("Publish Thread Result: %d\n", WORK_QUEUE_MODE_PUBLISH_THREAD_RESULT);

	WORK_QUEUE_MODE_CONSUME_THREAD_RESULT_lock.lock();
	printf("Consume Thread Result: %d\n", WORK_QUEUE_MODE_CONSUME_THREAD_RESULT);
	WORK_QUEUE_MODE_CONSUME_THREAD_RESULT_lock.unlock();
}

int workQueueMode_PublishThreadFunc()
{
	/*������RabbitMQ Server������    **/
	amqp_connection_state_t pConn = amqp_new_connection();
	if (NULL == pConn)
	{
		WORK_QUEUE_MODE_PUBLISH_THREAD_RESULT = -1;
		return WORK_QUEUE_MODE_PUBLISH_THREAD_RESULT;
	}

	/*������RabbitMQ Serverͨ�ŵ�socket    **/
	amqp_socket_t* pSocket = amqp_tcp_socket_new(pConn);
	if(NULL == pSocket)
	{
		WORK_QUEUE_MODE_PUBLISH_THREAD_RESULT = -1;
		return WORK_QUEUE_MODE_PUBLISH_THREAD_RESULT;
	}

	/*����RabbitMQ Serverͨ�ŵ�socket    **/
	string hostName = RabbitmqServer::sServerIpAddr;
	int port = RabbitmqServer::iServerPort;
	int openSocketRet = amqp_socket_open(pSocket, hostName.c_str(), port);
	if (AMQP_STATUS_OK != openSocketRet)
	{
		WORK_QUEUE_MODE_PUBLISH_THREAD_RESULT = -1;
		return WORK_QUEUE_MODE_PUBLISH_THREAD_RESULT;
	}

	/*��¼RabbitMQ Server    **/
	amqp_rpc_reply_t loginRet = amqp_login(pConn, "qhVHost", AMQP_DEFAULT_MAX_CHANNELS, AMQP_DEFAULT_FRAME_SIZE, 0, AMQP_SASL_METHOD_PLAIN, "quhan", "qhmm19971120");
	if (AMQP_RESPONSE_NORMAL != loginRet.reply_type)
	{
		WORK_QUEUE_MODE_PUBLISH_THREAD_RESULT = -1;
		return WORK_QUEUE_MODE_PUBLISH_THREAD_RESULT;
	}

	/*��ͨ�Źܵ�    **/
	int channelId = 1;
	amqp_channel_open_ok_t* openChannelRet = amqp_channel_open(pConn, channelId);

	/*������Ϣ   **/
	stringstream strBuf;

	for (int i = 0; i < 10; ++i)
	{
		strBuf << "DATA: " << i;
		char messageBuf[16] = "\0";
		strcpy(messageBuf, strBuf.str().c_str());

		amqp_bytes_t messageBody;
		messageBody.bytes = messageBuf;
		messageBody.len = sizeof(messageBuf);

		int publishRet = amqp_basic_publish(pConn, channelId, amqp_cstring_bytes(""), amqp_cstring_bytes("test_workmode_queue"), 0, 0, NULL, messageBody);

		printf("Thread: %d Send: %s\n", this_thread::get_id(), messageBuf);
		strBuf.str("");
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

	WORK_QUEUE_MODE_PUBLISH_THREAD_RESULT = 1;
	return WORK_QUEUE_MODE_PUBLISH_THREAD_RESULT;
}

int workQueueMode_ConsumeThreadFunc()
{
	/*������RabbitMQ Server������    **/
	amqp_connection_state_t pConn = amqp_new_connection();
	if (NULL == pConn)
	{
		WORK_QUEUE_MODE_CONSUME_THREAD_RESULT_lock.lock();
		WORK_QUEUE_MODE_PUBLISH_THREAD_RESULT = -1;
		WORK_QUEUE_MODE_CONSUME_THREAD_RESULT_lock.unlock();

		return WORK_QUEUE_MODE_PUBLISH_THREAD_RESULT;
	}

	/*������RabbitMQ Serverͨ�ŵ�socket    **/
	amqp_socket_t* pSocket = amqp_tcp_socket_new(pConn);
	if (NULL == pSocket)
	{
		WORK_QUEUE_MODE_CONSUME_THREAD_RESULT_lock.lock();
		WORK_QUEUE_MODE_PUBLISH_THREAD_RESULT = -1;
		WORK_QUEUE_MODE_CONSUME_THREAD_RESULT_lock.unlock();

		return WORK_QUEUE_MODE_PUBLISH_THREAD_RESULT;
	}

	/*����RabbitMQ Serverͨ�ŵ�socket    **/
	string hostName = RabbitmqServer::sServerIpAddr;
	int port = RabbitmqServer::iServerPort;
	int openSocketRet = amqp_socket_open(pSocket, hostName.c_str(), port);
	if (AMQP_STATUS_OK != openSocketRet)
	{
		WORK_QUEUE_MODE_CONSUME_THREAD_RESULT_lock.lock();
		WORK_QUEUE_MODE_PUBLISH_THREAD_RESULT = -1;
		WORK_QUEUE_MODE_CONSUME_THREAD_RESULT_lock.unlock();

		return WORK_QUEUE_MODE_PUBLISH_THREAD_RESULT;
	}

	/*��¼RabbitMQ Server    **/
	amqp_rpc_reply_t loginRet = amqp_login(pConn, "qhVHost", AMQP_DEFAULT_MAX_CHANNELS, AMQP_DEFAULT_FRAME_SIZE, 0, AMQP_SASL_METHOD_PLAIN, "quhan", "qhmm19971120");
	if (AMQP_RESPONSE_NORMAL != loginRet.reply_type)
	{
		WORK_QUEUE_MODE_CONSUME_THREAD_RESULT_lock.lock();
		WORK_QUEUE_MODE_PUBLISH_THREAD_RESULT = -1;
		WORK_QUEUE_MODE_CONSUME_THREAD_RESULT_lock.unlock();

		return WORK_QUEUE_MODE_PUBLISH_THREAD_RESULT;
	}

	/*��ͨ�Źܵ�    **/
	int channelId = 1;
	amqp_channel_open_ok_t* openChannelRet = amqp_channel_open(pConn, channelId);

	/*������Ϣ    **/
	while (true)
	{
		amqp_rpc_reply_t getRet = amqp_basic_get(pConn, channelId, amqp_cstring_bytes("test_workmode_queue"), AMQP_RESPONSE_NORMAL);
		if (AMQP_RESPONSE_NORMAL != getRet.reply_type)
			continue;

		amqp_message_t* msg = new amqp_message_t();
		amqp_rpc_reply_t rcvRet = amqp_read_message(pConn, channelId, msg, 0);
		if (AMQP_RESPONSE_NORMAL != rcvRet.reply_type)
		{
			delete msg;
			break;
		}
		else
		{
			printf("Thread: %d Receive: %s\n", this_thread::get_id(), (char *)msg->body.bytes);
			amqp_destroy_message(msg);

			delete msg;
			msg = NULL;

			Sleep(1000);
		}
	}

	/*�ر�ͨ�Źܵ�    **/
	amqp_channel_close(pConn, channelId, AMQP_REPLY_SUCCESS);

	/*������RabbitMȥServerͨ�ŵ�socket    **/
	amqp_connection_close(pConn, AMQP_REPLY_SUCCESS);

	/*�ͷ���RabbitMQ Server����ռ�õ��ڴ�ռ�    **/
	amqp_maybe_release_buffers(pConn);

	/*������RabbitMQ Server������    **/
	amqp_destroy_connection(pConn);

	WORK_QUEUE_MODE_CONSUME_THREAD_RESULT_lock.lock();
	WORK_QUEUE_MODE_PUBLISH_THREAD_RESULT = 1;
	WORK_QUEUE_MODE_CONSUME_THREAD_RESULT_lock.unlock();

	return WORK_QUEUE_MODE_CONSUME_THREAD_RESULT;
}