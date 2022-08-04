#pragma once
#include <iostream>
#include <cstring>
#include <string>
using std::cout;
using std::endl;
using std::string;

/*�������    **/
class AbstractResObjClass
{
public:
	inline virtual void showData(const string& data) = 0;
};

/*һ��������    **/
class NumberOneResObjClass : public AbstractResObjClass
{
public:
	inline virtual void showData(const string& data)
	{
		cout << "In Number One Class. Data Is : " << data << endl;
	}
};

/*����������    **/
class NumberTwoResObjClass : public AbstractResObjClass
{
public:
	inline virtual void showData(const string& data)
	{
		cout << "In Number Two Class. Data Is : " << data << endl;
	}
};