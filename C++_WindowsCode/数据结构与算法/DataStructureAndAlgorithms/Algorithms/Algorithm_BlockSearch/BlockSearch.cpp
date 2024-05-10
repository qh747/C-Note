#include "BlockSearch.h"

/*�ֿ����												**/
void funcCallBlockSort()
{
	vector<int> intVec = initializer_list<int>{ 0, 3, 2, 5,  9, 6, 7 ,8,  45, 10, 32, 27,  78, 91, 73, 99 };
	vector<Index_dt> idxVec = initializer_list<Index_dt>{ Index_dt(5, 0), Index_dt(9, 4), Index_dt(45, 8), Index_dt(99, 12) };

	cout << "Test Vec: ";
	for_each(intVec.begin(), intVec.end(), [](const int& val) { cout << val << " "; });
	cout << endl;

	/*��һ�����ݲ���												**/
	cout << "Val " << 32 << " In ";
	int fstValIndex = funcBlockSort(intVec, idxVec, 32);
	cout << fstValIndex << endl;

	/*�ڶ������ݲ���												**/
	cout << "Val " << 0 << " In ";
	int secValIndex = funcBlockSort(intVec, idxVec, 0);
	cout << secValIndex << endl;

	/*���������ݲ���												**/
	cout << endl << "Val " << 99 << " In ";
	int trdValIndex = funcBlockSort(intVec, idxVec, 99);
	cout << trdValIndex << endl;
}

int funcBlockSort(const vector<int>& vec, const vector<Index_dt>& idxVec, int keyVal)
{
	/*����������͸���ֵ������ʼ���������ͽ�����������	**/
	int bolckStartIndex = -1;
	int bolckEndIndex = -1;
	for (int i = 0; i < idxVec.size(); ++i)
	{
		if (idxVec[i].iVal >= keyVal)
		{
			/*�趨���ҷ�Χ����ʼ����					**/
			bolckStartIndex = idxVec[i].iIndex;

			/*�趨���ҷ�Χ�Ľ�������					**/
			if (i != idxVec.size() - 1)
				bolckEndIndex = idxVec[i + 1].iIndex;
			else
				bolckEndIndex = vec.size() - 1;

			break;
		}
	}

	/*��ʼ������������������쳣						**/
	if (-1 == bolckStartIndex || -1 == bolckEndIndex)
		return -1;

	/*������ʼ�����ͽ����������Ҹ���ֵ������			**/
	for (int j = bolckStartIndex; j <= bolckEndIndex; ++j)
	{
		if (vec[j] == keyVal)
			return j;
	}

	/*����ʧ��											**/
	return -1;
}