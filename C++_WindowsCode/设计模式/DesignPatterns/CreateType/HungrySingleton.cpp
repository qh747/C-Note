#include "HungrySingleton.h"

// ����ʽ����ģʽ�����ڳ�������ǰ����
HungrySingleton* HungrySingleton::pInstance = new HungrySingleton();

HungrySingleton* HungrySingleton::getInstance()
{
	static HungrySingletonRelease relsObj;
	return pInstance;
}

HungrySingleton::HungrySingletonRelease::~HungrySingletonRelease()
{
	if (nullptr != pInstance)
		delete pInstance;
}

void HungrySingletonTestDemo()
{
	HungrySingleton* pInc = HungrySingleton::getInstance();
	pInc->setCount(10);
	cout << "Current: " << pInc->getCount() << endl;
}