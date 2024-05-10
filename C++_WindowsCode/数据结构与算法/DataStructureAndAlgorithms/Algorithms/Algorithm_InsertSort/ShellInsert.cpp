#include "ShellInsert.h"

/*ϣ����������												**/
void funcCallShellInsertSort()
{
	/*��һ�����ݲ���												**/
	vector<int> fstIntVec = initializer_list<int>{ 1, 2, 3, 4, 5, 6, 7 ,8 };
	cout << "First Test Before Sort: ";
	for_each(fstIntVec.begin(), fstIntVec.end(), [](const int& val) { cout << val << " "; });
	cout << endl;

	funcShellInsertSort(fstIntVec);
	cout << "First Test After Sort: ";
	for_each(fstIntVec.begin(), fstIntVec.end(), [](const int& val) { cout << val << " "; });
	cout << endl << endl;

	/*�ڶ������ݲ���												**/
	vector<int> secIntVec = initializer_list<int>{ 6, 7, 1, 5, 2, 9, 11 ,0 };
	cout << "Second Test Before Sort: ";
	for_each(secIntVec.begin(), secIntVec.end(), [](const int& val) { cout << val << " "; });
	cout << endl;

	funcShellInsertSort(secIntVec);
	cout << "Second Test After Sort: ";
	for_each(secIntVec.begin(), secIntVec.end(), [](const int& val) { cout << val << " "; });
	cout << endl << endl;

	/*���������ݲ���												**/
	vector<int> trdIntVec = initializer_list<int>{ 1, 3, 5, 7, 2, 4, 6 ,8 };
	cout << "Third Test Before Sort: ";
	for_each(trdIntVec.begin(), trdIntVec.end(), [](const int& val) { cout << val << " "; });
	cout << endl;

	funcShellInsertSort(trdIntVec);
	cout << "Third Test After Sort: ";
	for_each(trdIntVec.begin(), trdIntVec.end(), [](const int& val) { cout << val << " "; });
	cout << endl << endl;
}

void funcShellInsertSort(vector<int>& sortVec)
{
	int size = sortVec.size();
	if (size < 2)
		return;

	int increment = size / 2;

	/*ԭʼ���з���												**/
	for (int curIncr = increment; curIncr > 0; --curIncr)
	{
		/*ÿ�����������, ��ʼλ��Ϊ������������Ϊ[1]��Ԫ��		**/
		for (int i = curIncr; i < size; ++i)
		{
			if (sortVec[i] < sortVec[i - curIncr])				// �����е�һ�ε���ʱ, ������Ϊ[1]��Ԫ��������Ϊ[0]��Ԫ�رȽ�
			{
				int sortValue = sortVec[i];
				int j = i - curIncr;							// �����е�һ�ε���ʱ, ָ������Ϊ[0]��Ԫ��
				for (; j >= 0; j -= curIncr)
				{
					sortVec[j + curIncr] = sortVec[j];			// �����е�һ�ε���ʱ, ������Ϊ[0]��Ԫ�ؿ���������Ϊ[1]��λ��
				}
				sortVec[j + curIncr] = sortValue;				// �����е�һ�ε���ʱ, ������Ϊ[1]��Ԫ�ؿ���������Ϊ[0]��λ��
			}
		}
	}
}