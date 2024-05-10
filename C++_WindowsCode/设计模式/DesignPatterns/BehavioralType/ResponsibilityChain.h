#pragma once
#include <iostream>
#include <string>
using std::string;
using std::cout;
using std::endl;

// ��Ϣ����
typedef struct MSG_DATA_TYPE
{
	string ipMsg;
	string transMsg;
	string appMsg;

	MSG_DATA_TYPE() : ipMsg(""), transMsg(""), appMsg("") {}
}Msg_dt;

// ������ģʽ
class AbstractMsgHandler
{
public:
	AbstractMsgHandler() { m_pNextMsgHandler = nullptr; }
	virtual ~AbstractMsgHandler() {}
	virtual void recvMsg(const Msg_dt& msg) = 0;
	virtual AbstractMsgHandler* getNextHandler() { return m_pNextMsgHandler; }
	virtual void setNextHandler(AbstractMsgHandler* handler) { m_pNextMsgHandler = handler; }

private:
	AbstractMsgHandler* m_pNextMsgHandler;
};

class IPMsgHandler : public AbstractMsgHandler
{
public:
	virtual ~IPMsgHandler() {}
	virtual void recvMsg(const Msg_dt& msg);
};

class TransMsgHandler : public AbstractMsgHandler
{
public:
	virtual ~TransMsgHandler() {}
	virtual void recvMsg(const Msg_dt& msg);
};

class APPMsgHandler : public AbstractMsgHandler
{
public:
	virtual ~APPMsgHandler() {}
	virtual void recvMsg(const Msg_dt& msg);
};

// ������ģʽ���Ժ���
void RespChainTestDemo();