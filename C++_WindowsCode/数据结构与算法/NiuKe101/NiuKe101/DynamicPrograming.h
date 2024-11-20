#pragma once
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
using std::vector;
using std::cout;
using std::endl;
using std::min;
using std::max;
using std::initializer_list;
using std::string;

// BM1 - 斐波拉契数列
class Fibonacci_Solution
{
public:
	int Fibonacci(int n);
	void demo();
};

// BM2 - 跳台阶
class JumpFloor_Solution
{
public:
	int jumpFloor(int number);
	int dp(int num, vector<int>& vec);

public:
	void demo();
};

// BM3 - 最小花费爬楼梯
class MinCostClimbingStairs_Solution
{
public:
	int minCostClimbingStairs(vector<int>& cost);
	int dp(vector<int>& cost, vector<int>& pathFee, int layer);

public:
	void demo();
};

// BM4 - 最长公共子序列（二）
class LCS_Solution
{
public:
	enum LcsDirect {
		up     = 1,
		left   = 2,
		upLeft = 3,
	};

public:
	string LCS(string s1, string s2);
	void getStr(const string& s, string& res, vector<vector<int>>& directVec, int row, int colu);

public:
	void demo();
};

// BM5 - 最长公共子串
class LCS2_Solution 
{
public:
	string LCS(string str1, string str2);
	void demo();
};

// BM6 - 不同路径的数目（一）
class UniquePaths_Solution
{
public:
	int uniquePaths(int m, int n);
	void demo();
};

// BM7 - 矩阵的最小路径和
class MinPathSum_Solution 
{
public:
	int minPathSum(vector<vector<int>>& matrix);
	void demo();
};

// BM8 - 把数字翻译成字符串
class TransNum_Solution 
{
public:
	int solve(string nums);
	void demo();
};

// BM9 - 兑换零钱（一）
class MinMoney_Solution
{
public:
	int minMoney(vector<int>& coins, int amount);
	void demo();
};

// BM10 - 最长上升子序列(一)
class LIS_Solution
{
public:
	int LIS(vector<int>& arr);
	void demo();
};

// BM14 - 编辑距离（一）
class EditDistance_Solution
{
public:
	int editDistance(string str1, string str2);
	void demo();
};

// BM17 - 打家劫舍(一)
class Rob_Solution
{
public:
	int rob(vector<int>& nums);
	void demo();
};