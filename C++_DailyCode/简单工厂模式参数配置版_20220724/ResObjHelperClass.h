#pragma once
#include "ResObjFactory.h"

/*������İ����࣬�Զ�������ʽ������ʹ��������    **/			     
#define REG_CLASS(class_Name)                                             \
class class_Name##HelperClass                                             \
{                                                                         \
public:                                                                   \
	class_Name##HelperClass()                                             \
	{                                                                     \
		ResObjCreateFactory::registerClass(#class_Name, createResObject); \
	}								                                      \
									                                      \
public:								                                      \
	static void* createResObject()		                                  \
	{								                                      \
		return new class_Name;		                                      \
	}	                                                                  \
};									                                      \
                                                                          \
class_Name##HelperClass class_Name##HelperObj;       