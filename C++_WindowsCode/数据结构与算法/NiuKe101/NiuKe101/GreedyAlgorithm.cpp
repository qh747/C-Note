#include "GreedyAlgorithm.h"

int GetLongestPalindrome_Solution::getLongestPalindrome(string A)
{
	int maxLen = 1;
	for (int i = 0; i < A.size(); ++i) {
		int curLen = max(getLength(A, i, i), getLength(A, i, i + 1));
		maxLen = (curLen > maxLen) ? curLen : maxLen;
	}

	return maxLen;
}

int GetLongestPalindrome_Solution::getLength(string A, int start, int end)
{
	while (start >= 0 && end < A.size() && A[start] == A[end]) {
		--start;
		++end;
	}
	return end - start - 1;
}

void GetLongestPalindrome_Solution::demo()
{
	string str = "ababc";
	cout << getLongestPalindrome(str) << endl;

	str = "abbba";
	cout << getLongestPalindrome(str) << endl;

	str = "a";
	cout << getLongestPalindrome(str) << endl;

	str = "baabccc";
	cout << getLongestPalindrome(str) << endl;
}