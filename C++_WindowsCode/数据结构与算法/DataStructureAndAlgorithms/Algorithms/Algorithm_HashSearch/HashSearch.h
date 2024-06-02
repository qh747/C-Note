#pragma once
#include <iostream>
#include <vector>
#include <ctime>
using std::cout;
using std::endl;
using std::vector;
using std::initializer_list;

/* ��ϣ�ڵ�											**/
typedef struct DATA_TYPE_HASH_NODE
{
	int						iIndex;					// Ԫ������
	int						iValue;					// Ԫ��ֵ
	DATA_TYPE_HASH_NODE*	pNext;					// �¸��ڵ�ĵ�ַ

	DATA_TYPE_HASH_NODE(int idx, int val) {
		iIndex = idx;
		iValue = val;
		pNext = nullptr;
	}

}HashNode_dt;

/* ��ϣ��											**/
class HashTable
{
public:
	HashTable(int primeNum = 13, int rebuildDeepth = 5);
	~HashTable();

public:
	void insert(int val);							// ����Ԫ��
	bool erase(int val);							// �Ƴ�Ԫ��
	void modify(int oldVal, int newVal);			// �޸�Ԫ��	
	bool search(int val);							// ����Ԫ��
	int size() { return m_size; }					// ��ȡԪ�ظ���

private:
	void destoryHashTable();						// ���ٹ�ϣ��
	void rebuildHashTable();						// �ؽ���ϣ��
	int  calcBiggerPrimeNum();						// ������������
	bool isPrime(int num);							// �жϲ���num�Ƿ�Ϊ����

private:
	vector<HashNode_dt*>	m_nodeVec;				// ��ϣ�ڵ�����
	int						m_primeNum;				// ����
	int						m_rebuildHashDeepth;	// ��ϣ���ؽ�����
	int						m_size;					// �ڵ����
};

/*��ϣ����											**/
void funcHashSearch();