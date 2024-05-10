#pragma once
#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

// �����
class AbstractLayer
{
public:
	virtual ~AbstractLayer() {}
	virtual string doService(const string& data) = 0;
};

// �ײ㹦��ʵ�ֲ�
class ToUpperBottomLayer : public AbstractLayer
{
public:
	virtual ~ToUpperBottomLayer() {}
	virtual string doService(const string& data);
};

class ToLowerBottomLayer : public AbstractLayer
{
public:
	virtual ~ToLowerBottomLayer() {}
	virtual string doService(const string& data);
};

// �ϲ㹦�ܵ��ò�
void DisplayFuncTopLayer(AbstractLayer* pProcMethod, const string& data);

// ������תԭ����Ժ���
void RelyOnInersionPrincipleTestDemo();
