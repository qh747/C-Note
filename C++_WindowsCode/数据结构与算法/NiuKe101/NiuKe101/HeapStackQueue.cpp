#include "HeapStackQueue.h"

void TwoStackImplQueue_Solution::push(int node)
{
	stack1.push(node);
}

int TwoStackImplQueue_Solution::pop()
{
	// ����ջ��Ϊ��, û������
	if (stack1.empty() && stack2.empty())
		return -1;

	// ����ջΪ�գ��Ӳ���ջ��ȡ����
	int node = 0;
	if (stack2.empty()) {
		while (!stack1.empty()) {
			node = stack1.top();
			stack1.pop();

			stack2.push(node);
		}
	}

	// �ӵ���ջȡ������
	node = stack2.top();
	stack2.pop();
	return node;
}

void TwoStackImplQueue_Solution::demo()
{
	for (int i = 0; i < 10; ++i) {
		this->push(i);
	}

	int val = this->pop();
	while (-1 != val) {
		cout << val << " ";
		val = this->pop();
	}
	cout << endl;
}

void IncludeMinStack_Solution::push(int value)
{
	m_dataStack.push(value);

	// �洢��СԪ�ص�ջ��Ԫ�ظ�����洢����Ԫ�ص�ջ��Ԫ�ظ�����ͬ
	if (m_minStack.empty() || m_minStack.top() > value)
		m_minStack.push(value);
	else
		m_minStack.push(m_minStack.top());
}

void IncludeMinStack_Solution::pop()
{
	// �洢��СԪ�ص�ջ��Ԫ�ظ�����洢����Ԫ�ص�ջ��Ԫ�ظ�����ͬ
	m_dataStack.pop();
	m_minStack.pop();
}

int IncludeMinStack_Solution::top()
{
	return m_dataStack.top();
}

int IncludeMinStack_Solution::min()
{
	return m_minStack.top();
}

void IncludeMinStack_Solution::demo()
{
	// Ԫ����ջ����ʾ��СԪ��
	for (int i = 0; i <= 10; ++i) {
		this->push(i);

		cout << "In Push Motivation. Min Value: " << this->min() << " Top Value: " << this->top() << endl;
	}

	// Ԫ�س�ջ����ʾ��СԪ��
	for (int i = 0; i < 10; ++i) {
		this->pop();

		cout << "In Pop Motivation. Min Value: " << this->min() << " Top Value: " << this->top() << endl;
	}
}

bool isValid_Solution::isValid(string s)
{
	if (s.empty())
		return false;

	stack<char> cStack;
	for (int i = 0; i < s.size(); ++i) {
		if (']' == s[i] || ')' == s[i] || '}' == s[i]) {
			if (cStack.empty())
				return false;

			char val = cStack.top();
			cStack.pop();

			if (')' == s[i] && '(' != val)
				return false;
			else if (']' == s[i] && '[' != val)
				return false;
			else if ('}' == s[i] && '{' != val)
				return false;
		}
		else
			cStack.push(s[i]);
	}

	if (cStack.empty())
		return true;
	else
		return false;
}

void isValid_Solution::demo()
{
	string s = "[](){}";
	cout << this->isValid(s) << endl;

	s = "{[()]}";
	cout << this->isValid(s) << endl;

	s = "{[({)]}";
	cout << this->isValid(s) << endl;
}

vector<int> maxInWindows_Solution::maxInWindows(vector<int>& num, int size)
{
	vector<int> resVec;
	if (size <= 0 || size > num.size() || num.empty())
		return resVec;

	// ��¼Ԫ�������Ķ���
	deque<int> idxQueue;

	// ��¼����������Ԫ�صĶ���
	deque<int> monoQueue;

	// ��������sizeָ��������Ԫ��
	for (int i = 0; i < size; ++i) {
		while (!monoQueue.empty() && monoQueue.back() <= num[i]) {
			monoQueue.pop_back();
			idxQueue.pop_back();
		}
		monoQueue.push_back(num[i]);
		idxQueue.push_back(i);
	}
	resVec.push_back(monoQueue.front());

	for (int i = size; i < num.size(); ++i) {
		// �����ݼ�����ȡ����βԪ�رȵ�ǰԪ��С��Ԫ��
		while (!monoQueue.empty() && monoQueue.back() <= num[i]) {
			monoQueue.pop_back();
			idxQueue.pop_back();
		}

		// ȡ�����ڶ���Ԫ��
		if (!monoQueue.empty() && monoQueue.front() == num[i - size] && (i - size) == idxQueue.front()) {
			monoQueue.pop_front();
			idxQueue.pop_front();
		}
			
		// ���뵱ǰԪ��
		monoQueue.push_back(num[i]);
		idxQueue.push_back(i);

		// �ɼ����ֵ
		resVec.push_back(monoQueue.front());
	}

	return resVec;
}

void maxInWindows_Solution::demo()
{
	vector<int> numSec = initializer_list<int>{ -7, -8, 7, 5, 7, 1, 6, 0 };
	int size = 4;

	vector<int> resSec = this->maxInWindows(numSec, size);
	for (int i = 0; i < resSec.size(); ++i) {
		cout << resSec[i] << " ";
	}
	cout << endl;
}

vector<int> GetLeastNumbers_Solution::getLeastNumbers(vector<int>& input, int k)
{
	vector<int> resVec;
	if (k <= 0 || input.empty())
		return resVec;

	// ʹ�����ȶ����ݴ���������С��K��Ԫ��
	priority_queue<int, vector<int>> priQueue;
	for (int i = 0; i < input.size(); ++i) {
		if (priQueue.size() < k) {
			// ���ȶ���Ԫ�ظ���������k��������Ҫ���ֱ�������ȶ������Ԫ��
			priQueue.push(input[i]);
		}
		else {
			if (priQueue.top() > input[i]) {
				// ����Ԫ�رȵ�ǰԪ�ش�͵�������Ԫ��
				priQueue.pop();
				priQueue.push(input[i]);
			}	
		}
	}

	// ���ȶ��и�ֵ�����������
	resVec.resize(k);
	for (int i = 0; i < k && !priQueue.empty(); ++i) {
		resVec[k - i - 1] = priQueue.top();
		priQueue.pop();
	}
	return resVec;
}

void GetLeastNumbers_Solution::demo()
{
	vector<int> input = initializer_list<int>{4, 5, 1, 6, 2, 7, 3, 8};
	vector<int> res = this->getLeastNumbers(input, 4);
	for (int i = 0; i 
< res.size(); ++i) {
		cout << res[i] << " ";
	}
	cout << endl;
}

int findKth_Solution::findKth(vector<int>& a, int n, int K)
{
	if (n <= 0 || a.empty() || K <= 0)
		return -1;

	// ���ȶ��в���С����
	priority_queue<int, vector<int>, greater<int>> priQueue;
	for (int i = 0; i < n; ++i) {
		if (priQueue.size() < K) {
			priQueue.push(a[i]);
		}
		else if(!priQueue.empty() && priQueue.top() < a[i]) {
			priQueue.pop();
			priQueue.push(a[i]);
		}
	}

	// �ڱ�֤������ֻ��K��Ԫ��ʱ���Ѷ�Ϊ��ǰ��СԪ�أ�Ҳ���ǵ�K���Ԫ��
	if (priQueue.size() != K) {
		return -1;
	}	
	else {
		return priQueue.top();
	}
}

void findKth_Solution::demo()
{
	vector<int> vec = initializer_list<int>{ 1, 3, 5, 2, 2};
	cout << this->findKth(vec, 5, 3) << endl;
}


void StreamMid_Solution::Insert(int num)
{
	// ���ݲ���
	if (m_bigTopHeap.empty() || num <= m_bigTopHeap.top()) {
		m_bigTopHeap.push(num);
	}
	else {
		m_smallTopHeap.push(num);
	}

	// �󶥶���С����Ԫ�ظ�������
	int diff = m_bigTopHeap.size() - m_smallTopHeap.size();
	if (diff > 1) {
		m_smallTopHeap.push(m_bigTopHeap.top());
		m_bigTopHeap.pop();
	}
	else if (diff < -1) {
		m_bigTopHeap.push(m_smallTopHeap.top());
		m_smallTopHeap.pop();
	}
}

double StreamMid_Solution::GetMedian()
{	
	int size = (m_smallTopHeap.size() + m_bigTopHeap.size());
	if (0 == size % 2) {
		// ż����Ԫ��
		return ((double)m_smallTopHeap.top() + (double)m_bigTopHeap.top()) / 2;
	}
	else {
		// ������Ԫ��
		return (m_smallTopHeap.size() > m_bigTopHeap.size()) ? m_smallTopHeap.top() : m_bigTopHeap.top();
	}
}

void StreamMid_Solution::demo()
{
	vector<int> vec = initializer_list<int>{5, 2, 3, 4, 1, 6, 7, 0, 8};
	for (int i = 0; i < vec.size(); ++i) {
		this->Insert(vec[i]);
		cout << this->GetMedian() << " ";
	}
	cout << endl;
}

int ExpressionEvaluation_Solution::solve(string s)
{
	if (s.empty())
		return -1;

	// pair�Ե�firstΪ����ֵ���, secondΪ��ǰ�����ַ���s������
	pair<int, int> res = this->getResult(s, 0);
	return res.first;
}

pair<int, int> ExpressionEvaluation_Solution::getResult(const string& s, int idx)
{
	stack<int> valStack;
	int num = 0;
	char op = '+';

	int i = idx;
	for (; i < s.size(); ++i) {	
		if (isdigit(s[i])) {
			// �ж��Ƿ�Ϊ����
			num = (num * 10) + (s[i] - '0');

			// �ж��Ƿ񵽴��ַ���ĩβ
			if (i != s.size() - 1)
				continue;
		}
		else if ('(' == s[i]) {
			// �������ȼ���, �ݹ鴦��
			pair<int, int> res = this->getResult(s, i + 1);
			num = res.first;
			i = res.second;

			// �ж��Ƿ񵽴��ַ���ĩβ
			if (i != s.size() - 1)
				continue;
		}
		
		// ������
		switch (op) {
			case '+': {
				valStack.push(num);
				break;
			}
			case '-': {
				valStack.push(-num);
				break;
			}
			case '*': {
				num = valStack.top() * num;
				valStack.pop();
				valStack.push(num);
				break;
			}
		}

		// ��������ֵ
		op = s[i];
		num = 0;

		if (')' == s[i]) {
			// �����������ţ������ݹ�
			break;
		}
	}

	while (!valStack.empty()) {
		num += valStack.top();
		valStack.pop();
	}
	return pair<double, int>(num, i);
}

void ExpressionEvaluation_Solution::demo()
{
	string s = "(2*(3-4))*5";
	cout << this->solve(s) << endl;

	s = "1+2";
	cout << this->solve(s) << endl;

	s = "3+2*3*4-1";
	cout << this->solve(s) << endl;
}