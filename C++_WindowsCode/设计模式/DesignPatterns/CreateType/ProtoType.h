#pragma once
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
using std::vector;
using std::string;
using std::cout;
using std::endl;

// ԭ��ģʽ
class AbstractProtoType
{
public:
	virtual ~AbstractProtoType() {}

public:
	virtual void setTitle(const string& title) = 0;
	virtual string getTitle() = 0;

	virtual void setInfo(const string& question) = 0;
	virtual string getInfo() = 0;

	// ԭ��ģʽ��������¡��������ɵ�ǰ�����Ŀ���
	virtual AbstractProtoType* clone() = 0;

protected:
	string m_title;
	string m_Info;
};

class FirstSpecificProtoType : public AbstractProtoType
{
public:
	FirstSpecificProtoType() : AbstractProtoType() {}
	virtual ~FirstSpecificProtoType() { }

public:
	virtual void setTitle(const string& title) { m_title = title; }
	virtual string getTitle() { return m_title; }

	virtual void setInfo(const string& info) { m_Info = info; }
	virtual string getInfo() { return m_Info; }

	virtual AbstractProtoType* clone();
};

class SecondSpecificProtoType : public AbstractProtoType
{
public:
	SecondSpecificProtoType() : AbstractProtoType() {}
	virtual ~SecondSpecificProtoType() { }

public:
	virtual void setTitle(const string& title) { m_title = title; }
	virtual string getTitle() { return m_title; }

	virtual void setInfo(const string& info) { m_Info = info; }
	virtual string getInfo() { return m_Info; }

	virtual AbstractProtoType* clone();
};

// ��¡�������ýӿڣ����󻯣���ͬΪÿһ�����඼����дһ�ݵ��ú���
void ShowProtoType(AbstractProtoType* pAbstractProtoType);
void SetInfo(AbstractProtoType* pAbstractProtoType, const vector<string>& infoVec);

// ԭ��ģʽ���Ժ���
void ProtoTypeTestDemo();