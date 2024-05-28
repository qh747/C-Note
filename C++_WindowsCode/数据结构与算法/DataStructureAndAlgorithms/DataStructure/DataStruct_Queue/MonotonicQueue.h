#pragma once
#include <queue>
#include <string>
#include <iostream>
using std::queue;
using std::string;
using std::cerr;
using std::endl;

/*��������									**/
class BasicMonotonicQueue
{
public:
	virtual ~BasicMonotonicQueue() {}

public:
	virtual void	push(int val) = 0;					// ����Ԫ��
	virtual void	pop() = 0;							// ����Ԫ��
	virtual int		top() = 0;							// ��ȡ����Ԫ��
	virtual bool    empty() { return m_que.empty(); }	// �ж϶����Ƿ�Ϊ��

protected:
	queue<int> m_que;
};

/*������������								**/
class IncreaseMonotonicQueue : public BasicMonotonicQueue
{
public:
	virtual ~IncreaseMonotonicQueue() {}

public:
	virtual void	push(int val);
	virtual void	pop();
	virtual int		top();
};

/*�����ݼ�����								**/
class DecreaseMonotonicQueue : public BasicMonotonicQueue
{
public:
	virtual ~DecreaseMonotonicQueue() {}

public:
	virtual void	push(int val);
	virtual void	pop();
	virtual int		top();
};