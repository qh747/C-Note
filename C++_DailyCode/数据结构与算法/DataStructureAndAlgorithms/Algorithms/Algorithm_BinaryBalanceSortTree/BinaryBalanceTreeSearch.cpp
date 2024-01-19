#include "BinaryBalanceTreeSearch.h"

/*����ƽ�����������ܲ���					**/
void funcCallBinaryBalanceTreeSearch()
{
	vector<int> intVec = initializer_list<int>{ 0, 33, 21, 51, 98, 65, 71 ,18, 45, 100, 32, 27, 78, 91, 73, 999 };
	BinaryBalanceTree binBanlanceTree;
	binBanlanceTree.createTree(intVec);

	cout << "Test Vec: ";
	for_each(intVec.begin(), intVec.end(), [](const int& val) { cout << val << " "; });
	cout << endl;

	/*��һ�����ݲ���												**/
	cout << "Val " << 33 << " In ";
	int fstValIndex = binBanlanceTree.getIndex(33);
	cout << fstValIndex << endl;

	/*�ڶ������ݲ���												**/
	cout << "Val " << 71 << " In ";
	int secValIndex = binBanlanceTree.getIndex(71);
	cout << secValIndex << endl;

	/*���������ݲ���												**/
	cout << "Val " << 100 << " In ";
	int trdValIndex = binBanlanceTree.getIndex(100);
	cout << trdValIndex << endl;

	/*���������ݲ���												**/
	cout << "Val " << 77 << " In ";
	int forthValIndex = binBanlanceTree.getIndex(77);
	cout << forthValIndex << endl;
}


/*����ƽ��������							**/
BinaryBalanceTree::BinaryBalanceTree()
{
	m_pRootNode = nullptr;
}

BinaryBalanceTree::~BinaryBalanceTree()
{
	if (nullptr != m_pRootNode)
		this->destoryTree(m_pRootNode);
}

void BinaryBalanceTree::createTree(const vector<int>& vec)
{
	for (int i = 0; i < vec.size(); ++i)
	{
		this->insertNode(m_pRootNode, vec[i], i);
	}
}

bool BinaryBalanceTree::insertNode(BinBalanceNode*& pNode, int val, int idx)
{
	if (nullptr == pNode)
	{
		/*�����½ڵ�, �洢����Ԫ��										**/
		pNode = new BinBalanceNode(val, idx, 0, nullptr, nullptr);
		return true;
	}
	
	if (pNode->iVal == val)
	{
		/*�ڵ��Ѵ���, ����ʧ��											**/
		return false;
	}
	else if (val < pNode->iVal)
	{
		/*�����½ڵ�													**/
		bool res = this->insertNode(pNode->pLeftChildNode, val, idx);
		if (!res)
			return false;

		/*�½ڵ����ɹ�, ����λ����Ϣ									**/
		this->updateHeight(pNode);

		/*�жϵ�ǰ�ڵ�����������������߶�								**/
		int leftHeight = (nullptr != pNode->pLeftChildNode) ? pNode->pLeftChildNode->iHeight : 0;
		int rightHeight = (nullptr != pNode->pRightChildNode) ? pNode->pRightChildNode->iHeight : 0;
		int heightDiff = leftHeight - rightHeight;
		if (heightDiff > 1)
		{
			/*�������߶ȳ����������߶�, ������������					**/
			this->rollTreeByRR(pNode);
		}
		else if (heightDiff < -1)
		{
			/*�������߶ȵ����������߶�, �Ƚ�����������, �ٽ�����������	**/
			this->rollTreeByLR(pNode);
		}

		return true;
	}
	else if (val > pNode->iVal)
	{
		/*�����½ڵ�													**/
		bool res = this->insertNode(pNode->pRightChildNode, val, idx);
		if (!res)
			return false;

		/*�½ڵ����ɹ�, ����λ����Ϣ									**/
		this->updateHeight(pNode);

		/*�жϵ�ǰ�ڵ�����������������߶�								**/
		int leftHeight = (nullptr != pNode->pLeftChildNode) ? pNode->pLeftChildNode->iHeight : 0;
		int rightHeight = (nullptr != pNode->pRightChildNode) ? pNode->pRightChildNode->iHeight : 0;
		int heightDiff = leftHeight - rightHeight;
		if (heightDiff > 1)
		{
			/*�������߶ȳ����������߶�, �Ƚ�����������, �ٽ�����������	**/
			this->rollTreeByRL(pNode);
		}
		else if (heightDiff < -1)
		{
			/*�������߶ȵ����������߶�, ������������					**/
			this->rollTreeByLL(pNode);
		}

		return true;
	}
	else
		return false;
}

int BinaryBalanceTree::getIndex(int val)
{
	BinBalanceNode* pNode = m_pRootNode;
	while (nullptr != pNode)
	{
		if (pNode->iVal == val)
			return pNode->iIndex;
		else if (val < pNode->iVal)
			pNode = pNode->pLeftChildNode;
		else
			pNode = pNode->pRightChildNode;
	}

	return -1;
}

void BinaryBalanceTree::updateHeight(BinBalanceNode* pNode)
{
	if (nullptr == pNode)
		return;
	else
	{
		/*��ȡ��ǰ�ڵ�����ӽڵ�߶�					**/
		int leftHeight = (nullptr != pNode->pLeftChildNode) ? pNode->pLeftChildNode->iHeight : 0;

		/*��ȡ��ǰ�ڵ���Һ��ӽڵ�߶�					**/
		int rightHeight = (nullptr != pNode->pRightChildNode) ? pNode->pRightChildNode->iHeight : 0;

		/*��ǰ�ڵ�ĸ߶�Ϊ���Һ��ӽڵ�߶����ֵ + 1	**/
		pNode->iHeight = max(leftHeight, rightHeight) + 1;
	}
}

int	BinaryBalanceTree::getHeight(BinBalanceNode* pNode)
{
	if (nullptr == pNode)
		return 0;
	else
		return pNode->iHeight;
}

void BinaryBalanceTree::rollTreeByLL(BinBalanceNode*& pNode)
{
	BinBalanceNode* pRootNode = pNode;

	/*������ǰ�ڵ���Һ��ӽڵ�							**/
	BinBalanceNode* pUpNode = pNode->pRightChildNode;

	/*��ǰ�ڵ���Һ��ӽڵ�ָ������ڵ�����ӽڵ�		**/
	pRootNode->pRightChildNode = pUpNode->pLeftChildNode;

	/*�����ڵ�����ӽڵ�ָ��ǰ�ڵ�					**/
	pUpNode->pLeftChildNode = pRootNode;

	/*��ǰ�ڵ��޸�ָ��Ϊ�����ڵ�						**/
	pNode = pUpNode;

	/*���½ڵ�߶�										**/
	this->updateHeight(pUpNode->pLeftChildNode);
	this->updateHeight(pUpNode->pRightChildNode);
	this->updateHeight(pUpNode);
}

void BinaryBalanceTree::rollTreeByRR(BinBalanceNode*& pNode)
{
	BinBalanceNode* pRootNode = pNode;

	/*������ǰ�ڵ�����ӽڵ�							**/
	BinBalanceNode* pUpNode = pNode->pLeftChildNode;

	/*��ǰ�ڵ�����ӽڵ�ָ������ڵ���Һ��ӽڵ�		**/
	pNode->pLeftChildNode = pUpNode->pRightChildNode;

	/*�����ڵ���Һ��ӽڵ�ָ��ǰ�ڵ�					**/
	pUpNode->pRightChildNode = pNode;

	/*��ǰ�ڵ��޸�ָ��Ϊ�����ڵ�						**/
	pNode = pUpNode;

	/*���½ڵ�߶�										**/
	this->updateHeight(pUpNode->pLeftChildNode);
	this->updateHeight(pUpNode->pRightChildNode);
	this->updateHeight(pUpNode);
}

void BinaryBalanceTree::rollTreeByLR(BinBalanceNode*& pNode)
{
	/*�Ƚ���ǰ�ڵ�����ӽڵ���Ϊ���ڵ������������	**/
	this->rollTreeByLL(pNode->pLeftChildNode);

	this->updateHeight(pNode->pLeftChildNode);
	this->updateHeight(pNode->pRightChildNode);
	this->updateHeight(pNode);

	/*�ٽ���ǰ�ڵ���Ϊ���ڵ������������				**/
	this->rollTreeByRR(pNode);

	this->updateHeight(pNode->pLeftChildNode);
	this->updateHeight(pNode->pRightChildNode);
	this->updateHeight(pNode);
}

void BinaryBalanceTree::rollTreeByRL(BinBalanceNode*& pNode)
{
	/*�Ƚ���ǰ�ڵ���Һ��ӽڵ���Ϊ���ڵ������������	**/
	this->rollTreeByRR(pNode->pRightChildNode);

	this->updateHeight(pNode->pLeftChildNode);
	this->updateHeight(pNode->pRightChildNode);
	this->updateHeight(pNode);

	/*�ٽ���ǰ�ڵ���Ϊ���ڵ������������				**/
	this->rollTreeByLL(pNode);

	this->updateHeight(pNode->pLeftChildNode);
	this->updateHeight(pNode->pRightChildNode);
	this->updateHeight(pNode);
}

void BinaryBalanceTree::destoryTree(BinBalanceNode* pNode)
{
	if (nullptr == pNode)
		return;

	this->destoryTree(pNode->pLeftChildNode);
	this->destoryTree(pNode->pRightChildNode);

	delete pNode;
}