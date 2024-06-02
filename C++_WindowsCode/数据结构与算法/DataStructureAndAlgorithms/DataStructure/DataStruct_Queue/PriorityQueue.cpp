#include "PriorityQueue.h"

void BigTopPriorityQueue::push(int val)
{
	m_queue.push_back(val);
	this->adjust();
}

int BigTopPriorityQueue::top()
{
	try {
		if (m_queue.empty()) {
			throw "Queue Is Empty. Get Top Value Error";
		}		
		else {
			return m_queue[0];
		}
	}
	catch (const string& err) {
		cerr << err << endl;
	}
}

void BigTopPriorityQueue::pop()
{
	try {
		if (m_queue.empty()) {
			throw "Queue Is Empty. Get Top Value Error";
		}
		else {
			// ������һ��Ԫ�غ����һ��Ԫ�ص�˳�򣬼��������ƶ�������
			swap(m_queue[0], m_queue[m_queue.size() - 1]);
			m_queue.erase(--m_queue.end());
			this->adjust();
		}
	}
	catch (const string& err) {
		cerr << err << endl;
	}
}

void BigTopPriorityQueue::adjust()
{
	// һ�λ�ȡ�������������ʹ��
	int size = m_queue.size();

	int lastNotLeafNodeIdx = (size / 2) - 1;
	for (int i = lastNotLeafNodeIdx; i >= 0; --i) {
		int curLeftChildIdx = 2 * i + 1;

		// ���ӽڵ�������������Ч��Χ�������ӽڵ���ڵ�ǰ�ڵ�
		if (curLeftChildIdx >= 0 && curLeftChildIdx < size && m_queue[curLeftChildIdx] > m_queue[i]) {
			swap(m_queue[i], m_queue[curLeftChildIdx]);
			
			// �ݹ����
			this->adjust();
		}

		int curRightChildIdx = 2 * i + 2;
		// �Һ��ӽڵ�������������Ч��Χ�����Һ��ӽڵ���ڵ�ǰ�ڵ�
		if (curRightChildIdx >= 0 && curRightChildIdx < size && m_queue[curRightChildIdx] > m_queue[i]) {
			swap(m_queue[i], m_queue[curRightChildIdx]);

			// �ݹ����
			this->adjust();
		}
	}
}

void SmallTopPriorityQueue::push(int val)
{
	m_queue.push_back(val);
	this->adjust();
}

int SmallTopPriorityQueue::top()
{
	try {
		if (m_queue.empty()) {
			throw "Queue Is Empty. Get Top Value Error";
		}
		else {
			return m_queue[0];
		}
	}
	catch (const string& err) {
		cerr << err << endl;
	}
}

void SmallTopPriorityQueue::pop()
{
	try {
		if (m_queue.empty()) {
			throw "Queue Is Empty. Get Top Value Error";
		}
		else {
			// ������һ��Ԫ�غ����һ��Ԫ�ص�˳�򣬼��������ƶ�������
			swap(m_queue[0], m_queue[m_queue.size() - 1]);
			m_queue.erase(--m_queue.end());
			this->adjust();
		}
	}
	catch (const string& err) {
		cerr << err << endl;
	}
}

void SmallTopPriorityQueue::adjust()
{
	// һ�λ�ȡ�������������ʹ��
	int size = m_queue.size();

	int lastNotLeafNodeIdx = (size / 2) - 1;
	for (int i = lastNotLeafNodeIdx; i >= 0; --i) {
		int curLeftChildIdx = 2 * i + 1;

		// ���ӽڵ�������������Ч��Χ�������ӽڵ�С�ڵ�ǰ�ڵ�
		if (curLeftChildIdx >= 0 && curLeftChildIdx < size && m_queue[curLeftChildIdx] < m_queue[i]) {
			swap(m_queue[i], m_queue[curLeftChildIdx]);

			// �ݹ����
			this->adjust();
		}

		int curRightChildIdx = 2 * i + 2;
		// �Һ��ӽڵ�������������Ч��Χ�����Һ��ӽڵ�С�ڵ�ǰ�ڵ�
		if (curRightChildIdx >= 0 && curRightChildIdx < size && m_queue[curRightChildIdx] < m_queue[i]) {
			swap(m_queue[i], m_queue[curRightChildIdx]);

			// �ݹ����
			this->adjust();
		}
	}
}