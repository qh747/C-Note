#include "TcpSocket.h"

TcpSocket::TcpSocket()
{
	/*��ʼ��socket�׽��ֻ���			**/
	WSADATA sockEnvir;
	if (0 != WSAStartup(MAKEWORD(2, 2), &sockEnvir))
	{
		std::cerr << "SOCKET ENVIR INIT FAILED. ERR CODE: " << WSAGetLastError() << std::endl;
		return;
	}
		
	/*����socket						**/
	m_sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (INVALID_SOCKET == m_sock)
	{
		std::cerr << "SOCKET CREATE FAILED. ERR CODE: " << WSAGetLastError() << std::endl;
		return;
	}
		
	/*����socketΪ������				**/
	unsigned long nonblockflag = 1;
	if (SOCKET_ERROR == ioctlsocket(m_sock, FIONBIO, &nonblockflag))
		std::cerr << "SOCKET SET NONBLOCK FAILED. ERR CODE: " << WSAGetLastError() << std::endl;

	/*����socket�˿ڸ���				**/
	int reuseFlag = 1;
	if (SOCKET_ERROR == setsockopt(m_sock, SOL_SOCKET, SO_REUSEADDR, (const char *)&reuseFlag, sizeof(reuseFlag)))
		std::cerr << "TCP SERVER SET REUSE ADDR FAILED. ERR CODE: " << WSAGetLastError() << std::endl;
}

TcpSocket::~TcpSocket()
{
	/*�ر�socket						**/
	closesocket(m_sock);

	/*socket�׽��ֻ�������				**/
	WSACleanup();
}

TcpSocket::TcpSocket(SOCKET servSock)
{
	if (INVALID_SOCKET == servSock)
		std::cerr << "SOCKET ASSIGN FAILED." << std::endl;
	else
		m_sock = servSock;
}

int	TcpSocket::connectServer(const string& ip, unsigned short port, unsigned long timeout)
{
	/*���������Ч�Լ��							**/
	if (true == ip.empty() || port <= 0 || timeout <= 0)
	{
		std::cout << "FUNC INPUT PARAM ERROR, FUNC NAME: connectServer() " << std::endl;
		return -1;
	}

	/*����˵�ַ��Ϣ����							**/
	sockaddr_in servAddr;
	memset(&servAddr, 0, sizeof(servAddr));

	servAddr.sin_family = AF_INET;
	servAddr.sin_addr.S_un.S_addr = inet_addr(ip.c_str());
	servAddr.sin_port = port;

	/*���������									**/
	int connResult = 0;
	/*������״̬�����ӻ���������					**/
	connResult = connect(m_sock, (sockaddr *)&servAddr, sizeof(servAddr));
	if (0 != connResult)
	{
		/*select����								**/
		fd_set sendSet;
		FD_ZERO(&sendSet);
		FD_SET(m_sock, &sendSet);

		/*ͨ��select�ж������Ƿ�ɹ�				**/
		timeval sendTimeOut = { timeout, 0 };
		int selectResult = select(m_sock + 1, NULL, &sendSet, NULL, &sendTimeOut);
		if (0 == selectResult)
		{
			/*���ӳ�ʱ								**/
			std::cout << "SOCKET CONNECT TCP SERVER TIMEOUT." << std::endl;
			return -1;
		}
		else if (-1 == selectResult)
		{
			/*����ʧ��								**/
			std::cout << "SOCKET CONNECT TCP SERVER ERROR 1. ERROR CODE: " << WSAGetLastError() << std::endl;
			return -1;
		}
		else
		{
			/*��ȡsocket���ԣ��ж������Ƿ�ɹ�		**/
			int connError = 0;
			int errorLen = sizeof(connError);
			if (getsockopt(m_sock, SOL_SOCKET, SO_ERROR, (char *)&connError, &errorLen) < 0)
			{
				std::cout << "SOCKET CONNECT TCP SERVER ERROR 2. ERROR CODE: " << WSAGetLastError() << std::endl;
				return -1;
			}

			if (0 != connError)
			{
				std::cout << "SOCKET CONNECT TCP SERVER ERROR 3. ERROR CODE: " << connError << std::endl;
				return -1;
			}

			/*���ӳɹ�								**/
			return 0;
		}
	}
	else
		return 0;
}

int TcpSocket::sendMessage(void* pMsgBody, int msgBodySize, unsigned long timeout)
{
	/*���������Ч�Լ��											**/
	if (NULL == pMsgBody || msgBodySize <= 0 || timeout <= 0)
	{
		std::cout << "FUNC INPUT PARAM ERROR, FUNC NAME: sendMessage() " << std::endl;
		return -1;
	}

	/*�ж��Ƿ��ܷ�����Ϣ											**/
	bool canSendMsg = this->canSendMessage(timeout);
	if (false == canSendMsg)
		return -1;

	/*��Ϣ�ײ�Ϊint�������ݣ���Ҫ�������ֽ���ת��Ϊ�����ֽ���		**/
	int msgHead = htonl(msgBodySize);				
	int msgSize = msgBodySize + sizeof(int);

	/*��Ϣ�������													**/
	char* pStrBuf = new char[msgSize];
	memcpy(pStrBuf, &msgHead, sizeof(int));
	memcpy(pStrBuf + sizeof(int), pMsgBody, msgBodySize);

	/*��Ϣ����														**/
	int sendSize = this->sendBytes(pStrBuf, msgSize);
	delete[] pStrBuf;

	return sendSize;
}

int TcpSocket::recvMessage(void* pMsgBody, int msgBodySize, unsigned long timeout)
{
	/*���������Ч�Լ��								**/
	if (NULL == pMsgBody || msgBodySize <= 0 || timeout <= 0)
	{
		std::cout << "FUNC INPUT PARAM ERROR, FUNC NAME: recvMessage() " << std::endl;
		return -1;
	}

	/*�ж��Ƿ��ܽ�����Ϣ								**/
	bool canRecvMsg = this->canRecvMessage(timeout);
	if (false == canRecvMsg)
		return -1;

	/*�жϽ��ջ������Ƿ�������							**/
	unsigned long hasData = 0;
	ioctlsocket(m_sock, FIONREAD, &hasData);			// ���ڷ�����ģʽ���ж϶Զ��Ƿ�Ͽ�����
	if (hasData <= 0)
		return 0;

	/*������Ϣ�ײ�										**/
	int msgHead = 0;
	this->recvBytes(&msgHead, sizeof(msgHead));

	/*��ȡ��Ϣ��ʵ�ʳ���								**/
	int msgSize = ntohl(msgHead);
	if (msgSize <= 0)
		return msgSize;									// �Զ˶Ͽ�����
	
	/*������Ϣ����										**/
	char* pStrBuf = static_cast<char *>(pMsgBody);
	if (msgSize <= msgBodySize)
	{
		/*��Ϣ����С�ڵ��ڽ��ջ���������				**/
		this->recvBytes(pStrBuf, msgSize);
		pStrBuf[msgSize] = '\0';
		return msgSize;
	}
	else
	{
		/*��Ϣ���ȴ��ڽ��ջ���������					**/
		char* pTmpBuf = new char[msgSize];
		this->recvBytes(pTmpBuf, msgSize);

		memcpy(pStrBuf, pTmpBuf, msgBodySize);
		pStrBuf[msgBodySize] = '\0';

		delete[] pTmpBuf;
		return msgBodySize;
	}
}

bool TcpSocket::canRecvMessage(unsigned long timeout)
{
	/*select����						**/
	fd_set recvSet;
	FD_ZERO(&recvSet);
	FD_SET(m_sock, &recvSet);

	timeval readTimeOut = { timeout, 0 };
	int selectResult = select(m_sock + 1, &recvSet, NULL, NULL, &readTimeOut);

	if (selectResult < 0)
		return false;
	else if (0 == selectResult)
		return false;

	if (m_sock != recvSet.fd_array[0])
		return false;
	else
		return true;
}

bool TcpSocket::canSendMessage(unsigned long timeout)
{
	/*select����						**/
	fd_set sendSet;
	FD_ZERO(&sendSet);
	FD_SET(m_sock, &sendSet);

	timeval sendTimeOut = { timeout, 0 };
	int selectResult = select(m_sock + 1, NULL, &sendSet, NULL, &sendTimeOut);
	if (selectResult < 0)
		return false;
	else if (0 == selectResult)
		return false;

	if (m_sock != sendSet.fd_array[0])
		return false;
	else
		return true;
}

int TcpSocket::recvBytes(void* pRecvBuf, int recvSize)
{
	int curRecvSize = 0;
	char* pStrBuf = static_cast<char *>(pRecvBuf);
	while (curRecvSize < recvSize)
	{
		curRecvSize += recv(m_sock, pStrBuf + curRecvSize, (recvSize - curRecvSize), 0);
	}

	return curRecvSize;
}

int TcpSocket::sendBytes(void* pSendBuf, int sendSize)
{
	int curSendSize = 0;
	char* pStrBuf = static_cast<char *>(pSendBuf);
	while (curSendSize < sendSize)
	{
		curSendSize += send(m_sock, pStrBuf + curSendSize, (sendSize - curSendSize), 0);
	}

	return curSendSize;
}