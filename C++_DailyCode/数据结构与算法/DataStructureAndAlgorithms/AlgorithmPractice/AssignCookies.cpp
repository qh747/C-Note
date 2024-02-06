#include "PublicHeaders.h"

/*���ɷ�������							**/
void funcTestAssignCookies()
{
	/*��һ�����ݲ���								**/
	vector<int> fstBboys = initializer_list<int>{ 1, 3, 5, 7 };
	vector<int> fstCookies = initializer_list<int>{ 1, 4, 6 };

	int fullBoysCount = AlgorithmAssignCookies(fstBboys, fstCookies);
	cout << "First Test Of Full Boys Count: " << fullBoysCount << endl;

	/*�ڶ������ݲ���								**/
	vector<int> secBboys = initializer_list<int>{ 1, 9, 15, 3 };
	vector<int> secCookies = initializer_list<int>{ 1, 0, 2 };

	fullBoysCount = AlgorithmAssignCookies(secBboys, secCookies);
	cout << "Second Test Of Full Boys Count: " << fullBoysCount << endl;

	/*���������ݲ���								**/
	vector<int> trdBboys = initializer_list<int>{ 11, 10, 7, 2 };
	vector<int> trdCookies = initializer_list<int>{ 1, 0, 2 };

	fullBoysCount = AlgorithmAssignCookies(trdBboys, trdCookies);
	cout << "Third Test Of Full Boys Count: " << fullBoysCount << endl;
}

int AlgorithmAssignCookies(vector<int> boys, vector<int> cookies)
{
	sort(boys.begin(), boys.end());
	sort(cookies.begin(), cookies.end());

	int curCookieIndex = 0;
	int curBoyIndex = 0;
	int fullBoys = 0;
	while (true)
	{
		if (curBoyIndex >= boys.size() || curCookieIndex >= cookies.size())
			break;

		if (cookies[curCookieIndex] >= boys[curBoyIndex])
		{
			++curBoyIndex;
			++fullBoys;
		}

		++curCookieIndex;
	}

	return fullBoys;
}