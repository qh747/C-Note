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

	cout << "REQUEST SOURCE MSG:" << " "
		 << srcMsg.cmdType		  << " "
		 << srcMsg.clientId		  << " "
		 << srcMsg.serverId       << " "
		 << srcMsg.sign			  << " "
		 << srcMsg.data			  << endl << endl;

	/*������Ϣ����							**/
	string encodeMsg = reqEncodeModel.encodeMsg();
	cout << "REQUEST ENCODE MSG: " << encodeMsg << endl << endl;

	/*������Ϣ����							**/
	Request_Codec reqDecodeModel;
	reqDecodeModel.initMessage(encodeMsg);
	RequestMsg_dt* pDstMsg = static_cast<RequestMsg_dt *>(reqDecodeModel.decodeMsg());
	
	cout << "REQUEST DEST MSG:" << " "
		 << pDstMsg->cmdType	<< " "
		 << pDstMsg->clientId   << " "
		 << pDstMsg->serverId   << " "
		 << pDstMsg->sign		<< " "
		 << pDstMsg->data		<< endl << endl;
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

	cout << "RESPONSE SOURCE MSG:" << " "
		 << srcMsg.status		   << " "
		 << srcMsg.clientId		   << " "
		 << srcMsg.serverId		   << " "
		 << srcMsg.seckeyId		   << " "
		 << srcMsg.data			   << endl << endl;

	/*��Ӧ��Ϣ����							**/
	string encodeMsg = respEncodeModel.encodeMsg();
	cout << "RESPONSE ENCODE MSG: " << encodeMsg << endl << endl;

	/*��Ӧ��Ϣ����							**/
	Response_Codec respDecodeModel;
	respDecodeModel.initMessage(encodeMsg);
	ResponseMsg_dt* pDstMsg = static_cast<ResponseMsg_dt *>(respDecodeModel.decodeMsg());

	cout << "RESPONSE DEST MSG:" << " "
		 << pDstMsg->status      << " "
		 << pDstMsg->clientId	 << " "
		 << pDstMsg->serverId	 << " "
		 << pDstMsg->seckeyId	 << " "
		 << pDstMsg->data        << endl << endl;
}