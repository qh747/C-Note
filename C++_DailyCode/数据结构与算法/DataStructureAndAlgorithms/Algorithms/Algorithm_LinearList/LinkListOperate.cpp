#include "LinkListOperate.h"

/*����ת													**/
void funcLinkListReverse()
{
	/*��������												**/
	LinkListNode_dt headerNode(0, NULL);
	LinkListNode_dt* pHeader = &headerNode;
	for (int i = 1; i <= 10; ++i)
	{
		LinkListNode_dt* pCur = new LinkListNode_dt(i, NULL);
		pHeader->pNext = pCur;
		pHeader = pHeader->pNext;

		++headerNode.iVal;
	}

	/*��ӡ����												**/
	cout << "Before Reverse. Link List: ";
	LinkListNode_dt* pPrintBefore = headerNode.pNext;
	for (int i = 0; i < headerNode.iVal; ++i)
	{
		cout << pPrintBefore->iVal << " ";
		pPrintBefore = pPrintBefore->pNext;
	}
	cout << endl;

	/*����ת												**/
	LinkListNode_dt* pPrevious = headerNode.pNext;
	LinkListNode_dt* pCurrent = pPrevious->pNext;
	LinkListNode_dt* pTemp = NULL;
	while (NULL != pCurrent)
	{
		pTemp = pCurrent->pNext;							// �ݴ浱ǰ�ڵ����һ���ڵ��ַ

		pCurrent->pNext = pPrevious;						// ��ת��ǰ�ڵ�ָ��
		pPrevious = pCurrent;								// ǰһ���ڵ�ǰ������ǰ�ڵ�
		pCurrent = pTemp;									// ��ǰ�ڵ�ָǰ������һ���ڵ�
	}
	headerNode.pNext = pPrevious;							// ��ǰ�ڵ��Ѿ�ָ�����һ���ڵ����һ��λ��, Ϊ��, ���ͷ�ڵ��ָ����ָ��ǰһ���ڵ�

	/*��ӡ����												**/
	cout << "After Reverse. Link List: ";
	LinkListNode_dt* pPrintAfter = headerNode.pNext;
	for (int i = 0; i < headerNode.iVal; ++i)
	{
		cout << pPrintAfter->iVal << " ";
		pPrintAfter = pPrintAfter->pNext;
	}
	cout << endl;

	/*��������												**/
	LinkListNode_dt* pDestory = headerNode.pNext;
	LinkListNode_dt* pTempSave = NULL;
	for (int i = 0; i < headerNode.iVal; ++i)
	{
		pTempSave = pDestory->pNext;
		delete pDestory;
		
		pDestory = pTempSave;
	}
}