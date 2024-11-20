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

// BM1 - 쳲���������
class Fibonacci_Solution
{
public:
	int Fibonacci(int n);
	void demo();
};

// BM2 - ��̨��
class JumpFloor_Solution
{
public:
	int jumpFloor(int number);
	int dp(int num, vector<int>& vec);

public:
	void demo();
};

// BM3 - ��С������¥��
class MinCostClimbingStairs_Solution
{
public:
	int minCostClimbingStairs(vector<int>& cost);
	int dp(vector<int>& cost, vector<int>& pathFee, int layer);

public:
	void demo();
};

// BM4 - ����������У�����
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

// BM5 - ������Ӵ�
class LCS2_Solution 
{
public:
	string LCS(string str1, string str2);
	void demo();
};

// BM6 - ��ͬ·������Ŀ��һ��
class UniquePaths_Solution
{
public:
	int uniquePaths(int m, int n);
	void demo();
};

// BM7 - �������С·����
class MinPathSum_Solution 
{
public:
	int minPathSum(vector<vector<int>>& matrix);
	void demo();
};

// BM8 - �����ַ�����ַ���
class TransNum_Solution 
{
public:
	int solve(string nums);
	void demo();
};

// BM9 - �һ���Ǯ��һ��
class MinMoney_Solution
{
public:
	int minMoney(vector<int>& coins, int amount);
	void demo();
};

// BM10 - �����������(һ)
class LIS_Solution
{
public:
	int LIS(vector<int>& arr);
	void demo();
};

// BM14 - �༭���루һ��
class EditDistance_Solution
{
public:
	int editDistance(string str1, string str2);
	void demo();
};

// BM17 - ��ҽ���(һ)
class Rob_Solution
{
public:
	int rob(vector<int>& nums);
	void demo();
};