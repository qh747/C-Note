#include <iostream>
#include <cstring>
#include <string>
#include <memory>
using namespace std;

/*���������    **/
class AbstractServer
{
public:
	virtual ~AbstractServer() { }

public:
	virtual void startServer() = 0;
};

/*���������    **/
class HttpServer : public AbstractServer
{
public:
	HttpServer() { }
	virtual ~HttpServer() { }

public:
	virtual void startServer()
	{
		cout << "Http Server Start." << endl;
	}
};

/*���������    **/
class ServerProxy : public AbstractServer
{
public:
	ServerProxy(string userName, string userPasswd) :m_userName(userName), m_userPasswd(userPasswd)
	{
		m_pServer = new HttpServer();
	}

	virtual ~ServerProxy()
	{
		if (NULL == m_pServer)
			return;

		delete m_pServer;
		m_pServer = NULL;
	}

public:
	virtual void startServer()	/*������, ���ӵ�¼��֤����    **/
	{
		if (string("admin") != m_userName)
		{
			cout << "User Name Error." << endl;
			return;
		}

		if (string("12345678") != m_userPasswd)
		{
			cout << "User Password Error." << endl;
			return;
		}

		cout << "Authenticate Success. Server Is Starting." << endl;
		m_pServer->startServer();
	}

private:
	string				m_userName;
	string				m_userPasswd;
	AbstractServer*		m_pServer;
};

int main()
{
	shared_ptr<AbstractServer> pServer = make_shared<ServerProxy>(string("admin"), string("12345678"));
	pServer->startServer();

	system("pause");
	return 0;
}