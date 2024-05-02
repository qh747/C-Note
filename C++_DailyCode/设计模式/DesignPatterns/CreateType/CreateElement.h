#pragma once
#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

// ������Դ��
class AbstractElement
{
public:
	virtual ~AbstractElement() {}

public:
	virtual void showInfo() = 0;
};

// ������Դ��һ
class SpecficElementFst : public AbstractElement
{
public:
	SpecficElementFst() : AbstractElement() {}
	virtual ~SpecficElementFst() {}

public:
	virtual void showInfo() { cout << "First Specific Info" << endl; }
};

// ������Դ���
class SpecficElementSec : public AbstractElement
{
public:
	SpecficElementSec() : AbstractElement() {}
	virtual ~SpecficElementSec() {}

public:
	virtual void showInfo() { cout << "Second Specific Info" << endl; }
};

// �³�����Դ��
class NewAbstractElement
{
public:
	virtual ~NewAbstractElement() {}

public:
	virtual void showNewInfo() = 0;
};

// �¾�����Դ��һ
class NewSpecficElementFst : public NewAbstractElement
{
public:
	NewSpecficElementFst() : NewAbstractElement() {}
	virtual ~NewSpecficElementFst() {}

public:
	virtual void showNewInfo() { cout << "First New Specific Info" << endl; }
};

// �¾�����Դ���
class NewSpecficElementSec : public NewAbstractElement
{
public:
	NewSpecficElementSec() : NewAbstractElement() {}
	virtual ~NewSpecficElementSec() {}

public:
	virtual void showNewInfo() { cout << "Second New Specific Info" << endl; }
};