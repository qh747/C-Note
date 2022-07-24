#include <iostream>
#include <cstring>
#include <string>
using namespace std;

/*����ĺ������麯���Ƿ�ᱻ���า�ǲ���    **/
class TestBasicClass
{
/*��ͨ����    **/
public:
	void simpleShowValue(int val)
	{
		cout << "In Basic Class Simple Function, Int Type Value : " << val << endl;
	}

	void simpleShowValue(string val)
	{
		cout << "In Basic Class Simple Function, String Type Value : " << val << endl;
	}

/*�麯��    **/
public:
	virtual void virtualShowValue(int val)
	{
		cout << "In Basic Class Virtual Function, Int Type Value : " << val << endl;
	}

	virtual void virtualShowValue(string val)
	{
		cout << "In Basic Class Virtual Function, String Type Value : " << val << endl;
	}
};

class TestInheritClass :public TestBasicClass
{
public:
	using TestBasicClass::virtualShowValue;    /*����Effective C++�����Բ�������Ϊstring���麯���Ƿ�ᱻ����*/

/*��ͨ����    **/
public:
	void simpleShowValue(int val)	/*ֻ�̳в�������Ϊint�ĺ����������Ƿ�����ز���Ϊstring�����غ���    **/
	{
		cout << "In Herit Class Simple Function, Int Type Value : " << val << endl;
	}

/*�麯��    **/
public:
	virtual void virtualShowValue(int val)    /*ֻ�̳в�������Ϊint�ĺ����������Ƿ�����ز���Ϊstring�����غ���    **/
	{
		cout << "In Herit Class Virtual Function, Int Type Value : " << val << endl;
	}
};

int main()
{
	/*�����������ʽ����   **/
	TestInheritClass testInheritObj;
	testInheritObj.simpleShowValue(10);
	testInheritObj.virtualShowValue(20);
	testInheritObj.virtualShowValue("hello");

	/*����������ʽ����������ػ�������غ���    **/
	/*ʹ��using TestBasicClass::virtualShowValue�����غ������ᱻ����    **/
 
	/*����ָ������ʽ����    **/
	TestBasicClass* testInheritPtr = new TestInheritClass();
	testInheritPtr->simpleShowValue(100);
	testInheritPtr->simpleShowValue("Hello");
	testInheritPtr->virtualShowValue(200);
	testInheritPtr->virtualShowValue("Hello");

	/*����ָ����ʽ�����಻�����ػ�������غ���    **/

	system("pause");
	return 0;
}