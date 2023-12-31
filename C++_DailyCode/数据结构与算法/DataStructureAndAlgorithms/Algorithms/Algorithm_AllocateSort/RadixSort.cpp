#include "RadixSort.h"

/*��������															**/
void funcCallRadixSort()
{
	/*��һ�����ݲ���												**/
	vector<int> fstIntVec = initializer_list<int>{ 1000, 300, 20, 10000, 5, 45, 789 ,856 };
	cout << "First Test Before Sort: ";
	for_each(fstIntVec.begin(), fstIntVec.end(), [](const int& val) { cout << val << " "; });
	cout << endl;

	funcRadixSort(fstIntVec);
	cout << "First Test After Sort: ";
	for_each(fstIntVec.begin(), fstIntVec.end(), [](const int& val) { cout << val << " "; });
	cout << endl << endl;

	/*�ڶ������ݲ���												**/
	vector<int> secIntVec = initializer_list<int>{ 60, 70, 101, 5, 2, 999, 1100, 0 };
	cout << "Second Test Before Sort: ";
	for_each(secIntVec.begin(), secIntVec.end(), [](const int& val) { cout << val << " "; });
	cout << endl;

	funcRadixSort(secIntVec);
	cout << "Second Test After Sort: ";
	for_each(secIntVec.begin(), secIntVec.end(), [](const int& val) { cout << val << " "; });
	cout << endl << endl;

	/*���������ݲ���												**/
	vector<int> trdIntVec = initializer_list<int>{ 1, 2, 5, 7, 2, 4, 6 ,8 };
	cout << "Third Test Before Sort: ";
	for_each(trdIntVec.begin(), trdIntVec.end(), [](const int& val) { cout << val << " "; });
	cout << endl;

	funcRadixSort(trdIntVec);
	cout << "Third Test After Sort: ";
	for_each(trdIntVec.begin(), trdIntVec.end(), [](const int& val) { cout << val << " "; });
	cout << endl << endl;
}

void funcRadixSort(vector<int>& sortVec)
{
	int size = sortVec.size();
	if (size < 2)
		return;

	/*��ȡ���ֵ																	**/
	int maxVal = -1;
	for (int i = 0; i < size; ++i)
	{
		if (maxVal < sortVec[i])
			maxVal = sortVec[i];
	}
	
	/*��ȡ���ֵ��λ��																**/
	int maxPos = 0;
	while (maxVal > 0)
	{
		++maxPos;
		maxVal /= 10;
	}

	/*�����ֵ��λ������ѭ���ܹ���Ҫ���ж��ٴ�										**/
	int base = 1;
	while (maxPos--)
	{
		/*��¼Ԫ�س��ֵĴ���														**/
		vector<int> countVec(10, 0);
		for (int i = 0; i < size; ++i)
		{
			int index = sortVec[i] / base % 10;
			++countVec[index];
		}

		/*�����ϵ�Ԫ�ص���ʼλ�úͳ��ִ����Ƶ���ǰԪ�ص���ʼλ��					**/
		vector<int> startVec(11, 0);
		for (int j = 1; j <= 10; ++j)
		{
			/*����: λ��Ϊ0����ʼλ��Ϊ0�����ִ���3��, ��λ��Ϊ1����ʼλ��Ϊ3		**/
			startVec[j] = countVec[j - 1] + startVec[j - 1];
		}

		/*����Ԫ�ص���ʼλ�ö�Ԫ�ؽ�������											**/
		vector<int> tmpValVec(size, 0);
		for (int k = 0; k < size; ++k)
		{
			/*��ȡ��ǰԪ�ص�ĩλ													**/
			int index = sortVec[k] / base % 10;

			/*����λ������ʼλ�ö�Ԫ������											**/
			tmpValVec[startVec[index]] = sortVec[k];

			/*��ǰλ������ʼλ������ƶ�1λ											**/
			++startVec[index];
		}

		/*����������õ�Ԫ�ؽ��и�ֵ												**/
		for (int index = 0; index < size; ++index)
		{
			sortVec[index] = tmpValVec[index];
		}

		/*��������10��																**/
		base *= 10;
	}
}