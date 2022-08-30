#include <iostream>
#include <cstring>
#include <string>
#include <map>
using namespace std;

class Originator;

class Memento
{
	friend class Originator;

/*խ�ӿڣ����ڹ�����CareTaker    **/
public:
	~Memento() { }

/*��ӿڣ�����Originator��    **/
private:
	Memento(const string& curState) : m_state(curState) { }

	const string& getState() { return m_state; }

private:
	string m_state;
};


class Originator
{
public:
	Originator() { }
	~Originator() { } 

public:
	void modifyState(const string& state)
	{
		m_state = state;
	}

	void showState()
	{
		cout << "Current State: " << m_state << endl;
	}

	Memento* saveState()
	{
		return new Memento(m_state);
	}

	void setState(Memento* pMemento)
	{
		if(NULL != pMemento)
			m_state = pMemento->getState();
	}

private:
	string m_state;
};


class CareTaker
{
public:
	CareTaker(Originator* pOriginator) : m_pOriginator(pOriginator)
	{ 

	}

	~CareTaker()
	{
		for (map<int, Memento*>::iterator iter = m_mementoMap.begin(); iter != m_mementoMap.end(); iter++)
		{
			delete iter->second;
			iter->second = NULL;
		}
	}

public:
	void addMemento(Memento* pMemento)
	{
		int currentMementoIndex = m_mementoMap.size();
		m_mementoMap.insert(make_pair(currentMementoIndex, pMemento));
	}

	void undo(int index)
	{
		if (NULL == m_pOriginator)
			return;

		map<int, Memento*>::iterator iter = m_mementoMap.find(index);
		if (m_mementoMap.end() != iter)
			m_pOriginator->setState(iter->second);
	}

private:
	Originator* m_pOriginator;
	map<int, Memento*> m_mementoMap;
};

int main()
{
	Originator* pOriginator = new Originator();
	CareTaker* pCareTaker = new CareTaker(pOriginator);

	pOriginator->modifyState(string("Init State"));
	pOriginator->showState();
	/*����״̬����    **/
	pCareTaker->addMemento(pOriginator->saveState());
	
	pOriginator->modifyState(string("Run State"));
	pOriginator->showState();

	pCareTaker->addMemento(pOriginator->saveState());

	pOriginator->modifyState(string("Error State"));
	pOriginator->showState();

	/*״̬����    **/
	pCareTaker->undo(1);
	pOriginator->showState();

	pOriginator->modifyState(string("End State"));
	pOriginator->showState();

	delete pCareTaker;
	pCareTaker = NULL;

	delete pOriginator;
	pOriginator = NULL;

	system("pause");
	return 0;
}