#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
using std::cout;
using std::endl;
using std::vector;
using std::initializer_list;
using std::string;
using std::for_each;
using std::max;

// BM1 - 没有重复项数字的全排列
class Permute_Solution 
{
public:
	vector<vector<int>> permute(vector<int>& num);
	void trackBacking(vector<int>& num, vector<int>& pathVec, vector<bool>& usedVec);

public:
	void demo();

private:
	vector<vector<int>> m_resVec;
};

// BM2 - 有重复项数字的全排列
class PermuteUnique_Solution 
{
public:
	vector<vector<int>> permuteUnique(vector<int>& num);
	void trackBacking(vector<int>& num, vector<int>& pathVec, vector<bool>& usedVec);

public:
	void demo();

private:
	vector<vector<int>> m_resVec;
};

// BM3 - 岛屿数量
class IslandCount_Solution {
public:
	int solve(vector<vector<char> >& grid);
	void dfs(vector<vector<char>>& grid, int x, int y);

public:
	void demo();
};

// BM4 - 字符串的排列
class Permutation_Solution 
{
public:
	vector<string> Permutation(string str);
	void dfs(string& str, vector<char>& pathVec, vector<bool>& usedVec);

public:
	void demo();

private:
	vector<string> m_resVec;
};

// BM6 - 括号生成
class GenerateParenthesis_Solution
{
public:
	vector<string> generateParenthesis(int n);
	void dfs(int left, int right, int n, string s);

public:
	void demo();

private:
	vector<string> m_resVec;
};

// BM7 - 矩阵最长路径
class MaxPath_Solution 
{
public:
	int solve(vector<vector<int>>& matrix);
	int dfs(vector<vector<int>>& matrix, vector<vector<int>>& mem,int row, int colu, int x, int y);

public:
	void demo();

private:
	int m_maxPathLen = 0;
};

// BM13 - 数字字符串转化成IP地址
class RestoreIpAddresses_Solution
{
public:
	vector<string> restoreIpAddresses(string s);
	void tracingback(string s, int startIdx, int pointCount);

public:
	void demo();

private:
	vector<string> m_resVec;
};