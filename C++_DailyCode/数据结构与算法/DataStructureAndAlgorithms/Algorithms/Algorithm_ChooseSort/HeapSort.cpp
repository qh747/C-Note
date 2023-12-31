#include "HeapSort.h"

/*������															**/
void funcCallHeapSort()
{
	/*��һ�����ݲ���												**/
	vector<int> fstIntVec = initializer_list<int>{ 1, 3, 2, 10, 5, 4, 7 ,8 };
	cout << "First Test Before Sort: ";
	for_each(fstIntVec.begin(), fstIntVec.end(), [](const int& val) { cout << val << " "; });
	cout << endl;

	funcHeapSort(fstIntVec);
	cout << "First Test After Sort: ";
	for_each(fstIntVec.begin(), fstIntVec.end(), [](const int& val) { cout << val << " "; });
	cout << endl << endl;

	/*�ڶ������ݲ���												**/
	vector<int> secIntVec = initializer_list<int>{ 6, 7, 1, 5, 2, 9, 11 ,0 };
	cout << "Second Test Before Sort: ";
	for_each(secIntVec.begin(), secIntVec.end(), [](const int& val) { cout << val << " "; });
	cout << endl;

	funcHeapSort(secIntVec);
	cout << "Second Test After Sort: ";
	for_each(secIntVec.begin(), secIntVec.end(), [](const int& val) { cout << val << " "; });
	cout << endl << endl;

	/*���������ݲ���												**/
	vector<int> trdIntVec = initializer_list<int>{ 1, 2, 5, 7, 2, 4, 6 ,8 };
	cout << "Third Test Before Sort: ";
	for_each(trdIntVec.begin(), trdIntVec.end(), [](const int& val) { cout << val << " "; });
	cout << endl;

	funcHeapSort(trdIntVec);
	cout << "Third Test After Sort: ";
	for_each(trdIntVec.begin(), trdIntVec.end(), [](const int& val) { cout << val << " "; });
	cout << endl << endl;
}

void funcHeapAdjust(vector<int>& vec, int curSize, int curIndex)
{
	/*������Ϊ��ǰ��ֵ����Ԫ������Ϊ���������Ԫ������					**/
	int curBiggestIndex = curIndex;

	/*��ȡ��ǰԪ�ص����ӡ��Һ��ӽڵ������								**/
	int leftSonIndex = curIndex * 2 + 1;
	int rightSonIndex = curIndex * 2 + 2;

	/*���ֵԪ�������Ƚ��Լ���ȡ											**/
	if (leftSonIndex < curSize && vec[curBiggestIndex] < vec[leftSonIndex])
	{
		/*���ӽڵ�����δ����Խ�� && ���Ԫ������ < ���ӽڵ�����			**/
		curBiggestIndex = leftSonIndex;
	}

	if (rightSonIndex < curSize && vec[curBiggestIndex] < vec[rightSonIndex])
	{
		/*���ӽڵ�����δ����Խ�� && ���Ԫ������ < ���ӽڵ�����			**/
		curBiggestIndex = rightSonIndex;
	}

	/*���ֵ�ڵ�Ԫ�����������ı�											**/
	if (curBiggestIndex != curIndex)
	{
		swap(vec[curIndex], vec[curBiggestIndex]);

		/*�ݹ����															**/
		funcHeapAdjust(vec, curSize, curBiggestIndex);
	}
}

void funcHeapSort(vector<int>& sortVec)
{
	int size = sortVec.size();
	if (size < 2)
		return;

	/*�����ѣ������һ����Ҷ�ӽڵ㿪ʼ������								**/
	for (int i = (size /2 - 1); i >= 0; --i)
	{
		funcHeapAdjust(sortVec, size, i);
	}

	/*�ѵ���																**/
	for (int j = size - 1; j > 0; --j)
	{
		/*�����Ѻ͵����Ѻ�, 0������Ԫ��Ϊ���������ֵ, ��ĩβֵ���н���		**/
		swap(sortVec[0], sortVec[j]);

		/*�Ӷ����Ƴ�ĩβԪ��, ����ʣ��Ԫ�����½��жѵ���					**/
		funcHeapAdjust(sortVec, --size, 0);
	}
}