#pragma once
#include <iostream>
using namespace std;

/*����ڵ�ṹ												**/
typedef struct DATA_TYPE_LINK_LIST_NODE
{
	int								iVal;					// ������
	DATA_TYPE_LINK_LIST_NODE*		pNext;					// ָ����

	DATA_TYPE_LINK_LIST_NODE()
	{
		iVal = -1;
		pNext = NULL;
	}
	DATA_TYPE_LINK_LIST_NODE(int val, DATA_TYPE_LINK_LIST_NODE* pNode)
	{
		iVal = val;
		pNext = pNode;
	}
}LinkListNode_dt;


/*����ת													**/
void	funcLinkListReverse();