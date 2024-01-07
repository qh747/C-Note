#include "BinaryTree.h"

BinaryTree::BinaryTree()
{
	m_leafNodeCount = 0;
	m_pRootNode = nullptr;
	m_nodeMgmtVec.clear();
}

BinaryTree::~BinaryTree()
{
	if (m_pRootNode)
	{
		this->freeTree(&m_pRootNode);
		m_pRootNode = nullptr;
	}
}

bool BinaryTree::addNewNode(int val)
{
	BTreeNode_dt* pNewNode = new BTreeNode_dt(val);
	if (m_nodeMgmtVec.empty())
	{
		/*�ڵ��������Ϊ��, �������ڵ�							**/
		m_nodeMgmtVec.push_back(pNewNode);
		m_pRootNode = pNewNode;
		
		return true;
	}
	else
	{
		/*�ڵ�������鲻Ϊ��, ���ҿɲ���Ľڵ�						**/
		BTreeNode_dt* pParentNode = nullptr;
		for (int i = 0; i < m_nodeMgmtVec.size(); ++i)
		{
			BTreeNode_dt* pCurNode = m_nodeMgmtVec[i];

			/*����ɲ���ڵ��Ҫ�������ӻ��Һ��ӽڵ�Ϊ��			**/
			if (!pCurNode->pLeftNode || !pCurNode->pRightNode)
			{
				pParentNode = pCurNode;
				break;
			}
		}

		if (pParentNode)
		{
			/*�ҵ��ɲ���ڵ�										**/
			if (!pParentNode->pLeftNode)
				pParentNode->pLeftNode = pNewNode;
			else
				pParentNode->pRightNode = pNewNode;

			/*�ڵ����												**/
			m_nodeMgmtVec.push_back(pNewNode);

			return true;
		}
		else
		{
			delete pNewNode;
			cerr << "Binary Tree Error. Can Not Find valid Node To Insert." << endl;

			return false;
		}
	}
}

int	BinaryTree::getLeafNodeCount()
{
	/*���֮ǰͳ�Ƶ�Ҷ�ӽڵ�����Ļ���								**/
	m_leafNodeCount = 0;

	/*������������ڵ�, �ݹ����Ҷ�ӽڵ����						**/
	this->countLeafNode(m_pRootNode);

	/*Ҷ�ӽڵ�����ڵݹ�������Ѿ�ͳ�����, �ѱ���ֵ, ����ֱ�ӷ���	**/
	return m_leafNodeCount;
}

int BinaryTree::getTreeDepth()
{
	int treeDepth = this->countTreeDepth(m_pRootNode);
	return treeDepth;
}

void BinaryTree::foreachTree(BtreeForach_t type)
{
	cout << "Binary Tree Start Foreach: ";
	this->BinaryTree::foreachTree(m_pRootNode, type);
	cout << endl;
}

BinaryTree* BinaryTree::copyBinaryTree()
{
	BinaryTree* pNewTree = new BinaryTree();
	pNewTree->m_pRootNode = BinaryTree::copyBinaryTree(m_pRootNode, pNewTree->m_nodeMgmtVec);

	return pNewTree;
}

void BinaryTree::freeTree(BTreeNode_dt** pRootNodeAddr)
{
	if (!(*pRootNodeAddr))
		return;
	else if((*pRootNodeAddr)->pLeftNode || (*pRootNodeAddr)->pRightNode)
	{
		/*���ͷŵ�ǰ�ڵ��Ҷ�ӽڵ�									**/
		this->freeTree(&((*pRootNodeAddr)->pLeftNode));
		this->freeTree(&((*pRootNodeAddr)->pRightNode));
	}
	
	/*�ͷŵ�ǰ�ڵ�													**/
	delete* pRootNodeAddr;
	*pRootNodeAddr = nullptr;
}

int BinaryTree::countLeafNode(BTreeNode_dt* pRootNode)
{
	if (!pRootNode)
		return 0;
	else if (!pRootNode->pLeftNode && !pRootNode->pRightNode)
	{
		++m_leafNodeCount;
		return m_leafNodeCount;
	}
	else
	{
		countLeafNode(pRootNode->pLeftNode);
		countLeafNode(pRootNode->pRightNode);
		return m_leafNodeCount;
	}
}

int BinaryTree::countTreeDepth(BTreeNode_dt* pRootNode)
{
	if (!pRootNode)
		return 0;
	else if (!pRootNode->pLeftNode && !pRootNode->pRightNode)
		return 1;
	else
	{
		int leftDepth = this->countTreeDepth(pRootNode->pLeftNode);
		int rightDepth = this->countTreeDepth(pRootNode->pRightNode);

		int curDepth = (leftDepth >= rightDepth) ? ++leftDepth : ++rightDepth;
		return curDepth;
	}
}

void BinaryTree::foreachTree(BTreeNode_dt* pRootNode, BtreeForach_t type)
{
	if (!pRootNode)
		return;
	
	if (FIRST_SEQ_FOREACH == type)
	{
		/*�������: ������											**/
		cout << pRootNode->iData << " ";
		this->foreachTree(pRootNode->pLeftNode, type);
		this->foreachTree(pRootNode->pRightNode, type);
	}
	else if (MIDDLE_SEQ_FOREACH == type)
	{
		/*�������: �����											**/
		this->foreachTree(pRootNode->pLeftNode, type);
		cout << pRootNode->iData << " ";
		this->foreachTree(pRootNode->pRightNode, type);
	}
	else
	{
		/*�������: ���Ҹ�											**/
		this->foreachTree(pRootNode->pLeftNode, type);
		this->foreachTree(pRootNode->pRightNode, type);
		cout << pRootNode->iData << " ";
	}
}

BTreeNode_dt* BinaryTree::copyBinaryTree(BTreeNode_dt* pRootNode, vector<BTreeNode_dt*>& nodeMgmtVec)
{
	if (!pRootNode)
		return nullptr;
	else
	{
		BTreeNode_dt* pRightNode = this->copyBinaryTree(pRootNode->pRightNode, nodeMgmtVec);
		BTreeNode_dt* pLeftNode = this->copyBinaryTree(pRootNode->pLeftNode, nodeMgmtVec);

		BTreeNode_dt* pNewNode = new BTreeNode_dt(pRootNode->iData);
		pNewNode->pLeftNode = pLeftNode;
		pNewNode->pRightNode = pRightNode;

		nodeMgmtVec.insert(nodeMgmtVec.begin(), 1, pNewNode);

		return pNewNode;
	}
}