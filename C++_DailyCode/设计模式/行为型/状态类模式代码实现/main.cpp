#include <iostream>
#include <cstring>
using namespace std;

class Context;

/*����״̬����    **/
class State
{
public:
	virtual ~State() { }
	virtual void handle(const string& data, Context* pContext) = 0;
};

/*����״̬������    **/
class InitState : public State
{
public:
	InitState() { }
	virtual ~InitState() { }

public:
	virtual void handle(const string& data, Context* pContext);
};

class RunState : public State
{
public:
	RunState() { }
	virtual ~RunState() { }

public:
	virtual void handle(const string& data, Context* pContext);
};

class EndState : public State
{
public:
	EndState() { }
	virtual ~EndState() { }

public:
	virtual void handle(const string& data, Context* pContext);
};


/*������    **/
class Context
{
public:
	Context() : m_pState(new InitState())	/*Ĭ�ϸ���ʼ��״̬    **/
	{

	}

	~Context()
	{ 
		if (NULL != m_pState)
		{
			delete m_pState;
			m_pState = NULL;
		}
	}

public:
	void HandleData(const string& data)
	{
		if (NULL != m_pState)
			m_pState->handle(data, this);

	}

	void setState(State* curState)
	{ 
		if (NULL != m_pState)
		{
			delete m_pState;
			m_pState = NULL;
		}

		m_pState = curState;
	}

private:
	State* m_pState;
};


/*����״̬�ඨ��,�����ŵ������������Ϊ���ܹ���ȡ��������ķ���    **/
void InitState::handle(const string& data, Context* pContext)
{
	cout << "Init State Receive And Record Data. Data : " << data << endl;
	pContext->setState(new RunState());		/*��״̬���п����Զ��л���ָ������һ��״̬    **/
}

void RunState::handle(const string& data, Context* pContext)
{
	cout << "Run State Process Data. Data : " << data << endl;
	pContext->setState(new EndState());		
}

void EndState::handle(const string& data, Context* pContext)
{
	cout << "End State Destory Data. Data : " << data << endl;
}


int main()
{
	Context* pContext = new Context();
	pContext->HandleData("Build Connection");
	pContext->HandleData("Data Stream");
	pContext->HandleData("Destory Connection");

	delete pContext;
	pContext = NULL;

	system("pause");
	return 0;
}