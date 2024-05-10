#pragma once
#include "CreateElement.h"

// ��������ģʽ
class AbstractFactoryMethod
{
public:
	virtual ~AbstractFactoryMethod() {}
	virtual AbstractElement* createElement() = 0;
};

class FristFactoryMethod : public AbstractFactoryMethod
{
public:
	virtual ~FristFactoryMethod() {}
	virtual AbstractElement* createElement();
};

class SecondFactoryMethod : public AbstractFactoryMethod
{
public:
	virtual ~SecondFactoryMethod() {}
	virtual AbstractElement* createElement();
};

// ��������ģʽ���Ժ���
void FactoryMethodTestDemo();