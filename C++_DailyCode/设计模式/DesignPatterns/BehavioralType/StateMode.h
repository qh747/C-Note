#pragma once
#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

class Context;

// ����״̬����
class AbstractState
{
public:
	virtual ~AbstractState() {}
	virtual void handle(const string& data) = 0;
};

// ����״̬��
class SendState : public AbstractState
{
public:
	virtual ~SendState() {}
	virtual void handle(const string& data) { cout << "In Send State. Send Data: " << data << endl; }
};

class RecvState : public AbstractState
{
public:
	virtual ~RecvState() {}
	virtual void handle(const string& data) { cout << "In Recv State. Recv Data: " << data << endl; }
};

// ״̬ģʽ
class Context
{
public:
	void handleData(const string& data) { m_pState->handle(data); }
	void setState(AbstractState* curState) { m_pState = curState; }

private:
	AbstractState* m_pState;
};

// ״̬ģʽ���Ժ���
void StateTestDemo();