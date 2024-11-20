#pragma once
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using std::cout;
using std::endl;
using std::string;
using std::unordered_map;
using std::make_pair;
using std::vector;
using std::initializer_list;

// BM2 - 数组中出现次数超过一半的数字
class MoreThanHalfNum_Solution
{
public:
	int solve(vector<int>& numbers);
	void demo();
};

// BM3 - 数组中只出现一次的两个数字
class FindNumsAppearOnce_Solution 
{
public:
	vector<int> FindNumsAppearOnce(vector<int>& nums);
	void demo();
};

// BM4 - 缺失的第一个正整数
class minNumberDisappeared_Solution {
public:
	int minNumberDisappeared(vector<int>& nums);
	void demo();
};