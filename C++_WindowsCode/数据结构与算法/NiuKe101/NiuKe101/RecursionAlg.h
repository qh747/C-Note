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

// BM1 - û���ظ������ֵ�ȫ����
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

// BM2 - ���ظ������ֵ�ȫ����
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

// BM3 - ��������
class IslandCount_Solution {
public:
	int solve(vector<vector<char> >& grid);
	void dfs(vector<vector<char>>& grid, int x, int y);

public:
	void demo();
};

// BM4 - �ַ���������
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

// BM6 - ��������
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

// BM7 - �����·��
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

// BM13 - �����ַ���ת����IP��ַ
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