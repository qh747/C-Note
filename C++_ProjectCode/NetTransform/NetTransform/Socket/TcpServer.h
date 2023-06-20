#pragma once 
#include "TcpSocket.h"
/*TCP �����															**/
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