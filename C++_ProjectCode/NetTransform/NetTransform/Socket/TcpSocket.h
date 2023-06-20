#pragma once
#pragma warning(disable: 4996)
#pragma comment(lib, "ws2_32.lib")
#include <WinSock2.h>
#include <string>
#include <cstring>
#include <stdexcept>
#include <iostream>
#include <ctime>
#include <cstdlib>
using std::string;

/*TCP�׽��֣����ڷ������ͻ���ͨ�ţ�֧�ַ���ˡ��ͻ���ʹ��									**/
class TcpSocket
{
public:
	TcpSocket();																			// TCP�ͻ���ʹ�ã����캯��
	~TcpSocket();																			// ��������
	TcpSocket(SOCKET servSock);																// TCP�����ʹ�ã����캯��

public:
	int		connectServer(const string& ip, unsigned short port, unsigned long timeout);	// TCP�ͻ���ʹ�ã�����TCP�����
	int 	sendMessage(void* pMsgBody, int msgBodySize, unsigned long timeout);			// ������Ϣ
	int		recvMessage(void* pMsgBody, int msgBodySize, unsigned long timeout);			// ������Ϣ

private:
	bool    canRecvMessage(unsigned long timeout);											// ָ��ʱ�����Ƿ��ܽ�����Ϣ�ж�
	bool    canSendMessage(unsigned long timeout);											// ָ��ʱ�����Ƿ��ܷ�����Ϣ�ж�

	int		recvBytes(void* pRecvBuf, int recvSize);										// ����n�ֽ�����
	int		sendBytes(void* pSendBuf, int sendSize);										// ����n�ֽ�����

	bool	isSockValid();																	// �ж�socket�Ƿ���Ч

private:
	SOCKET m_sock;																			// socketͨ���׽���
};