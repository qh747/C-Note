#include "QuickSort.h"

/*��������																			**/
void funcCallQuickSort()
{
	int testArray[5] = { 0, 8, 2, 7, 4 };
	int arraySize = sizeof(testArray) / sizeof(testArray[0]);

	/*��ӡ����ǰ������																**/
	cout << "Before Sort. Array: ";
	for (int i = 0; i < arraySize; ++i)
		cout << testArray[i] << " ";
	cout << endl;

	/*��������																		**/
	int startPos = 0;
	int endPos = arraySize - 1;
	funcQuickSort(testArray, startPos, endPos);

	/*��ӡ����������																**/
	cout << "After Sort.  Array: ";
	for (int i = 0; i < arraySize; ++i)
		cout << testArray[i] << " ";
	cout << endl;
}

void funcQuickSort(int* pArray, int startPos, int endPos)
{
	if (startPos >= endPos)
		return;

	/*��ȡ��ǰѭ����ʼ�ͽ���ֵ														**/
	int curStartPos = startPos;
	int curEndPos = endPos;

	/*������ʼλ�õ�Ԫ��Ϊ��ǰѭ�����м�ֵ											**/
	int midVal = pArray[startPos]; 

	/*�������д����м�ֵ��Ԫ���ƶ������											**/
	while (curEndPos > curStartPos)
	{
		/*��ǰֵС���м�ֵ, �ƶ����м�ֵ���										**/
		if (pArray[curEndPos] < midVal)
		{
			pArray[curStartPos] = pArray[curEndPos];
			break;
		}
		else
			--curEndPos;
	}

	/*��������С���м�ֵ��Ԫ���ƶ����ұ�											**/
	while (curStartPos < curEndPos)
	{
		/*��ǰֵ�����м�ֵ, �ƶ����м�ֵ�ұ�										**/
		if (pArray[curStartPos] > midVal)
		{
			pArray[curEndPos] = pArray[curStartPos];
			break;
		}
		else
			++curStartPos;
	}

	/*�м�ֵ�ƶ�																	**/
	pArray[curStartPos] = midVal;
	int lstPos = curStartPos;

	/*�м�ֵ���Ԫ�صݹ�����														**/
	funcQuickSort(pArray, 0, lstPos - 1);

	/*�м�ֵ�Ҳ�Ԫ�صݹ�����														**/
	funcQuickSort(pArray, lstPos + 1, endPos);
}