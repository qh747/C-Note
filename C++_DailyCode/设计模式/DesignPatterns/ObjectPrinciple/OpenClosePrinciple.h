#pragma once
#include <iostream>
using std::cout;
using std::endl;

// ����ԭ��
class AbstractOperator
{
public:
	virtual ~AbstractOperator() {}
	virtual int doOperate(int lft, int rght) = 0;
};

class AddOperator : public AbstractOperator
{
public:
	virtual ~AddOperator() {}
	virtual int doOperate(int lft, int rght) { return lft + rght; }
};

class ReduceOperator : public AbstractOperator
{
public:
	virtual ~ReduceOperator() {}
	virtual int doOperate(int lft, int rght) { return lft - rght; }
};

// ����ԭ����Ժ���
void OpenClosePrincipleTestDemo();