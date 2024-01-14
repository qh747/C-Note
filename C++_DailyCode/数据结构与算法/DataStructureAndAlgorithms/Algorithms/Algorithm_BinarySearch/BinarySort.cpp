#include "BinarySearch.h"

/*���ֲ���												**/
void funcCallBinarySort()
{
	/*��һ�����ݲ���									**/
	vector<int> fstIntVec = initializer_list<int>{ 1000, 300, 20, 10000, 5, 45, 789 ,856 };
	funcChooseSort(fstIntVec);
	cout << "First Test Vec: ";
	for_each(fstIntVec.begin(), fstIntVec.end(), [](const int& val) { cout << val << " "; });
	cout << endl << "Val " << 45 << " In ";

	int fstValIndex = funcBinarySort(fstIntVec, 45);
	cout << fstValIndex << endl << endl;

	/*�ڶ������ݲ���												**/
	vector<int> secIntVec = initializer_list<int>{ 60, 70, 101, 5, 2, 999, 1100, 0 };
	funcChooseSort(secIntVec);
	cout << "Second Test Vec: ";
	for_each(secIntVec.begin(), secIntVec.end(), [](const int& val) { cout << val << " "; });
	cout << endl << "Val " << 1100 << " In ";

	int secValIndex = funcBinarySort(secIntVec, 1100);
	cout << secValIndex << endl << endl;

	/*���������ݲ���												**/
	vector<int> trdIntVec = initializer_list<int>{ 1, 2, 5, 7, 2, 4, 6 ,8 };
	funcChooseSort(trdIntVec);
	cout << "Third Test Vec: ";
	for_each(trdIntVec.begin(), trdIntVec.end(), [](const int& val) { cout << val << " "; });
	cout << endl << "Val " << 1 << " In ";

	int trdValIndex = funcBinarySort(trdIntVec, 1);
	cout << trdValIndex << endl << endl;
}

int funcBinarySort(vector<int>& vec, int val)
{
	if (vec.empty())
		return -1;

	int startPos = 0;
	int endPos = vec.size() - 1;

	int midPos = (startPos + endPos) / 2;
	while (startPos <= endPos)
	{
		if (vec[midPos] == val)
		{
			/*�ҵ���ǰ�����������λ��					**/
			return midPos;
		}
		else if (val > vec[midPos])
		{
			/*�м�ֵ������С������ʼλ������ƶ�		**/
			startPos = midPos + 1;
		}
		else
		{
			/*�м�ֵ�����ݴ󣬽���ʼλ������ƶ�		**/
			endPos = midPos - 1;
		}

		midPos = (startPos + endPos) / 2;
	}

	return -1;
}