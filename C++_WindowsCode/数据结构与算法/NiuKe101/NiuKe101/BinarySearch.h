#pragma once
#include <iostream>
#include <vector>
#include <string>
using std::cout;
using std::endl;
using std::vector;
using std::string;

// BM1 - ���ֲ���-I
class search_Solution {
public:
	int search(vector<int>& nums, int target);
	void searchTest();
};

// BM3 - Ѱ�ҷ�ֵ
class findPeakElement_Solution {
public:
	int findPeakElement(vector<int>& nums);
	void findPeakElementTest();
};

// BM4 - �����е������
class InversePairs_Solution {
public:
	int InversePairs(vector<int>& nums);
	void mergeSplit(vector<int>& nums, int start, int end, int& count);
	void merge(vector<int>& nums, int start, int end, int& count);
	void InversePairsTest();
};

// BM5 ��ת�������С����
class minNumberInRotateArray_Solution {
public:
	int minNumberInRotateArray(vector<int>& nums);
	void minNumberInRotateArrayTest();
};

// BM6 �Ƚϰ汾��
class compare_Solution {
public:
	int compare(string version1, string version2);
	void compareTest();
};