#include "DynamicPrograming.h"

int Fibonacci_Solution::Fibonacci(int n)
{
	if (n <= 2) {
		return 1;
	}
	else {
		vector<int> memVec(2, 1);
		for (int i = 2; i < n; ++i) {
			memVec.push_back(memVec[i - 1] + memVec[i - 2]);
		}
		return memVec[n - 1];
	}
}

void Fibonacci_Solution::demo()
{
	cout << this->Fibonacci(1) << endl;
	cout << this->Fibonacci(2) << endl;
	cout << this->Fibonacci(45) << endl;
}

int JumpFloor_Solution::jumpFloor(int number)
{
	if (number <= 1) {
		return 1;
	}
	else if (2 == number) {
		return 2;
	}

	// 数组0号元素不使用
	vector<int> vec(number + 1, 0);
	vec[0] = 0;
	vec[1] = 1;
	vec[2] = 2;

	return this->dp(number - 1, vec) + this->dp(number - 2, vec);
}

int JumpFloor_Solution::dp(int num, vector<int>& vec)
{
	if (0 != vec[num]) {
		return vec[num];
	}
	else {
		vec[num] = this->dp(num - 1, vec) + this->dp(num - 2, vec);
		return vec[num];
	}
}

void JumpFloor_Solution::demo()
{
	cout << this->jumpFloor(7) << endl;
}

int MinCostClimbingStairs_Solution::minCostClimbingStairs(vector<int>& cost)
{
	int layer = cost.size();
	
	vector<int> pathFee(layer + 1, 0);
	this->dp(cost, pathFee, layer);

	return pathFee[layer];
}

int MinCostClimbingStairs_Solution::dp(vector<int>& cost, vector<int>& pathFee, int layer)
{
	if (0 != pathFee[layer] || layer < 2) {
		return pathFee[layer];
	}
	else {
		// cost[layer - 1]代表从layer - 1层向上爬需要的费用，dp(cost, pathFee, layer - 1)代表从底层到layer - 1需要的最小费用
		int layerReduce1Free = cost[layer - 1] + dp(cost, pathFee, layer - 1);
		int layerReduce2Free = cost[layer - 2] + dp(cost, pathFee, layer - 2);
		pathFee[layer] = min(layerReduce1Free, layerReduce2Free);
		return pathFee[layer];
	}
}

void MinCostClimbingStairs_Solution::demo()
{
	vector<int> cost = initializer_list<int>{ 1,100,1,1,1,90,1,1,80,1 };
	cout << this->minCostClimbingStairs(cost) << endl;
}

string LCS_Solution::LCS(string s1, string s2)
{
	if (s1.empty() || s2.empty())
		return "-1";

	int s1Len = s1.size();
	int s2Len = s2.size();

	vector<vector<int>> valVec(s1Len + 1, vector<int>(s2Len + 1));
	vector<vector<int>> directVec(s1Len + 1, vector<int>(s2Len + 1));

	for (int i = 1; i <= s1Len; ++i) {
		for (int j = 1; j <= s2Len; ++j) {
			if (s1[i - 1] == s2[j - 1]) {
				// 记录当前节点的数值
				valVec[i][j] = valVec[i - 1][j - 1] + 1;

				// 记录当前节点的方向
				directVec[i][j] = LcsDirect::upLeft;
			}
			else {
				if (valVec[i - 1][j] >= valVec[i][j - 1]) {
					valVec[i][j] = valVec[i - 1][j];
					directVec[i][j] = LcsDirect::up;
				}
				else {
					valVec[i][j] = valVec[i][j - 1];
					directVec[i][j] = LcsDirect::left;
				}
			}
		}
	}

	string res;
	this->getStr(s1, res, directVec, s1Len, s2Len);
	return (res.empty() ? "-1" : res);
}

void LCS_Solution::getStr(const string& s, string& res, vector<vector<int>>& directVec, int row, int colu)
{
	if (0 == row || 0 == colu) {
		return;
	}
	else if (upLeft == directVec[row][colu]) {
		this->getStr(s, res, directVec, row - 1, colu - 1);
		res.push_back(s[row - 1]);
	}
	else if (left == directVec[row][colu]) {
		this->getStr(s, res, directVec, row, colu - 1);
	}
	else {
		this->getStr(s, res, directVec, row - 1, colu);
	}
}

void LCS_Solution::demo()
{
	cout << this->LCS("1A2C3D4B56", "B1D23A456A") << endl;
}

string LCS2_Solution::LCS(string str1, string str2)
{
	int s1Len = str1.size();
	int s2Len = str2.size();

	vector<vector<int>> dp(s1Len + 1, vector<int>(s2Len + 1));
	int maxStrLen = 0;
	int lastPos = 0;

	for (int i = 1; i <= s1Len; ++i) {
		for (int j = 1; j <= s2Len; ++j) {
			if (str1[i - 1] == str2[j - 1]) {
				// 连续公共子串长度加一
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}

			if (dp[i][j] > maxStrLen) {
				// 更新当前最大公共字串长度
				maxStrLen = dp[i][j];

				// 更新当前最大公共字串最后一个字符的位置
				lastPos = i - 1;
			}
		}
	}

	// 最后一个字符位置 - 字符串长度 + 1 = 字符串起始位置
	int startPos = lastPos - maxStrLen + 1;
	return str1.substr(startPos, maxStrLen);
}

void LCS2_Solution::demo()
{
	cout << this->LCS("22222", "22222") << endl;
}

int UniquePaths_Solution::uniquePaths(int m, int n)
{
	vector<vector<int>> dp(m, vector<int>(n));
	// 第一行和第一列的路径都为1
	for (int i = 0; i < m; ++i) {		
		dp[i][0] = 1;	
	}
	for (int i = 0; i < n; ++i) {
		dp[0][i] = 1;
	}

	// 到达当前节点的路径总和为到达左边节点的路径和上边节点的路径之和
	for (int i = 1; i < m; ++i) {
		for (int j = 1; j < n; ++j) {
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
		}
	}

	return dp[m - 1][n - 1];
}

void UniquePaths_Solution::demo()
{
	cout << this->uniquePaths(2, 2) << endl;
}

int MinPathSum_Solution::minPathSum(vector<vector<int>>& matrix)
{
	int row = matrix.size();
	int colu = matrix[0].size();	
	vector<vector<int>> dp(row, vector<int>(colu));

	// 初始化第一行和第一列
	dp[0][0] = matrix[0][0];
	for (int i = 1; i < row; ++i) {
		dp[i][0] = dp[i - 1][0] + matrix[i][0];
	}
	
	for (int i = 1; i < colu; ++i) {
		dp[0][i] = dp[0][i - 1] + matrix[0][i];
	}

	// 初始化剩余行和列
	for (int i = 1; i < row; ++i) {
		for (int j = 1; j < colu; ++j) {
			dp[i][j] = matrix[i][j] + min(dp[i - 1][j], dp[i][j - 1]);
		}
	}
	return dp[row - 1][colu - 1];
}

void MinPathSum_Solution::demo()
{
	vector<vector<int>> matrix = initializer_list<vector<int>>{{1, 3, 5, 9}, {8, 1, 3, 4}, {5, 0, 6, 1}, {8, 8, 4, 0}};
	cout << this->minPathSum(matrix) << endl;
}

int TransNum_Solution::solve(string nums)
{
	int len = nums.size();

	// 排除特殊情况
	if (1 == len) {
		int val = nums[0] - '0';
		if (val > 0)
			return 1;
		else
			return 0;
	}
	else if (2 == len) {
		int val = (nums[0] - '0') * 10 + (nums[1] - '0');
		if ((val >= 11 && val <= 19) || (val >= 21 && val <= 26))
			return 2;
		else
			return 1;
	}

	// 排除无法译码的情况
	for (int i = 1; i < len; ++i) {
		if ('0' == nums[i] && '1' != nums[i - 1] && '2' != nums[i - 1]) {
			return 0;
		}
	}

	// dp数组存放翻译方法的数量
	vector<int> dp(len + 1, 1);
	for (int i = 2; i <= len; ++i) {
		//在11-19，21-26之间的情况
		if ((nums[i - 2] == '1' && nums[i - 1] != '0') || (nums[i - 2] == '2' && nums[i - 1] > '0' && nums[i - 1] < '7'))
			dp[i] = dp[i - 1] + dp[i - 2];
		else
			dp[i] = dp[i - 1];
	}
	return dp[len];
}

void TransNum_Solution::demo()
{
	cout << solve("12") << endl;
	cout << solve("12258") << endl;
	cout << solve("31717126241541717") << endl;
}

int MinMoney_Solution::minMoney(vector<int>& coins, int amount)
{
	if (0 == amount)
		return 0;
	else if (amount < 0)
		return -1;

	vector<int> dp(amount + 1, INT_MAX);
	dp[0] = 0;
	
	// 先遍历物品
	for (int coinIdx = 0; coinIdx < coins.size(); ++coinIdx) {
		int coin = coins[coinIdx];

		// 再遍历背包
		for (int curAmount = coin; curAmount <= amount; ++curAmount) {
			int previousAmountCostCoins = dp[curAmount - coin];
			if(INT_MAX != previousAmountCostCoins)
				dp[curAmount] = min(previousAmountCostCoins + 1, dp[curAmount]);
		}
	}

	if (INT_MAX == dp[amount])
		return -1;
	else
		return dp[amount];
}

void MinMoney_Solution::demo()
{
	vector<int> arr = { 5, 2, 3 };
	int aim = 10;
	cout << minMoney(arr, aim) << endl;

	arr = { 5, 2, 3 };
	aim = 0;
	cout << minMoney(arr, aim) << endl;

	arr = { 3, 5 };
	aim = 2;
	cout << minMoney(arr, aim) << endl;
}

int LIS_Solution::LIS(vector<int>& arr)
{
	if (arr.empty())
		return 0;

	vector<int> dp(arr.size() + 1, 1);
	int maxLen = 1;

	for (int i = 1; i < arr.size(); ++i) {
		int curValue = arr[i];
		for (int j = 0; j < i; ++j) {
			if (arr[j] < curValue) {
				dp[i] = max(dp[j] + 1, dp[i]);
				maxLen = (dp[i] > maxLen) ? dp[i] : maxLen;
			}
		}
	}
	return maxLen;
}

void LIS_Solution::demo()
{
	vector<int> arr = { 6, 3, 1, 5, 2, 3, 7 };
	cout << LIS(arr) << endl;
}

int EditDistance_Solution::editDistance(string str1, string str2)
{
	// dp数组初始化
	vector<vector<int>> dp(str1.size() + 1, vector<int>(str2.size() + 1));
	for (int i = 0; i <= str1.size(); ++i) {
		dp[i][0] = i;
	}
	for (int j = 0; j <= str2.size(); ++j) {
		dp[0][j] = j;
	}

	// dp数组填充数值
	for (int i = 1; i <= str1.size(); ++i) {
		for (int j = 1; j <= str2.size(); ++j) {
			if (str1[i - 1] == str2[j - 1]) {
				dp[i][j] = dp[i - 1][j - 1];
			}
			else {
				int leftTopVal = dp[i - 1][j - 1];
				int leftVal = dp[i][j - 1];
				int topVal = dp[i - 1][j];
				dp[i][j] = min(leftTopVal, min(leftVal, topVal)) + 1;
			}
		}
	}

	// dp数组最后一行、最后一列的元素表示修改总次数
	return dp[str1.size()][str2.size()];
}

void EditDistance_Solution::demo()
{

	cout << editDistance("new", "nowcoder") << endl;
	cout << editDistance("intention", "execution") << endl;
}

int Rob_Solution::rob(vector<int>& nums)
{
	if (nums.empty())
		return 0;
	else if (1 == nums.size())
		return nums[0];
	else if (2 == nums.size())
		return max(nums[0], nums[1]);

	// dp数组初始化
	vector<int> dp(nums.size(), 0);
	dp[0] = nums[0];
	dp[1] = max(nums[0], nums[1]);

	// dp数组填值
	for (int i = 2; i < nums.size(); ++i) {
		dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
	}

	return dp[nums.size() - 1];
}

void Rob_Solution::demo()
{
	vector<int> nums = { 1, 2, 3, 4 };
	cout << rob(nums) << endl;

	nums = { 1, 3, 6 };
	cout << rob(nums) << endl;

	nums = { 2, 10, 5 };
	cout << rob(nums) << endl;
}