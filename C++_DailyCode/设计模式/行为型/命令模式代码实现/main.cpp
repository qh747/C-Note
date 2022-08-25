#include <iostream>
#include <cstring>
#include <string>
using namespace std;

/*�����࣬��������    **/
class ServerClass
{
public:
	void dataOperate()
	{
		cout << "Server Receive Data. Storage Data." << endl;
	}

	void messageOperate()
	{
		cout << "Server Receive Message. Process Message." << endl;
	}

	void commandOperate()
	{
		cout << "Server Receive Command. Response Command." << endl;
	}
};

/*������    **/
class AbstractOperateClass
{
public:
	virtual ~AbstractOperateClass() { }

public:
	virtual void operate() = 0;
};

class DataOperateClass : public AbstractOperateClass
{
public:
	DataOperateClass(ServerClass* pServer) : m_pServer(pServer) { }
	virtual ~DataOperateClass() { }

public:
	virtual void operate()
	{
		if (NULL == m_pServer)
			return;

		m_pServer->dataOperate();
	}

private:
	ServerClass* m_pServer;
};

class MessageOperateClass : public AbstractOperateClass
{
public:
	MessageOperateClass(ServerClass* pServer) : m_pServer(pServer) { }
	virtual ~MessageOperateClass() { }

public:
	virtual void operate()
	{
		if (NULL == m_pServer)
			return;

		m_pServer->messageOperate();
	}

private:
	ServerClass* m_pServer;
};

class CommandOperateClass : public AbstractOperateClass
{
public:
	CommandOperateClass(ServerClass* pServer) : m_pServer(pServer) { }
	virtual ~CommandOperateClass() { }

public:
	virtual void operate()
	{
		if (NULL == m_pServer)
			return;

		m_pServer->commandOperate();
	}

private:
	ServerClass* m_pServer;
};

/*�����࣬�ͻ�����    **/
class ClientClass
{
public:
	void setOperate(AbstractOperateClass* pOperate)
	{
		m_pOperate = pOperate;
	}

	void execute()
	{
		if (NULL == m_pOperate)
			return;

		m_pOperate->operate();
	}

private:
	AbstractOperateClass* m_pOperate;
};


int main()
{
	/*���������ߺͷ�����    **/
	ServerClass* serverPtr = new ServerClass();
	ClientClass* clientPtr = new ClientClass();

	/*ִ�з������ݲ���    **/
	AbstractOperateClass* operatePtr = new DataOperateClass(serverPtr);
	clientPtr->setOperate(operatePtr);
	cout << "Client Send Data." << endl;
	clientPtr->execute();

	/*ִ�з�����Ϣ����    **/
	delete operatePtr;
	operatePtr = new MessageOperateClass(serverPtr);
	clientPtr->setOperate(operatePtr);
	cout << "Client Send Message." << endl;
	clientPtr->execute();

	/*ִ�з����������    **/
	delete operatePtr;
	operatePtr = new CommandOperateClass(serverPtr);
	clientPtr->setOperate(operatePtr);
	cout << "Client Send Command." << endl;
	clientPtr->execute();

	delete clientPtr;
	clientPtr = NULL;

	delete serverPtr;
	serverPtr = NULL;

	system("pause");
	return 0;
}