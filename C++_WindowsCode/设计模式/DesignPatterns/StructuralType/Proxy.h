#pragma once
#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

// ��������
class AbstractServer
{
public:
	virtual ~AbstractServer() {}
	virtual void startServer() = 0;
};

class HttpServer : public AbstractServer
{
public:
	virtual ~HttpServer() {}

public:
	virtual void startServer() { cout << "Http Server Start." << endl; }
};

// ����ģʽ
class ServerProxy : public AbstractServer
{
public:
	ServerProxy(string userName, string userPasswd) : m_userName(userName), m_userPasswd(userPasswd), m_pServer(new HttpServer()) {}
	virtual ~ServerProxy();
	virtual void startServer();

private:
	string				m_userName;
	string				m_userPasswd;
	AbstractServer*		m_pServer;
};

// ����ģʽ���Ժ���
void ProxyTestDemo();