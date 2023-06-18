#include "FuncTest.h"

/*Request_Codecģ�����						**/
void funcModelRequestCodecTest()
{
	/*������Ϣ��ʼ��						**/
	RequestMsg_dt srcMsg;
	srcMsg.cmdType  = 1;
	srcMsg.clientId = "Client No.1";
	
	srcMsg.serverId = "Server No.1";
	srcMsg.sign     = "Source Message";
	srcMsg.data		= "Register Server";

	Request_Codec reqEncodeModel;
	reqEncodeModel.initMessage(srcMsg);

	cout << "REQUEST SOURCE MSG:" << " " << srcMsg.cmdType << " " << srcMsg.clientId << " " << srcMsg.serverId << " " << srcMsg.sign << " " << srcMsg.data << endl << endl;

	/*������Ϣ����							**/
	string encodeMsg = reqEncodeModel.encodeMsg();

	/*������Ϣ����							**/
	Request_Codec reqDecodeModel;
	reqDecodeModel.initMessage(encodeMsg);
	RequestMsg_dt* pDstMsg = static_cast<RequestMsg_dt *>(reqDecodeModel.decodeMsg());
	
	cout << "REQUEST DEST MSG:" << " " << pDstMsg->cmdType << " " << pDstMsg->clientId << " " << pDstMsg->serverId << " " << pDstMsg->sign << " " << pDstMsg->data << endl << endl;
	delete pDstMsg;
}

/*Response_Codecģ�����					**/
void funcModelResponseCodecTest()
{
	/*��Ӧ��Ϣ��ʼ��						**/
	ResponseMsg_dt srcMsg;
	srcMsg.clientId = "Client No.1";
	srcMsg.serverId = "Server No.1";
	srcMsg.seckeyId = 1;
	srcMsg.data     = "Register Server";
	srcMsg.status   = true;

	Response_Codec respEncodeModel;
	respEncodeModel.initMessage(srcMsg);

	cout << "RESPONSE SOURCE MSG:" << " " << srcMsg.status << " " << srcMsg.clientId << " " << srcMsg.serverId << " " << srcMsg.seckeyId << " " << srcMsg.data << endl << endl;

	/*��Ӧ��Ϣ����							**/
	string encodeMsg = respEncodeModel.encodeMsg();

	/*��Ӧ��Ϣ����							**/
	Response_Codec respDecodeModel;
	respDecodeModel.initMessage(encodeMsg);
	ResponseMsg_dt* pDstMsg = static_cast<ResponseMsg_dt *>(respDecodeModel.decodeMsg());

	cout << "RESPONSE DEST MSG:" << " " << pDstMsg->status << " " << pDstMsg->clientId << " " << pDstMsg->serverId << " " << pDstMsg->seckeyId << " " << pDstMsg->data << endl << endl;
	delete pDstMsg;
}

/*Socketģ�����							**/
void funcThreadSocketTest()
{
	thread servThread(funcModelTcpServerTest);
	thread clientThread(funcModelTcpClientTest);

	servThread.join();
	clientThread.join();
}

void funcModelTcpServerTest()
{
	TcpServer serv;
	if (0 != serv.setListen("127.0.0.1", 8001))
		return;

	/*�ȴ��ͻ�������, ֻ�ȴ�2��				**/
	TcpSocket* pCommSock = serv.acceptConn(5);
	if (NULL == pCommSock)
		return;
	
	char sendBuf[32] = "Server Has Been Processed Msg.";
	char recvBuf[64] = "\0";
	while (true)
	{
		int recvSize = pCommSock->recvMessage(recvBuf, sizeof(recvBuf), 3);
		if (recvSize > 0)
		{
			/*�յ��ͻ�����Ϣ				**/
			printf("SERV RECV MSG: %s\n", recvBuf);

			if (0 != strncmp("exit", recvBuf, 4))
			{
				printf("SERV SEND MSG: Server Has Been Processed Msg.\n");
				pCommSock->sendMessage(sendBuf, strlen(sendBuf), 2);
			}
		}
		else
		{
			printf("CLIENT DISCONNECT SERVER.\n");
			break;
		}
		memset(recvBuf, 0, sizeof(recvBuf));
	}
	delete pCommSock;

	printf("SERV EXIT.\n");
	return;
}

void funcModelTcpClientTest()
{
	TcpSocket clientSock;
	if (-1 != clientSock.connectServer("127.0.0.1", 8001, 3))
		printf("CLIENT CONNECT SERVER SUCCESS.\n");
	else
	{
		printf("CLIENT CONNECT SERVER FAILED.\n");
		return;
	}

	char sendBuf[32] = "Client Register Server.";
	printf("CLIENT SEND MSG: Client Register Server.\n");
	clientSock.sendMessage(sendBuf, strlen(sendBuf), 2);

	char recvBuf[64] = "\0";
	clientSock.recvMessage(recvBuf, sizeof(recvBuf), 3);
	printf("CLIENT RECV MSG: %s\n", recvBuf);

	printf("CLIENT EXIT.\n");
	char exitBuf[6] = "exit";
	clientSock.sendMessage(exitBuf, strlen(exitBuf), 2);

	return;
}