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

	// ����0��Ԫ�ز�ʹ��
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
		// cost[layer - 1]�����layer - 1����������Ҫ�ķ��ã�dp(cost, pathFee, layer - 1)����ӵײ㵽layer - 1��Ҫ����С����
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
				// ��¼��ǰ�ڵ����ֵ
				valVec[i][j] = valVec[i - 1][j - 1] + 1;

				// ��¼��ǰ�ڵ�ķ���
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
				// ���������Ӵ����ȼ�һ
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}

			if (dp[i][j] > maxStrLen) {
				// ���µ�ǰ��󹫹��ִ�����
				maxStrLen = dp[i][j];

				// ���µ�ǰ��󹫹��ִ����һ���ַ���λ��
				lastPos = i - 1;
			}
		}
	}

	// ���һ���ַ�λ�� - �ַ������� + 1 = �ַ�����ʼλ��
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
	// ��һ�к͵�һ�е�·����Ϊ1
	for (int i = 0; i < m; ++i) {		
		dp[i][0] = 1;	
	}
	for (int i = 0; i < n; ++i) {
		dp[0][i] = 1;
	}

	// ���ﵱǰ�ڵ��·���ܺ�Ϊ������߽ڵ��·�����ϱ߽ڵ��·��֮��
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

	// ��ʼ����һ�к͵�һ��
	dp[0][0] = matrix[0][0];
	for (int i = 1; i < row; ++i) {
		dp[i][0] = dp[i - 1][0] + matrix[i][0];
	}
	
	for (int i = 1; i < colu; ++i) {
		dp[0][i] = dp[0][i - 1] + matrix[0][i];
	}

	// ��ʼ��ʣ���к���
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

	// �ų��������
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

	// �ų��޷���������
	for (int i = 1; i < len; ++i) {
		if ('0' == nums[i] && '1' != nums[i - 1] && '2' != nums[i - 1]) {
			return 0;
		}
	}

	// dp�����ŷ��뷽��������
	vector<int> dp(len + 1, 1);
	for (int i = 2; i <= len; ++i) {
		//��11-19��21-26֮������
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
	
	// �ȱ�����Ʒ
	for (int coinIdx = 0; coinIdx < coins.size(); ++coinIdx) {
		int coin = coins[coinIdx];

		// �ٱ�������
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
	// dp�����ʼ��
	vector<vector<int>> dp(str1.size() + 1, vector<int>(str2.size() + 1));
	for (int i = 0; i <= str1.size(); ++i) {
		dp[i][0] = i;
	}
	for (int j = 0; j <= str2.size(); ++j) {
		dp[0][j] = j;
	}

	// dp���������ֵ
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

	// dp�������һ�С����һ�е�Ԫ�ر�ʾ�޸��ܴ���
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

	// dp�����ʼ��
	vector<int> dp(nums.size(), 0);
	dp[0] = nums[0];
	dp[1] = max(nums[0], nums[1]);

	// dp������ֵ
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