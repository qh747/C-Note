#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*�������д洢�����ݸ�ʽ			**/
typedef struct DATA_TYPE_INDEX
{
	int		iVal;					// Ԫ�عؼ���Ϣ
	int		iIndex;					// Ԫ������

	DATA_TYPE_INDEX(int val, int idx)
	{
		iVal = val;
		iIndex = idx;
	}

}Index_dt;

/*�ֿ����							**/
void funcCallBlockSort();
int funcBlockSort(const vector<int>& vec, const vector<Index_dt>& idxVec, int keyVal);