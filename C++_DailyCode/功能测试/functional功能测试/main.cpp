#include <iostream>
#include <functional>
using namespace std;

/*�º���std::function���Ͷ��壬ָ�������int��int������ֵ��int�ĺ���    **/
typedef std::function<int(int, int)> MyFunction;

/*��ͨ����    **/
int addFunc(int fstNum, int secNum)
{
	return fstNum + secNum;
}

/*lambda���ʽ    **/
auto lambda = [](int fstNum, int secNum) {return fstNum + secNum; };

/*��������    **/
struct MyAddType
{
	int operator()(int fNum, int sNum)
	{
		return fNum + sNum;
	}
};

/*��������    **/
class MyAddClass
{
public:
	int myAddFunc(int fNum, int sNum)
	{
		return fNum + sNum;
	}
};

int main()
{
	MyFunction funcObj;

	funcObj = addFunc;
	cout << "ָ����ͨ����" << endl;
	cout << funcObj(10, 20) << endl;

	funcObj = lambda;
	cout << "ָ��lambda" << endl;
	cout << funcObj(10, 20) << endl;

	funcObj = MyAddType();
	cout << "ָ��������" << endl;
	cout << funcObj(10, 20) << endl;

	MyAddClass myAddObj;
	funcObj = std::bind(&MyAddClass::myAddFunc, &myAddObj, 10,20);
	cout << "ָ���Ա����" << endl;
	cout << funcObj(10, 20) << endl;

	system("pause");
	return 0;
}