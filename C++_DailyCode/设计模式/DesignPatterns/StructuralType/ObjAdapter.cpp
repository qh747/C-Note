#include "ObjAdapter.h"

void CalculateClassAdapter::showValue(const int val)
{
	stringstream ss;
	ss << val;
	this->ShowValueClass::showValue(ss.str());
}

void CalculateObjAdapter::showValue(const int val)
{
	stringstream ss;
	ss << val;
	m_showValue.showValue(ss.str());
}

void ClassAdapterTestDemo()
{
	// ͨ������������ʵ��һ������������������������������Լ���int���ͱ���������ʾ
	CalculateClassAdapter adapter;
	int res = adapter.addValue(10);
	adapter.showValue(res);

	res = adapter.addValue(10, 20, 30);
	adapter.showValue(res);
}

void ObjAdapterTestDemo()
{
	CalculateObjAdapter adapter;
	int res = adapter.addValue(100);
	adapter.showValue(res);

	res = adapter.addValue(100, 200, 300);
	adapter.showValue(res);
}

