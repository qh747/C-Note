#pragma once
#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include <deque>
#include <queue>
using std::cout;
using std::endl;
using std::stack;
using std::string;
using std::vector;
using std::deque;
using std::queue;
using std::priority_queue;
using std::initializer_list;
using std::greater;
using std::pair;

// BM1 - ������ջʵ�ֶ���
class TwoStackImplQueue_Solution
{
public:
	void push(int node);
	int pop();

public:
	void demo();

private:
	stack<int> stack1;
	stack<int> stack2;
};

// BM2 - ����min������ջ
class IncludeMinStack_Solution 
{
public:
	void push(int value);
	void pop();
	int top();
	int min();

public:
	void demo();

private:
	stack<int> m_dataStack;
	stack<int> m_minStack;
};

// BM3 - ��Ч��������
class isValid_Solution 
{
public:
	bool isValid(string s);
	void demo();
};

// BM4 - �������ڵ����ֵ
class maxInWindows_Solution
{
public:
	vector<int> maxInWindows(vector<int>& num, int size);
	void demo();
};

// BM5 - ��С��K����
class GetLeastNumbers_Solution 
{
public:
	vector<int> getLeastNumbers(vector<int>& input, int k);
	void demo();
};

// BM6 - Ѱ�ҵ�K��
class findKth_Solution 
{
public:
	int findKth(vector<int>& a, int n, int K);
	void demo();
};

// BM7 - ����������λ��
class StreamMid_Solution 
{
public:
	void Insert(int num);
	double GetMedian();

	void demo();

private:
	priority_queue<int, vector<int>> m_bigTopHeap;
	priority_queue<int, vector<int>, greater<int>> m_smallTopHeap;
};

// BM8 - ���ʽ��ֵ
class ExpressionEvaluation_Solution {
public:
	int solve(string s);
	pair<int, int> getResult(const string& s, int idx);

public:
	void demo();
};