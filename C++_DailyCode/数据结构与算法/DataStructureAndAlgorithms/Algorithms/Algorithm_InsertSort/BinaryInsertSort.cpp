#include "BinaryInsertSort.h"

/*���ֲ�������												**/
void funcCallBinaryInsertSort()
{
	/*��һ�����ݲ���												**/
	vector<int> fstIntVec = initializer_list<int>{ 1, 2, 3, 4, 5, 6, 7 ,8 };
	cout << "First Test Before Sort: ";
	for_each(fstIntVec.begin(), fstIntVec.end(), [](const int& val) { cout << val << " "; });
	cout << endl;

	funcBinaryInsertSort(fstIntVec);
	cout << "First Test After Sort: ";
	for_each(fstIntVec.begin(), fstIntVec.end(), [](const int& val) { cout << val << " "; });
	cout << endl << endl;

	/*�ڶ������ݲ���												**/
	vector<int> secIntVec = initializer_list<int>{ 6, 7, 1, 5, 2, 9, 11 ,0 };
	cout << "Second Test Before Sort: ";
	for_each(secIntVec.begin(), secIntVec.end(), [](const int& val) { cout << val << " "; });
	cout << endl;

	funcBinaryInsertSort(secIntVec);
	cout << "Second Test After Sort: ";
	for_each(secIntVec.begin(), secIntVec.end(), [](const int& val) { cout << val << " "; });
	cout << endl << endl;

	/*���������ݲ���												**/
	vector<int> trdIntVec = initializer_list<int>{ 1, 3, 5, 7, 2, 4, 6 ,8 };
	cout << "Third Test Before Sort: ";
	for_each(trdIntVec.begin(), trdIntVec.end(), [](const int& val) { cout << val << " "; });
	cout << endl;

	funcBinaryInsertSort(trdIntVec);
	cout << "Third Test After Sort: ";
	for_each(trdIntVec.begin(), trdIntVec.end(), [](const int& val) { cout << val << " "; });
	cout << endl << endl;
}

void funcBinaryInsertSort(vector<int>& sortVec)
{
	int size = sortVec.size();
	if (size < 2)
		return;

	for (int i = 1; i < size; ++i)
	{
		int sortValue = sortVec[i];
		int j = i - 1;
		if (sortValue < sortVec[j])
		{
			/*ʹ�ö��ֲ��ҷ���ȡԪ���ƶ���ʼλ��					**/
			int binaryStartPos = 0;
			int binaryEndPos = i;
			int binaryMidPos = (binaryStartPos + binaryEndPos) / 2;
			while (binaryStartPos <= binaryEndPos)
			{
				if (sortValue < sortVec[binaryMidPos])
					binaryEndPos = binaryMidPos - 1;
				else
					binaryStartPos = binaryMidPos + 1;

				binaryMidPos = (binaryStartPos + binaryEndPos) / 2;
			}

			/*�ƶ��������Ԫ��, Ϊ��ǰδ�����Ԫ���ṩ����λ��		**/
			for (; j > binaryEndPos; --j)
			{
				sortVec[j + 1] = sortVec[j];
			}
			
			/*������Ԫ�ز���										**/
			sortVec[j + 1] = sortValue;
		}
	}
}