#pragma once
#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

// ģ�巽��ģʽ
class AbstractMethod
{
public:
	virtual ~AbstractMethod() {}

	// ������processMsg()��������recvMsg()��praseMsg()��sendMsg()������ִ��˳��
	virtual string processMsg(const string& msg);

protected:
	virtual void recvMsg(const string& msg) = 0;
	virtual void praseMsg() = 0;
	virtual const string& sendMsg() = 0;

protected:
	string m_msg;
};

class FastProcessMethod : public AbstractMethod
{
public:
	virtual ~FastProcessMethod() {}

protected:
	// ������ʵ�ֺ���ϸ��
	virtual void recvMsg(const string& msg);
	virtual void praseMsg();
	virtual const string& sendMsg();
};

class SafeProcessMethod : public AbstractMethod
{
public:
	virtual ~SafeProcessMethod() {}

protected:
	// ������ʵ�ֺ���ϸ��
	virtual void recvMsg(const string& msg);
	virtual void praseMsg();
	virtual const string& sendMsg();
};

// ģ�巽��ģʽ���Ժ���
void TemplateMethodTestDemo();