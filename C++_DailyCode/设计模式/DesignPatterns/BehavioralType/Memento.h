#pragma once
#include <iostream>
#include <string>
#include <stack>
using std::cout;
using std::endl;
using std::string;
using std::stack;

// ������
class Memento
{
	friend class Originator;

public:
	Memento(const string& state) : m_state(state) {}

private:
	const string& getState() const { return m_state; }

private:
	string m_state;
};

// ԭʼ��
class Originator
{
public:
	Originator(const string& state) : m_state(state) {}
	Memento*		saveState() { return new Memento(m_state); }
	void			setState(const string& state) { m_state = state; }
	const string&	getState() { return m_state; }
	void			restoreState(const Memento& mem) { m_state = mem.getState(); }

private:
	string m_state;
};

// ���չ�����
class CareTaker
{
public:
	void addMemento(Memento* mem) { m_memStack.push(mem); }
	bool hasMemento() { return !m_memStack.empty(); }
	Memento* getLastMemento()
	{
		if (m_memStack.empty())
			return nullptr;
		else
		{
			Memento* top = m_memStack.top();
			m_memStack.pop();
			return top;
		}
	}

private:
	stack<Memento*> m_memStack;
};

// ����ģʽ���Ժ���
void MementoTestDemo();