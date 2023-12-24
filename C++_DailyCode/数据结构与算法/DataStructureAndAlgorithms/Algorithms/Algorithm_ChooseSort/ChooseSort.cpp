#include "ChooseSort.h"

/*ѡ������															**/
void funcCallChooseSort()
{
	/*��һ�����ݲ���												**/
	vector<int> fstIntVec = initializer_list<int>{1, 3, 2, 10, 5, 4, 7 ,8};
	cout << "First Test Before Sort: ";
	for_each(fstIntVec.begin(), fstIntVec.end(), [](const int& val){ cout << val << " "; });
	cout << endl;

	funcChooseSort(fstIntVec);
	cout << "First Test After Sort: ";
	for_each(fstIntVec.begin(), fstIntVec.end(), [](const int& val) { cout << val << " "; });
	cout << endl << endl;

	/*�ڶ������ݲ���												**/
	vector<int> secIntVec = initializer_list<int>{ 6, 7, 1, 5, 2, 9, 11 ,0 };
	cout << "Second Test Before Sort: ";
	for_each(secIntVec.begin(), secIntVec.end(), [](const int& val) { cout << val << " "; });
	cout << endl;

	funcChooseSort(secIntVec);
	cout << "Second Test After Sort: ";
	for_each(secIntVec.begin(), secIntVec.end(), [](const int& val) { cout << val << " "; });
	cout << endl << endl;

	/*���������ݲ���												**/
	vector<int> trdIntVec = initializer_list<int>{ 1, 3, 5, 7, 2, 4, 6 ,8 };
	cout << "Third Test Before Sort: ";
	for_each(trdIntVec.begin(), trdIntVec.end(), [](const int& val) { cout << val << " "; });
	cout << endl;

	funcChooseSort(trdIntVec);
	cout << "Third Test After Sort: ";
	for_each(trdIntVec.begin(), trdIntVec.end(), [](const int& val) { cout << val << " "; });
	cout << endl << endl;
}

void funcChooseSort(vector<int>& sortVec)
{
	int size = sortVec.size();
	if (size < 2)
		return;

	for (int i = 0; i < size; ++i)
	{
		int curSortIndex = i;
		for (int j = i; j < size; ++j)
		{
			/*�ҵ�����ѭ����ֵ��С���������						**/
			if (sortVec[j] < sortVec[curSortIndex])
				curSortIndex = j;
		}

		/*��������ѭ����ֵ��С��������ź͵�ǰѭ����������ŵ�ֵ	**/
		if (i != curSortIndex)
			swap(sortVec[i], sortVec[curSortIndex]);
	}
}