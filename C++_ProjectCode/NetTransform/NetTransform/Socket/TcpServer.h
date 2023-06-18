#pragma once 
#include <WinSock2.h>
#pragma comment(lib, "ws2_32.lib")
#include "TcpSocket.h"
#include <ctime>

class TcpServer
{
public:
	TcpServer();
	~TcpServer();

public:
	int			setListen(const string& ip, unsigned short port);		// ����TCP����˼�����IP��ַ�Ͷ˿�
	TcpSocket*	acceptConn(unsigned long timeout);						// �ȴ��ͻ������ӣ�ͨ��timeout�������õȴ�ʱ��

private:
	SOCKET		m_sock;													// TCP�����ʹ���׽���
};