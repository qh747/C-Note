#pragma once
#include <iostream>
#include <string>
#include <sstream>
using std::cout;
using std::endl;
using std::string;
using std::stringstream;

// ��Ҫ�������
class CalculateClass
{
public:		
	virtual ~CalculateClass() {}
	virtual int addValue(int fstVal, int secVal) { return fstVal + secVal; }
};

class ShowValueClass
{
public:
	virtual void showValue(const string& val) { cout << "Val: " << val << endl; }
};

// ����������ģʽ
class CalculateClassAdapter : public CalculateClass, public ShowValueClass
{
public:		
	virtual ~CalculateClassAdapter() {}
	virtual int  addValue(int val) { return this->CalculateClass::addValue(val, 0); }
	virtual int  addValue(int fstVal, int secVal, int thrVal) { return this->CalculateClass::addValue(fstVal, secVal + thrVal); }
	virtual void showValue(const int val);
};

// ��������ģʽ
class CalculateObjAdapter : public CalculateClass
{
public:
	virtual ~CalculateObjAdapter() {}
	virtual int  addValue(int val) { return this->CalculateClass::addValue(val, 0); }
	virtual int  addValue(int fstVal, int secVal, int thrVal) { return this->CalculateClass::addValue(fstVal, secVal + thrVal); }
	virtual void showValue(const int val);

private:
	ShowValueClass m_showValue;
};

// ��������ģʽ���Ժ���
void ClassAdapterTestDemo();

// ����������ģʽ���Ժ���
void ObjAdapterTestDemo();