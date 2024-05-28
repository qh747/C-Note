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