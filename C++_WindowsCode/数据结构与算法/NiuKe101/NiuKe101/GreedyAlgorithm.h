#pragma once
#include <string>
#include <algorithm>
#include <cmath>
#include <iostream>
using std::string;
using std::cout;
using std::endl;
using std::max;

// BM12 - 最长回文子串
class GetLongestPalindrome_Solution
{
public:
	int getLongestPalindrome(string A);
	int getLength(string A, int start, int end);
	void demo();
};