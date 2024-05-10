#pragma once
#include <iostream>
#include <cstdlib>
using namespace std;

/*��̬���� (����: int)												**/
class DynamicArray
{
public:
	DynamicArray();													// ����
	DynamicArray(unsigned int capacity);							// ����
	~DynamicArray();												// ����

public:
	void					addVal(int val);						// ���Ԫ��
	void					insertVal(unsigned int pos, int val);	// ����Ԫ��
	void					modifyVal(unsigned int pos, int val);	// �޸�Ԫ��
	int						getVal(unsigned int pos);				// ��ȡԪ��
	void					delVal(unsigned int pos);				// �Ƴ�Ԫ��
	void					clear();								// �������
	unsigned int			getSize();								// ��ȡ����Ԫ�ظ���
	unsigned int			getCapacity();							// ��ȡ����������С

private:
	void					initArray(unsigned int capacity = 4);	// ��ʼ������
	bool					extendArray(unsigned int capacity);		// ��չ����

private:
	unsigned int			m_capacity;								// ��������
	unsigned int			m_size;									// ����Ԫ�ظ���
	int*					m_pArray;								// ����ָ��
};


