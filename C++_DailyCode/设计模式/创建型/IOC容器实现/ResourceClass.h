#pragma once
#include <iostream>
#include <string>

/*����    **/
struct AbstractClass
{
public:
	AbstractClass() { }
	virtual ~AbstractClass() { std::cout << "AbstractClass Destory." << std::endl; }

public:
	virtual void showStr(const std::string& str) = 0;
};

/*��һ��������    **/
class FirstInheritClass : public AbstractClass
{
public:
	FirstInheritClass() { }
	virtual ~FirstInheritClass() { std::cout << "FirstInheritClass Destory." << std::endl; }

public:
	virtual void showStr(const std::string& str)
	{
		std::cout << "FirstInheritClass::showStr(), Str: " << str << std::endl;
	}
};

/*�ڶ���������    **/
class SecondInheritClass : public AbstractClass
{
public:
	SecondInheritClass() { }
	virtual ~SecondInheritClass() { std::cout << "SecondInheritClass Destory." << std::endl; }

public:
	virtual void showStr(const std::string& str)
	{
		std::cout << "SecondInheritClass::showStr(), Str: " << str << std::endl;
	}
};