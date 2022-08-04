#pragma once
#include <functional>
#include <memory>
#include <map>
#include "ResourceClass.h"
using namespace std;

/*BASIC_RESOURCE_TYPEΪ����    **/
template <typename BASIC_RESOURCE_TYPE>	
class IocContainer
{
public:
	IocContainer() { }
	~IocContainer() { }

public:
	/*INHERIT_RESOURCEΪ�����������    **/
	template <typename INHERIT_RESOURCE_TYPE>	
	void registerType(string strKey)
	{
		/*������������ָ��������Ĺ��캯������ͨ��new����һ������    **/
		function<BASIC_RESOURCE_TYPE* ()> func = []() { return new INHERIT_RESOURCE_TYPE(); };
		/*ע���������������ƺʹ���������ָ�����ĺ���    **/
		innerRegisterType(strKey, func);
	}

	shared_ptr<BASIC_RESOURCE_TYPE> resolve(string strKey)
	{
		/*����������ָ�����    **/
		return shared_ptr<BASIC_RESOURCE_TYPE>(innerResolve(strKey));
	}

private:
	void innerRegisterType(string strKey, function<BASIC_RESOURCE_TYPE* ()> funcValue)
	{
		/*��������������ͱ�ʶ�Ƿ�ע���    **/
		if (m_containMap.end() == m_containMap.find(strKey))
			m_containMap.insert(make_pair(strKey, funcValue));
	}

	BASIC_RESOURCE_TYPE* innerResolve(string strKey)
	{
		typename map<string, function<BASIC_RESOURCE_TYPE* ()>>::iterator iter = m_containMap.find(strKey);
		if (m_containMap.end() == iter)
			return NULL;
		else
			return iter->second();	/*��()��ֱ��ͨ�����ú����������������    **/
	}

private:
	/*keyΪ���Ψһ��ʶ����������    **/
	/*valueΪnew�����ĺ���    **/
	map<string, function<BASIC_RESOURCE_TYPE* ()>> m_containMap;
};
