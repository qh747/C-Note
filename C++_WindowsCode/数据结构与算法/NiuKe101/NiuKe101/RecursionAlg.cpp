#include "RecursionAlg.h"

vector<vector<int>> Permute_Solution::permute(vector<int>& num)
{
	vector<bool> usedVec;
	usedVec.resize(num.size(), false);

	vector<int> pathVec;

	trackBacking(num, pathVec, usedVec);
	return m_resVec;
}

void Permute_Solution::trackBacking(vector<int>& num, vector<int>& pathVec, vector<bool>& usedVec)
{
	// ���õݹ���ֹ����
	if (pathVec.size() == num.size()) {
		m_resVec.push_back(pathVec);
		return;
	}

	for (int i = 0; i < num.size(); ++i) {
		if (!usedVec[i]) {
			// �ݹ�
			pathVec.push_back(num[i]);
			usedVec[i] = true;
			trackBacking(num, pathVec, usedVec);

			// ����
			pathVec.pop_back();
			usedVec[i] = false;
		}
		else {
			continue;
		}
	}
}

void Permute_Solution::demo()
{
	vector<int> num = initializer_list<int>{ 1, 2, 3 };
	vector<vector<int>>res = this->permute(num);
	for (int i = 0; i < res.size(); ++i) {
		cout << "Layer" << i + 1 << ": ";
		for (int j = 0; j < res[i].size(); ++j) {
			cout << res[i][j] << " ";
		}
		cout << endl;
	}
}

vector<vector<int>> PermuteUnique_Solution::permuteUnique(vector<int>& num)
{
	// ����
	std::sort(num.begin(), num.end());

	// �ݹ�/����
	vector<int> pathVec;
	vector<bool> usedVec(num.size(), false);

	this->trackBacking(num, pathVec, usedVec);
	return m_resVec;
}

void PermuteUnique_Solution::trackBacking(vector<int>& num, vector<int>& pathVec, vector<bool>& usedVec)
{
	if (pathVec.size() == num.size()) {
		m_resVec.push_back(pathVec);
		return;
	}

	for (int i = 0; i < num.size(); ++i) {
		if (usedVec[i]) {
			continue;
		}
		else if (i > 0 && num[i] == num[i - 1] && !usedVec[i - 1]) {
			// ��������ȥ��
			continue;
		}
		else {
			pathVec.push_back(num[i]);
			usedVec[i] = true;

			this->trackBacking(num, pathVec, usedVec);
			pathVec.pop_back();
			usedVec[i] = false;
		}
	}
}

void PermuteUnique_Solution::demo()
{
	vector<int> num = initializer_list<int>{ 1, 1, 2 };
	vector<vector<int>>res = this->permuteUnique(num);
	for (int i = 0; i < res.size(); ++i) {
		cout << "Layer" << i + 1 << ": ";
		for (int j = 0; j < res[i].size(); ++j) {
			cout << res[i][j] << " ";
		}
		cout << endl;
	}
}

int IslandCount_Solution::solve(vector<vector<char>>& grid)
{
	int islandCount = 0;
	for (int i = 0; i < grid.size(); ++i) {
		for (int j = 0; j < grid[i].size(); ++j) {
			if ('0' == grid[i][j]) {
				continue;
			}
			else {
				++islandCount;
				this->dfs(grid, i, j);
			}
		}
	}

	return islandCount;
}

void IslandCount_Solution::dfs(vector<vector<char>>& grid, int x, int y)
{
	int rowBorder = grid.size();
	int columnBorder = grid[0].size();

	if (x < 0 || x >= rowBorder || y < 0 || y >= columnBorder)
		return;

	if ('0' == grid[x][y])
		return;

	grid[x][y] = '0';
	this->dfs(grid, x - 1, y);
	this->dfs(grid, x + 1, y);
	this->dfs(grid, x, y - 1);
	this->dfs(grid, x, y + 1);
}

void IslandCount_Solution::demo()
{
	vector<vector<char>> grid = initializer_list<vector<char>>{ {'1', '1', '0', '0', '0'},  
																{'0', '1', '0', '1', '1'},
																{'0', '0', '0', '1', '1'}, 
																{'0', '0', '0', '0', '0'}, 
																{'0', '0', '1', '1', '1'}, };
	cout << this->solve(grid) << endl;

	vector<vector<char>> secGrid = initializer_list<vector<char>>{{'0'}};
	cout << this->solve(secGrid) << endl;

	vector<vector<char>> thrGrid = initializer_list<vector<char>>{ {'1', '1'}, {'1', '1'} };
	cout << this->solve(thrGrid) << endl;
}

vector<string> Permutation_Solution::Permutation(string str)
{
	vector<char> path;
	vector<bool> usedVec(str.size(), false);

	sort(str.begin(), str.end());
	this->dfs(str, path, usedVec);
	return m_resVec;
}

void Permutation_Solution::dfs(string& str, vector<char>& pathVec, vector<bool>& usedVec)
{
	if (pathVec.size() == str.size()) {
		m_resVec.push_back(string(pathVec.begin(), pathVec.end()));
		return;
	}

	for (int i = 0; i < str.size(); ++i) {
		if (usedVec[i]) {
			continue;
		}
		else if (i > 0 && str[i - 1] == str[i] && usedVec[i - 1]) {
			continue;
		}
		else {
			pathVec.push_back(str[i]);
			usedVec[i] = true;

			this->dfs(str, pathVec, usedVec);
			pathVec.pop_back();
			usedVec[i] = false;
		}
	}
}

void Permutation_Solution::demo()
{
	vector<string> res = this->Permutation(string("ab"));
	for_each(res.begin(), res.end(), [](const string& s) {
		cout << s << " ";
	});
	cout << endl;

	m_resVec.clear();
	vector<string> secRes = this->Permutation(string("aab"));
	for_each(secRes.begin(), secRes.end(), [](const string& s) {
		cout << s << " ";
	});
	cout << endl;

	m_resVec.clear();
	vector<string> thrRes = this->Permutation(string("abc"));
	for_each(thrRes.begin(), thrRes.end(), [](const string& s) {
		cout << s << " ";
	});
	cout << endl;
}

vector<string> GenerateParenthesis_Solution::generateParenthesis(int n)
{
	string str;
	this->dfs(0, 0, n, str);

	return m_resVec;
}

void GenerateParenthesis_Solution::dfs(int left, int right, int n, string s)
{
	if (left == n && right == n) {
		// ������������������ź������ŵ��������Ѿ�ʹ����
		m_resVec.push_back(s);
		return;
	}

	if (left < n) {
		s.push_back('(');
		this->dfs(left + 1, right, n, s);
		s.pop_back();
	}
	
	if (right < left && right < n) {
		// �����ŵ������������ŵ��������ƣ������ǰ�����ŵ��������������Żᵼ����Ч���ż���
		s.push_back(')');
		this->dfs(left, right + 1, n, s);
		s.pop_back();
	}
}

void GenerateParenthesis_Solution::demo()
{
	vector<string> res = this->generateParenthesis(1);
	for_each(res.begin(), res.end(), [](const string& s) {
		cout << s << " ";
	});
	cout << endl;

	m_resVec.clear();
	vector<string> secRes = this->generateParenthesis(2);
	for_each(secRes.begin(), secRes.end(), [](const string& s) {
		cout << s << " ";
	});
	cout << endl;

	m_resVec.clear();
	vector<string> thrRes = this->generateParenthesis(3);
	for_each(thrRes.begin(), thrRes.end(), [](const string& s) {
		cout << s << " ";
	});
	cout << endl;
}

int MaxPath_Solution::solve(vector<vector<int>>& matrix)
{
	int row = matrix.size();
	int colu = matrix[0].size();

	// �ڴ�������飬�洢��ǰֵ�Ƿ񱻼�¼��
	int maxRes = 0;
	vector<vector<int>> pathMemVec(row, vector<int>(colu));
	for (int i = 0; i < row; ++i) {
		for (int j = 0; j < colu; ++j) {
			maxRes = max(maxRes, dfs(matrix, pathMemVec, row, colu, i, j));
		}
	}

	return maxRes;
}

int MaxPath_Solution::dfs(vector<vector<int>>& matrix, vector<vector<int>>& mem, int row, int colu, int x, int y)
{
	if (0 != mem[x][y]) {
		// ��ǰֵ�ѱ���¼��
		return mem[x][y];
	}
	else {
		// ��ʼ����ǰֵ
		++mem[x][y];
	}

	int maxPath = 0;
	if (x - 1 >= 0 && matrix[x - 1][y] > matrix[x][y])
		maxPath = max(maxPath, dfs(matrix, mem, row, colu, x - 1, y) + 1);

	if (x + 1 < row && matrix[x + 1][y] > matrix[x][y])
		maxPath = max(maxPath, dfs(matrix, mem, row, colu, x + 1, y) + 1);

	if (y - 1 >= 0 && matrix[x][y - 1] > matrix[x][y])
		maxPath = max(maxPath, dfs(matrix, mem, row, colu, x, y - 1) + 1);

	if (y + 1 < colu && matrix[x][y + 1] > matrix[x][y])
		maxPath = max(maxPath, dfs(matrix, mem, row, colu, x, y + 1) + 1);

	mem[x][y] = max(mem[x][y], maxPath);
	return mem[x][y];
}

void MaxPath_Solution::demo()
{
	vector<vector<int>> vec = initializer_list<vector<int>>{ {3, 4, 5}, {3, 2, 6}, {2, 2, 1} };
	cout << this->solve(vec) << endl;
}

vector<string> RestoreIpAddresses_Solution::restoreIpAddresses(string s)
{
	m_resVec.clear();

	// �ַ���λ��С��4�����12�޷���ԭIP��ַ�����ؿ�����
	if (s.size() < 4 || s.size() > 12)
		return m_resVec;

	tracingback(s, 0, 0);
	return m_resVec;
}

void RestoreIpAddresses_Solution::tracingback(string s, int startIdx, int pointCount)
{
	if (3 == pointCount) {
		// ��ǰ�Ѿ�û�����鹹��IP��ַ�����һ����
		if (startIdx == s.size())
			return;

		// ��ǰΪ����010����ʽ���޷���ԭIP��ַ
		if ('0' == s[startIdx] && startIdx != s.size() - 1)
			return;

		// ��ǰIP��ַ�����һ���ֳ���255��Ϊ����ЧIP��ַ
		int num = atoi(s.substr(startIdx, s.size() - startIdx).c_str());
		if (num > 255)
			return;

		// ��ЧIP��ַ����������
		m_resVec.push_back(s); 	
		return;
	}

	for (int i = startIdx; i < s.size() && i < startIdx + 3; ++i) {
		// ��ǰΪ����010����ʽ���޷���ԭIP��ַ
		if (i != startIdx && '0' == s[startIdx])
			continue;
		
		// ��ǰIP��ַ�����һ���ֳ���255��Ϊ����ЧIP��ַ
		int num = atoi(s.substr(startIdx, i - startIdx + 1).c_str());
		if (num > 255)
			continue;

		// �ݹ鴦��
		s.insert(i + 1, 1, '.');
		++pointCount;
		tracingback(s, i + 2, pointCount);

		// ����
		--pointCount;
		s.erase(i + 1, 1);
	}
}

void RestoreIpAddresses_Solution::demo()
{
	vector<string> resVec = restoreIpAddresses("25525522135");
	for_each(resVec.begin(), resVec.end(), [](const string& ip) {
		cout << ip << endl;
	});

	resVec = restoreIpAddresses("1111");
	for_each(resVec.begin(), resVec.end(), [](const string& ip) {
		cout << ip << endl;
	});

	resVec = restoreIpAddresses("010010");
	for_each(resVec.begin(), resVec.end(), [](const string& ip) {
		cout << ip << endl;
	});
}