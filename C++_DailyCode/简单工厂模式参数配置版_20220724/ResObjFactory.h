#pragma once
#include <map>
#include "ResObjClass.h" 
using std::map;
using std::make_pair;
typedef void* (*objCreateFunc)();	/*��Դ������캯��    **/

class ResObjCreateFactory
{
public:
	static void registerClass(const string& className, objCreateFunc objCreateFuncPtr)
	{
		/*������ֻ����ע��һ��    **/
		if (getObjMap().end() == getObjMap().find(className))
		{
			getObjMap().insert(make_pair(className, objCreateFuncPtr));
		}
	}

	static void* createObject(const string& className)
	{
		AbstractResObjClass* resObjPtr = NULL;
		if (getObjMap().end() == getObjMap().find(className))
		{
			return NULL;
		}
		else
		{
			/*�Ӵ���������mapӳ����еļ�ֵ���ҵ���������ָ�룬ͨ������ָ��������ҵ�������ͨ��������������    **/
			resObjPtr = static_cast<AbstractResObjClass*>((*(getObjMap().find(className)->second))());
			return resObjPtr;
		}
	}

private:
	inline static map<string, objCreateFunc>& getObjMap()
	{
		/*��Դ������������ӳ�亯��    **/
		static map<string, objCreateFunc> objMap;
		return objMap;
	}

};