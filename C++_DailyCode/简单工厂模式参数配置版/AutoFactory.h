#pragma once
#include "ResObjHelperClass.h"

/*ע��һ����Դ��    **/
REG_CLASS(NumberOneResObjClass)

class AutoFactory
{
public:
	static AbstractResObjClass* createOne()
	{
		/*����һ����Դ��    **/
		return static_cast<AbstractResObjClass *>(ResObjCreateFactory::createObject("NumberOneResObjClass"));
	}
};

/*֮�������Ҫ����������Դ�ֻ࣬��Ҫ�޸�עע����Դ��ĺ궨��ʹ��������Ĳ���    **/