#include "InsertSearch.h"

/*��ֵ����												**/
void funcCallInsertSort()
{
	/*��һ�����ݲ���									**/
	vector<int> fstIntVec = initializer_list<int>{ 1000, 300, 20, 10000, 5, 45, 789 ,856 };
	funcChooseSort(fstIntVec);
	cout << "First Test Vec: ";
	for_each(fstIntVec.begin(), fstIntVec.end(), [](const int& val) { cout << val << " "; });
	cout << endl << "Val " << 45 << " In ";

	int fstValIndex = funcInsertSort(fstIntVec, 45);
	cout << fstValIndex << endl << endl;

	/*�ڶ������ݲ���												**/
	vector<int> secIntVec = initializer_list<int>{ 60, 70, 101, 5, 2, 999, 1100, 0 };
	funcChooseSort(secIntVec);
	cout << "Second Test Vec: ";
	for_each(secIntVec.begin(), secIntVec.end(), [](const int& val) { cout << val << " "; });
	cout << endl << "Val " << 1100 << " In ";

	int secValIndex = funcInsertSort(secIntVec, 1100);
	cout << secValIndex << endl << endl;

	/*���������ݲ���												**/
	vector<int> trdIntVec = initializer_list<int>{ 1, 2, 5, 7, 2, 4, 6 ,8 };
	funcChooseSort(trdIntVec);
	cout << "Third Test Vec: ";
	for_each(trdIntVec.begin(), trdIntVec.end(), [](const int& val) { cout << val << " "; });
	cout << endl << "Val " << 1 << " In ";

	int trdValIndex = funcInsertSort(trdIntVec, 1);
	cout << trdValIndex << endl << endl;
}

int funcInsertSort(vector<int>& vec, int val)
{
	if (vec.empty())
		return -1;

	int startPos = 0;
	int endPos = vec.size() - 1;
	
	/*�м�λ��Ϊ����ʼλ�� + ��ǰԪ������������������λ�õı��� * �����е�Ԫ�ظ���						**/
	int midPos = startPos + ((val - vec[startPos]) / (vec[endPos] - vec[startPos])) * (endPos - startPos);

	while (startPos <= endPos)
	{
		if (vec[midPos] == val)
			return midPos;
		else if (vec[midPos] > val)
			endPos = midPos - 1;
		else
			startPos = midPos + 1;

		/*�ҵ���ǰ�������и���Ԫ�صı�����Χ															**/
		midPos = startPos + ((val - vec[startPos]) / (vec[endPos] - vec[startPos])) * (endPos - startPos);
	}

	/*��ǰ������δ�ҵ�����Ԫ��																			**/
	return -1;
}