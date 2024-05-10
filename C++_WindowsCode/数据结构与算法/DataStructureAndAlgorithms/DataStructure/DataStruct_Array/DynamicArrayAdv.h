#pragma once
#include <iostream>
#include <cstdlib>
using namespace std;

/*��̬����Ľ��� (����: int)														**/
class DynamicArrayAdv
{
public:
	typedef enum TYPE_ARRAY_SIZE
	{
		DFT_ARRAY_SIZE				= 8,											// Ĭ���������С
		SIMPLE_ARRAY_SIZE			= 64,											// ��׼�������С
		EXTEND_ARRAY_SIZE			= 512,											// ��չ�������С
	}ArraySize_t;

public:
	DynamicArrayAdv();
	~DynamicArrayAdv();

public:
	void							pushBack(int val);								// �������Ԫ��
	void							insert(size_t pos, int val);					// ��������Ԫ��
	void							erase(size_t pos);								// �Ƴ�����Ԫ��
	void							clear();										// �������

public:
	int&							operator[](size_t pos);							// ��ȡ����Ԫ��
	const int&						operator[](size_t pos) const;					// ��ȡ����Ԫ��

	int&							at(size_t pos);									// ��ȡ����Ԫ��
	const int&						at(size_t pos) const;							// ��ȡ����Ԫ��

public:
	size_t							size() { return m_arraySize; }					// ��ȡ����Ԫ�ظ���
	size_t							capacity() { return m_arrayCapacity; }			// ��ȡ��������

private:
	void							initArray();									// ��ʼ������
	void							extendArray(size_t size);						// ��������
	void							moveBack(size_t pos);							// ����Ԫ������ƶ�
	void							moveForward(size_t pos);						// ����Ԫ����ǰ�ƶ�

private:
	size_t							m_arraySize;									// ����Ԫ�ظ���
	size_t							m_arrayCapacity;								// ��������
	int*							m_pArray;										// ����ָ��
	int								m_arrayBuffer[DFT_ARRAY_SIZE];					// ���黺����
};