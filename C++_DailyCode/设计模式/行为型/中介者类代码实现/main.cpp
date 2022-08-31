#include <iostream>
#include <cstring>
#include <string>
#include <vector>
using namespace std;

enum ClASS_TYPE
{
	FUNC_CLASS = 1,		/*������    **/
	UI_CLASS   = 2,		/*������    **/
};

class Mediator;
class Collegue;

/*�����н�����    **/        
class Mediator
{
public:
	virtual ~Mediator() {}

public:
	virtual void addCollegue(Collegue* pCollegue) = 0;
	virtual void send(string message, Collegue* pCollegue) = 0;
};

/*����ͬ����    **/
class Collegue
{
public:
	virtual ~Collegue() { }

public:
	void setClassType(ClASS_TYPE classType)
	{
		m_classType = classType;
	}

	ClASS_TYPE getClassType()
	{
		return m_classType;
	}

	void setMediator(Mediator* pMedaitor)
	{
		m_pMediator = pMedaitor;
	}

	Mediator* getMediator()
	{
		return m_pMediator;
	}

	virtual void sendMessage(string message) = 0;
	virtual void receiveMessage(string message) = 0;

protected:
	Mediator*  m_pMediator;
	ClASS_TYPE m_classType;
};

/*����ͬ����    **/
class FirstFuncCollegue : public Collegue
{
public:
	FirstFuncCollegue() { }
	virtual ~FirstFuncCollegue() { }

public:
	virtual void sendMessage(string message)
	{
		cout << "First Func Collegue Send Message: " << message << endl;
		this->m_pMediator->send(message, this);
	}

	virtual void receiveMessage(string message)
	{
		cout << "First Func Collegue Receive Message: " << message << endl;
	}
};

class SecondFuncCollegue : public Collegue
{
public:
	SecondFuncCollegue() { }
	virtual ~SecondFuncCollegue() { }

public:
	virtual void sendMessage(string message)
	{
		cout << "Second Func Collegue Send Message: " << message << endl;
		this->m_pMediator->send(message, this);
	}

	virtual void receiveMessage(string message)
	{
		cout << "Second Func Collegue Receive Message: " << message << endl;
	}
};

class FirstUiCollegue : public Collegue
{
public:
	FirstUiCollegue() { }
	virtual ~FirstUiCollegue() { }

public:
	virtual void sendMessage(string message)
	{
		cout << "First UI Collegue Send Message: " << message << endl;
		this->m_pMediator->send(message, this);
	}

	virtual void receiveMessage(string message)
	{
		cout << "First UI Collegue Receive Message: " << message << endl;
	}
};

class SecondUiCollegue : public Collegue
{
public:
	SecondUiCollegue() { }
	virtual ~SecondUiCollegue() { }

public:
	virtual void sendMessage(string message)
	{
		cout << "Second UI Collegue Send Message: " << message << endl;
		this->m_pMediator->send(message, this);
	}

	virtual void receiveMessage(string message)
	{
		cout << "Second UI Collegue Receive Message: " << message << endl;
	}
};

/*�����н�����    **/
/*�ֿ����������н�����;����н���������Ϊ�н������ͬ���໥�����    **/
class ConcreteMediator : public Mediator
{
public:
	virtual ~ConcreteMediator() { }

public:
	virtual void addCollegue(Collegue* pCollegue)
	{
		if (ClASS_TYPE::FUNC_CLASS == pCollegue->getClassType())
			m_funcCollegueList.push_back(pCollegue);
		else
			m_uiCollegueList.push_back(pCollegue);
	}
	virtual void send(string message, Collegue* pCollegue)
	{
		if (ClASS_TYPE::FUNC_CLASS == pCollegue->getClassType())
		{
			cout << "Mediator Forward Message From Func Class To UI Class." << endl;
			for (vector<Collegue*>::iterator iter = m_uiCollegueList.begin(); iter != m_uiCollegueList.end(); iter++)
			{
				(*iter)->receiveMessage(message);
			}
		}
		else
		{
			cout << "Mediator Forward Message From UI Class To Func Class." << endl;
			for (vector<Collegue*>::iterator iter = m_funcCollegueList.begin(); iter != m_funcCollegueList.end(); iter++)
			{
				(*iter)->receiveMessage(message);
			}
		}
	}

private:
	vector<Collegue*> m_funcCollegueList;
	vector<Collegue*> m_uiCollegueList;
};

int main()
{
	/*��ʼ���н���    **/
	Mediator* pMediator = new ConcreteMediator();

	/*��ʼ��ͬ��, ��������ͬ�ºͽ���ͬ��    **/
	Collegue* pFstFuncCollegue = new FirstFuncCollegue();
	pFstFuncCollegue->setClassType(ClASS_TYPE::FUNC_CLASS);

	Collegue* pSecFuncCollegue = new SecondFuncCollegue();
	pSecFuncCollegue->setClassType(ClASS_TYPE::FUNC_CLASS);

	Collegue* pFstUiCollegue = new FirstUiCollegue();
	pFstUiCollegue->setClassType(ClASS_TYPE::UI_CLASS);

	Collegue* pSecUiCollegue = new SecondUiCollegue();
	pSecUiCollegue->setClassType(ClASS_TYPE::UI_CLASS);

	/*����ͬ�����н��ߵĹ�ϵ    **/
	pFstFuncCollegue->setMediator(pMediator);
	pSecFuncCollegue->setMediator(pMediator);
	pFstUiCollegue->setMediator(pMediator);
	pSecUiCollegue->setMediator(pMediator);

	pMediator->addCollegue(pFstFuncCollegue);
	pMediator->addCollegue(pSecFuncCollegue);
	pMediator->addCollegue(pFstUiCollegue);
	pMediator->addCollegue(pSecUiCollegue);

	/*������ͬ�·�����Ϣ    **/
	pFstFuncCollegue->sendMessage(string("Hello UI"));

	/*������ͬ�·�����Ϣ    **/
	pFstUiCollegue->sendMessage(string("Hello Func"));

	/*�ڴ��ͷ�    **/
	delete pMediator;
	pMediator = NULL;

	delete pFstFuncCollegue;
	pFstFuncCollegue = NULL;

	delete pSecFuncCollegue;
	pSecFuncCollegue = NULL;

	delete pFstUiCollegue;
	pFstUiCollegue = NULL;

	delete pSecUiCollegue;
	pSecUiCollegue = NULL;

	system("pause");
	return 0;
}