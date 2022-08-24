#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

/*�۲�����    **/
class AbstractObserver
{
public:
	virtual ~AbstractObserver() { }

public:
	virtual void update(string data) = 0;
};

class PhoneObserver : public AbstractObserver
{
public:
	PhoneObserver() { }
	virtual ~PhoneObserver() { }

public:
	virtual void update(string data)
	{
		cout << "Phone Receive Thechnology Data: " << data << endl;
	}
};

class ComputerObserver : public AbstractObserver
{
public:
	ComputerObserver() { }
	virtual ~ComputerObserver() { }

public:
	virtual void update(string data)
	{
		cout << "Computer Receive Thechnology Data: " << data << endl;
	}
};


/*������    **/
class AbstractTopic
{
public:
	virtual ~AbstractTopic() { }

public:
	virtual void registerObj(AbstractObserver* observerPtr) = 0;
	virtual void unRegisterObj(AbstractObserver* observerPtr) = 0;

public:
	virtual void notifyObj(string data) = 0;
};


class TechnologyTopic : public AbstractTopic
{
public:
	TechnologyTopic() { }
	virtual ~TechnologyTopic() { }

public:
	virtual void registerObj(AbstractObserver* observerPtr)
	{
		if (m_observerArray.end() == find(m_observerArray.begin(), m_observerArray.end(), observerPtr))
		{
			m_observerArray.push_back(observerPtr);
		}
	}

	virtual void unRegisterObj(AbstractObserver* observerPtr)
	{
		vector<AbstractObserver*>::iterator iter = find(m_observerArray.begin(), m_observerArray.end(), observerPtr);
		if (m_observerArray.end() != iter)
		{
			m_observerArray.erase(iter);
		}
	}

public:
	virtual void notifyObj(string data)
	{
		for (int i = 0; i < m_observerArray.size(); ++i)
		{
			m_observerArray[i]->update(data);
		}
	}

private:
	vector<AbstractObserver*> m_observerArray;
};



int main()
{
	/*�ֻ��û�    **/
	AbstractObserver* phonePtr = new PhoneObserver();

	/*�����û�    **/
	AbstractObserver* computerPtr = new ComputerObserver();

	/*�Ƽ���������Ϣ    **/
	AbstractTopic* technologyPtr = new TechnologyTopic();

	/*�û�������Ϣ    **/
	technologyPtr->registerObj(phonePtr);
	technologyPtr->registerObj(computerPtr);

	/*��Ϣ֪ͨ    **/
	technologyPtr->notifyObj("Good News");

	/*�����û�ȡ������    **/
	technologyPtr->unRegisterObj(computerPtr);

	/*��Ϣ֪ͨ    **/
	technologyPtr->notifyObj("Bad News");

	delete technologyPtr;
	technologyPtr = NULL;

	delete phonePtr;
	phonePtr = NULL;

	delete computerPtr;
	computerPtr = NULL;

	system("pause");
	return 0;
}