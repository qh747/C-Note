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

// BM2 - �����г��ִ�������һ�������
class MoreThanHalfNum_Solution
{
public:
	int solve(vector<int>& numbers);
	void demo();
};

// BM3 - ������ֻ����һ�ε���������
class FindNumsAppearOnce_Solution 
{
public:
	vector<int> FindNumsAppearOnce(vector<int>& nums);
	void demo();
};

// BM4 - ȱʧ�ĵ�һ��������
class minNumberDisappeared_Solution {
public:
	int minNumberDisappeared(vector<int>& nums);
	void demo();
};