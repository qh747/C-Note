#include "HashAlg.h"

int MoreThanHalfNum_Solution::solve(vector<int>& numbers)
{
	unordered_map<int, int> recordMap;
	for (int i = 0; i < numbers.size(); ++i) {
		unordered_map<int, int>::iterator iter = recordMap.find(numbers[i]);
		if (recordMap.end() == iter)
			recordMap.insert(make_pair(numbers[i], 1));
		else {
			if (iter->second >= numbers.size() / 2)
				return iter->first;
			else
				iter->second += 1;
		}
	}

	return -1;
}

void MoreThanHalfNum_Solution::demo()
{
	vector<int> vec = initializer_list<int>{3, 3, 3, 3, 2, 2, 3};
	cout << this->solve(vec) << endl;
}

vector<int> FindNumsAppearOnce_Solution::FindNumsAppearOnce(vector<int>& nums)
{
	// 将数组元素存入哈希表中
	unordered_map<int, int> valMap;
	for (int i = 0; i < nums.size(); ++i) {
		if (valMap.end() == valMap.find(nums[i])) {
			valMap.insert(make_pair(nums[i], 1));
		}
		else {
			++valMap[nums[i]];
		}
	}

	// 查找哈希表中元素个数为1的元素
	vector<int> resVec;
	for (int i = 0; i < nums.size(); ++i) {
		if (1 == valMap[nums[i]]) {
			resVec.push_back(nums[i]);

			if (2 == resVec.size())
				break;
		}
	}

	// 顺序排列元素
	if (resVec[0] < resVec[1])
		return resVec;
	else
		return { resVec[1], resVec[0] };
}

void FindNumsAppearOnce_Solution::demo()
{
	vector<int> vec = initializer_list<int>{ 1, 4, 1, 5 };
	vector<int> resVec = this->FindNumsAppearOnce(vec);
	for (int i = 0; i < resVec.size(); ++i) {
		cout << resVec[i] << " ";
	}
	cout << endl;
}

int minNumberDisappeared_Solution::minNumberDisappeared(vector<int>& nums)
{
	unordered_map<int, int> valMap;
	for (int i = 0; i < nums.size(); ++i) {
		if (valMap.end() == valMap.find(nums[i])) {
			valMap.insert(make_pair(nums[i], 1));
		}
		else {
			++valMap[nums[i]];
		}
	}

	int res = 1;
	while (valMap.end() != valMap.find(res)) {
		++res;
	}
	return res;
}

void minNumberDisappeared_Solution::demo()
{
	vector<int> vec = initializer_list<int>{ -2, 3, 4, 1, 5 };
	cout << this->minNumberDisappeared(vec) << endl;
}