#pragma once
#include <iostream>
using std::cout;
using std::endl;

// ����ʽ����ģʽ
class HungrySingleton
{
public:
	static HungrySingleton* getInstance();

public:
	void setCount(int count) { m_count = count; }
	int getCount() { return m_count; }

private:
	HungrySingleton() { m_count = 0; }
	~HungrySingleton() { cout << "Instance Release Done." << endl; }

private:
	static HungrySingleton* pInstance;
	int m_count;

private:
	class HungrySingletonRelease
	{
	public:
		~HungrySingletonRelease();
	};
};

// ����ʽ����ģʽ���Ժ���
void HungrySingletonTestDemo();