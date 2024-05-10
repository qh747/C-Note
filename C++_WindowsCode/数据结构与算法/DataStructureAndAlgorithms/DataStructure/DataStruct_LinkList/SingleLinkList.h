#pragma once
#include <iostream>
#include <cstdlib>
using namespace std;

/*�������� (����: int)														**/
class SingleLinkList
{
public:
	typedef struct DATA_TYPE_LINK_NODE
	{
		int								iData;								// ����
		DATA_TYPE_LINK_NODE*			pNext;								// �¸��ڵ�ĵ�ַ
	}LinkNode_dt;

public:
	SingleLinkList();														// ����
	~SingleLinkList();														// ����

public:
	void								pushFront(int data);				// ���Ԫ��(�ײ�)
	void								pushBack(int data);					// ���Ԫ��(β��)
	void								insert(size_t index, int data);		// ����Ԫ��
	void								erase(size_t index);				// �Ƴ�Ԫ��
	int&								at(size_t index);					// ��ȡԪ��(���޸�)
	const int&							at(size_t index) const;				// ��ȡԪ��(�����޸�)
	size_t								size();								// ��ȡ������
	void								clear();							// �������

private:
	LinkNode_dt*						creatNode(int data);				// �����ڵ�
	void								initLinkList();						// ��ʼ������
	void								releaseLinkList();					// �ͷ�����
	void								destoryLinkList();					// ��������

private:
	LinkNode_dt*						m_pHeadNode;						// �����׽ڵ� 
};