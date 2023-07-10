#include "FuncTest.h"

/*�����ģ�����							**/
void funcThreadCodecTest()
{
	thread reqCodecThread(funcModelRequestCodecTest);
	thread respCodecThread(funcModelResponseCodecTest);

	reqCodecThread.join();
	respCodecThread.join();
}

void funcModelRequestCodecTest()
{
	/*������Ϣ��ʼ��						**/
	RequestMsg_dt srcMsg;
	srcMsg.iCmdType  = 1;
	srcMsg.sClientId = "Client No.1";
	srcMsg.sServerId = "Server No.1";
	srcMsg.sSign     = "Source Message";
	srcMsg.sData	 = "Register Server";

	Request_Codec reqEncodeModel;
	reqEncodeModel.initMessage(srcMsg);

	cout << "REQUEST SOURCE MSG:" << " " << srcMsg.iCmdType << " " << srcMsg.sClientId << " " << srcMsg.sServerId << " " << srcMsg.sSign << " " << srcMsg.sData << endl << endl;

	/*������Ϣ����							**/
	string encodeMsg = reqEncodeModel.encodeMsg();

	/*������Ϣ����							**/
	Request_Codec reqDecodeModel;
	reqDecodeModel.initMessage(encodeMsg);
	RequestMsg_dt* pDstMsg = static_cast<RequestMsg_dt *>(reqDecodeModel.decodeMsg());
	
	cout << "REQUEST DEST MSG:" << " " << pDstMsg->iCmdType << " " << pDstMsg->sClientId << " " << pDstMsg->sServerId << " " << pDstMsg->sSign << " " << pDstMsg->sData << endl << endl;
	delete pDstMsg;
}

void funcModelResponseCodecTest()
{
	/*��Ӧ��Ϣ��ʼ��						**/
	ResponseMsg_dt srcMsg;
	srcMsg.sClientId = "Client No.1";
	srcMsg.sServerId = "Server No.1";
	srcMsg.iSeckeyId = 1;
	srcMsg.sData     = "Register Server";
	srcMsg.bStatus   = true;

	Response_Codec respEncodeModel;
	respEncodeModel.initMessage(srcMsg);

	cout << "RESPONSE SOURCE MSG:" << " " << srcMsg.bStatus << " " << srcMsg.sClientId << " " << srcMsg.sServerId << " " << srcMsg.iSeckeyId << " " << srcMsg.sData << endl << endl;

	/*��Ӧ��Ϣ����							**/
	string encodeMsg = respEncodeModel.encodeMsg();

	/*��Ӧ��Ϣ����							**/
	Response_Codec respDecodeModel;
	respDecodeModel.initMessage(encodeMsg);
	ResponseMsg_dt* pDstMsg = static_cast<ResponseMsg_dt *>(respDecodeModel.decodeMsg());

	cout << "RESPONSE DEST MSG:" << " " << pDstMsg->bStatus << " " << pDstMsg->sClientId << " " << pDstMsg->sServerId << " " << pDstMsg->iSeckeyId << " " << pDstMsg->sData << endl << endl;
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

/*�����ڴ�ģ�����							**/
void funcMemoryShareTest()
{
	thread writeThread(funcModelMemoryShareWriteTest);
	thread readThread(funcModelMemoryShareReadTest);
	thread secReadThread(funcModelMemoryShareReadTest);

	writeThread.join();
	readThread.join();
	secReadThread.join();
}

void funcModelMemoryShareWriteTest()
{
	MemoryShare writeMemory;
	bool allocateResult = writeMemory.allocateMemory(1, "SHARE_MEMORY", 1024, 1);
	if (false == allocateResult)
		return;

	char sendBuf[20] = "hello world.";
	while (true)
	{
		DWORD writeSize = writeMemory.writeData(1, sendBuf, strlen(sendBuf), 0, 1);
		if (0 != writeSize)
		{
			printf("Write Thread Write Data Success. Data: %s. Size: %lu\n", sendBuf, writeSize);
			break;
		}
	}
	
	Sleep(0.5 * 1000);
	while (true)
	{
		bool clearResult = writeMemory.clearMemory(1, 0, strlen(sendBuf), 1);
		if (true == clearResult)
		{
			memset(sendBuf, 0, sizeof(sendBuf));
			strcpy(sendBuf, "hello share memory");
			break;
		}
	}

	while (true)
	{
		DWORD writeSize = writeMemory.writeData(1, sendBuf, strlen(sendBuf), 0, 1);
		if (0 != writeSize)
		{
			printf("Write Thread Write Data Success. Data: %s. Size: %lu\n", sendBuf, writeSize);
			break;
		}
	}
}

void funcModelMemoryShareReadTest()
{
	MemoryShare readMemory;

	char recvBuf[20] = "\0";
	int readCount = 0;
	while (true)
	{
		DWORD readSize = readMemory.readData(1, recvBuf, sizeof(recvBuf), 0, 1);
		if (0 != readSize)
		{
			recvBuf[strlen(recvBuf)] = '\0';
			printf("Read Thread Read Data Success. Data: %s Size: %d\n", recvBuf, strlen(recvBuf));
			++readCount;
		}

		Sleep(1 * 1000);

		if (readCount >= 2)
			break;
	}
}

void funModelClientMemoryShareTest()
{
	KeyInfo_dt keyInfo;
	keyInfo.iKeyId = 1;
	keyInfo.iKetStatus = KEY_IN_USE_STATE;
	strcpy(keyInfo.sClientId, "CLIENT_KEY_1");
	strcpy(keyInfo.sServerId, "SERVER_KEY_1");
	strcpy(keyInfo.sKeyInfo, "CLIENT_SERVER_KEY");

	ClientMemShare cltMemShare(1);
	cltMemShare.writeKeyInfo(&keyInfo);
	cout << "WIRTE: " << keyInfo.iKeyId << " " << keyInfo.iKetStatus << " " << keyInfo.sClientId << " " << keyInfo.sServerId << " " << keyInfo.sKeyInfo << endl;

	KeyInfo_dt readKeyInfo;
	cltMemShare.readKeyInfo(&readKeyInfo);
	cout << "READ : " << readKeyInfo.iKeyId << " " << readKeyInfo.iKetStatus << " " << readKeyInfo.sClientId << " " << readKeyInfo.sServerId << " " << readKeyInfo.sKeyInfo << endl;
}

/*����ģ�����								**/
void funcEncryptTest()
{
	/*MD5���ܲ���							**/
	Encrypt MD5Encrypt(Encrypt::TYPE_MD5);
	MD5Encrypt.addOriginalData("this is ", strlen("this is "));
	MD5Encrypt.addOriginalData("a test ", strlen("a test "));
	MD5Encrypt.addOriginalData("of MD5.", strlen("of MD5."));

	cout << "SRC DATA: " << "this is a test of MD5." << endl;
	cout << "DST SIZE: " << strlen(MD5Encrypt.getEncryptHexData().c_str()) << endl;
	cout << "DST DATA: " << MD5Encrypt.getEncryptHexData() << endl << endl;

	/*SHA1���ܲ���							**/
	Encrypt SHA1Encrypt(Encrypt::TYPE_SHA1);
	SHA1Encrypt.addOriginalData("this is ", strlen("this is "));
	SHA1Encrypt.addOriginalData("a test ", strlen("a test "));
	SHA1Encrypt.addOriginalData("of SHA1.", strlen("of SHA1."));

	cout << "SRC DATA: " << "this is a test of SHA1." << endl;
	cout << "DST SIZE: " << strlen(SHA1Encrypt.getEncryptHexData().c_str()) << endl;
	cout << "DST DATA: " << SHA1Encrypt.getEncryptHexData() << endl << endl;

	/*SHA224���ܲ���						**/
	Encrypt SHA224Encrypt(Encrypt::TYPE_SHA224);
	SHA224Encrypt.addOriginalData("this is ", strlen("this is "));
	SHA224Encrypt.addOriginalData("a test ", strlen("a test "));
	SHA224Encrypt.addOriginalData("of SHA224.", strlen("of SHA224."));

	cout << "SRC DATA: " << "this is a test of SHA224." << endl;
	cout << "DST SIZE: " << strlen(SHA224Encrypt.getEncryptHexData().c_str()) << endl;
	cout << "DST DATA: " << SHA224Encrypt.getEncryptHexData() << endl << endl;

	/*SHA384���ܲ���						**/
	Encrypt SHA384Encrypt(Encrypt::TYPE_SHA384);
	SHA384Encrypt.addOriginalData("this is ", strlen("this is "));
	SHA384Encrypt.addOriginalData("a test ", strlen("a test "));
	SHA384Encrypt.addOriginalData("of SHA384.", strlen("of SHA384."));

	cout << "SRC DATA: " << "this is a test of SHA384." << endl;
	cout << "DST SIZE: " << strlen(SHA384Encrypt.getEncryptHexData().c_str()) << endl;
	cout << "DST DATA: " << SHA384Encrypt.getEncryptHexData() << endl << endl;
}

void funcRsaEncryptTest()
{
	/*�ͻ������ɹ�Կ����Կ					**/
	RsaEncrypt rsaClientObj;
	rsaClientObj.generateRsaKey(1024, "./OpenSSL/RSA_TEST_SEND_PUBLIC_KEY.pem", "./OpenSSL/RSA_TEST_SEND_PRIVATE_KEY.pem");

	/***************      �˴�ģ��ͻ��˽���Կ�����������, ����˽�����洢��Կ����      *****************/
	ifstream ifs("./OpenSSL/RSA_TEST_SEND_PUBLIC_KEY.pem");
	stringstream str;
	str << ifs.rdbuf();
	ifs.close();
	string clientPubKey = str.str();

	Encrypt encryptClientObj(Encrypt::TYPE_SHA224);
	encryptClientObj.addOriginalData(clientPubKey, clientPubKey.size());
	string md5ClientStr = encryptClientObj.getEncryptHexData();

	string clientSign = rsaClientObj.sign(md5ClientStr, RsaEncrypt::SIGN_LEVEL1);

	ofstream ofs("./OpenSSL/RSA_TEST_RECV_PUBLIC_KEY.pem");
	ofs << clientPubKey;
	ofs.close();

	/*����˽�����Կ						**/
	RsaEncrypt rsaServerObj;
	rsaServerObj.prasePubKeyFromFile("./OpenSSL/RSA_TEST_RECV_PUBLIC_KEY.pem");

	Encrypt encryptServerObj(Encrypt::TYPE_SHA224);
	encryptServerObj.addOriginalData(clientPubKey, clientPubKey.size());
	string md5ServerStr = encryptServerObj.getEncryptHexData();

	bool verifyResult = rsaServerObj.signVerify(md5ServerStr, clientSign, RsaEncrypt::SIGN_LEVEL1);
	if (true == verifyResult)
		cout << "SERVER VERIFY SUCCESS." << endl;
	else
		return;
	/******************************************************************************************************/

	/*����˷������ݴ�����Կ				**/
	char serverKey[128] = "nihao hi ��� bababala 12345";
	cout << "TRANS KEY: " << serverKey << endl;

	string encryptData = rsaServerObj.encryptByPubKey(serverKey);
	cout << "ENCRYPT DATA: " << encryptData << endl;

	/*�ͻ��˽�������						**/
	string decryptData = rsaClientObj.decryptByPriKey(encryptData);
	cout << "DECRYPT DATA: " << decryptData << endl;
}

/*json��ȡ����ģ�����						**/
void funcClientJsonConfTest()
{
	bool isOk = false;
	ClientJsonCpp clientJsonConf("./JsonCpp/ClientJsonConf.json", isOk);
	if (false == isOk)
		return;

	ClitJsConf_dt jsonConf = clientJsonConf.getClientJsConf();
	cout << "CLIENT ID: " << jsonConf.sClientId << endl;
	cout << "SERVER ID: " << jsonConf.sServerId << endl;
	cout << "SERVER IP: " << jsonConf.sServerIp << endl;
	cout << "SERVER PT: " << jsonConf.iServerPort << endl;
	cout << "MEMSHA ID: " << jsonConf.iClientMemShareId << endl;

	DBJsConf_dt dbConf = clientJsonConf.getDBJsConf();
	cout << "DB NAME  : " << dbConf.sDBName << endl;
	cout << "DB TBL   : " << dbConf.sDBTblName << endl;
	cout << "DB USER  : " << dbConf.sDBUserName << endl;
	cout << "DB PASSWD: " << dbConf.sDBUserPasswd << endl;
	cout << "DB ADDR  : " << dbConf.sDBIpAddr << endl;
	cout << "DB PORT  : " << dbConf.iDBPort << endl;
}

/*����ģ�����								**/
void funcFactoryTest()
{
	RequestMsg_dt srcReqData;
	srcReqData.iCmdType		= 1;
	srcReqData.sClientId	= "CLIENT_ID_1";
	srcReqData.sServerId	= "SERVER_ID_1";
	srcReqData.sSign		= "REQ_DATA_SIGN";
	srcReqData.sData		= "REQ_DATA";

	cout << "SRC REQ DATA: " << srcReqData.iCmdType << " " << srcReqData.sClientId << " " << srcReqData.sServerId << " " << srcReqData.sSign << " " << srcReqData.sData << endl;

	CodecFactory* pCodecFactory = new ReqCodecFactory(srcReqData);
	Codec_Base* pCodec = pCodecFactory->createCodec();
	
	string encodeReqData = pCodec->encodeMsg();
	cout << "SERIAL REQ DATA: " << encodeReqData << endl;

	pCodecFactory->modifyType(SERIAL_TYPE, &encodeReqData);
	Codec_Base* pEncodeCodec = pCodecFactory->createCodec();

	RequestMsg_dt* pDstReqData = static_cast<RequestMsg_dt *>(pEncodeCodec->decodeMsg());
	cout << "DST REQ DATA: " << pDstReqData->iCmdType << " " << pDstReqData->sClientId << " " << pDstReqData->sServerId << " " << pDstReqData->sSign << " " << pDstReqData->sData << endl;

	delete pCodecFactory;
	delete pCodec;
	delete pEncodeCodec;
	delete pDstReqData;

	ResponseMsg_dt srcRespData;
	srcRespData.bStatus   = true;
	srcRespData.iSeckeyId = 2;
	srcRespData.sClientId = "CLIENT_ID_2";
	srcRespData.sServerId = "SERVER_ID_2";
	srcRespData.sData     = "RESP_DATA";

	cout << "SRC RESP DATA: " << srcRespData.bStatus << " " << srcRespData.iSeckeyId << " " << srcRespData.sClientId << " " << srcRespData.sServerId << " " << srcRespData.sData << endl;

	pCodecFactory = new RespCodecFactory(srcRespData);
	pCodec = pCodecFactory->createCodec();
	
	string encodeRespData = pCodec->encodeMsg();
	cout << "SERIAL RESP DATA: " << encodeRespData << endl;

	pCodecFactory->modifyType(SERIAL_TYPE, &encodeRespData);
	pEncodeCodec = pCodecFactory->createCodec();

	ResponseMsg_dt* pDstRespData = static_cast<ResponseMsg_dt *>(pEncodeCodec->decodeMsg());
	cout << "DST RESP DATA: " << pDstRespData->bStatus << " " << pDstRespData->iSeckeyId << " " << pDstRespData->sClientId << " " << pDstRespData->sServerId << " " << pDstRespData->sData << endl;

	delete pCodecFactory;
	delete pCodec;
	delete pEncodeCodec;
	delete pDstRespData;
}

/*�ͻ������ݿ�ģ�����						**/
void funcClientSqlTest()
{
	bool isOk = false;
	ClientJsonCpp clientJsonConf("./JsonCpp/ClientJsonConf.json", isOk);
	if (false == isOk)
		return;

	ClientSql clientSqlObj;
	bool connResult = clientSqlObj.connectDatabase(clientJsonConf.getDBJsConf());

	KeyInfo_dt data;
	data.iKetStatus = 1;
	data.iKeyId = 1;
	strcpy(data.sClientId, "clientId_test");
	strcpy(data.sServerId, "serverId_test");
	strcpy(data.sKeyInfo, "client_keyinfo_test");

	bool insertResult = clientSqlObj.insertKeyInfo(data);
	if (false == insertResult)
		return;

	KeyInfo_dt searchData;
	bool searchResult = clientSqlObj.getKeyInfo(data.iKeyId, searchData);
	if (false == searchResult)
		return;
	else
		cout << "CLIENT KEY INFO: " << searchData.iKeyId << " " << searchData.iKetStatus << " " << searchData.sClientId << " " << searchData.sServerId << " " << searchData.sKeyInfo << endl;

	KeyInfo_dt valueData;
	searchResult = clientSqlObj.getValuedKeyInfo(valueData);
	if (false == searchResult)
		return;
	else
		cout << "CLIENT VALUE KEY INFO: " << valueData.iKeyId << " " << valueData.iKetStatus << " " << valueData.sClientId << " " << valueData.sServerId << " " << valueData.sKeyInfo << endl;

	bool removeResult = clientSqlObj.removeKeyInfo(valueData.iKeyId);
	if (false == searchResult)
		cout << "Remove Error." << endl;
	else
		cout << "Remove Success." << endl;
}
