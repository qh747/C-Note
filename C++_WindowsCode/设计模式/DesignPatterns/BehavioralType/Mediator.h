#pragma once
#include <iostream>
#include <string>
#include <vector>
using std::cout;
using std::endl;
using std::string;
using std::vector;

class AbstractMediator;

// ����ͬ���� 
class AbstractColleague
{
public:
	void	setMediator(AbstractMediator* pMedaitor) { m_pMediator = pMedaitor; }
	virtual ~AbstractColleague() {}
	virtual void sendMsg(string msg) = 0;
	virtual void recvMsg(string msg) = 0;

protected:
	AbstractMediator*  m_pMediator;
};

// �����н�����
class AbstractMediator
{
public:
	virtual ~AbstractMediator() {}
	virtual void addColl(AbstractColleague* coll) = 0;
	virtual void relayMsg(string msg) = 0;
};

// ����ͬ����
class FuncCollegue : public AbstractColleague
{
public:
	virtual ~FuncCollegue() {}
	virtual void sendMsg(string msg);
	virtual void recvMsg(string msg);
};

// ����ͬ����
class DisplayCollegue : public AbstractColleague
{
public:
	virtual ~DisplayCollegue() {}
	virtual void sendMsg(string msg);
	virtual void recvMsg(string msg);
};

// �����н�����
class FuncMediator : public AbstractMediator
{
public:
	virtual ~FuncMediator() {}
	virtual void addColl(AbstractColleague* aoll);
	virtual void relayMsg(string msg);

private:
	vector<AbstractColleague*> m_collVec;
};

// �����н�����
class DisplayMediator : public AbstractMediator
{
public:
	virtual ~DisplayMediator() {}
	virtual void addColl(AbstractColleague* aoll);
	virtual void relayMsg(string msg);

private:
	vector<AbstractColleague*> m_collVec;
};

// �н���ģʽ���Ժ���
void MediatorTestDemo();