#pragma once
#include "CreateElement.h"

// �򵥹���ģʽ
class SimpleFactory
{
public:
	static AbstractElement* createElement(const string& name);
};

// �򵥹���ģʽ���Ժ���
void SimpleFactoryTestDemo();	