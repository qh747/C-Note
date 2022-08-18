#include <iostream>
#include <stack>
#include <cstdlib>
using namespace std;

/*�������ڵ�ṹ    **/
struct BTreeNode
{
	char m_data;
	BTreeNode* m_leftChildPtr;
	BTreeNode* m_rightChildPtr;

	BTreeNode() 
	{
		memset(this, 0, sizeof(BTreeNode));
	}

	BTreeNode(char data, BTreeNode* leftPtr = NULL, BTreeNode* rightPtr = NULL) : m_data(data), m_leftChildPtr(leftPtr), m_rightChildPtr(rightPtr)
	{

	}

	~BTreeNode()
	{
		cout << "Destory Node: " << m_data << endl;
	}
};

/*�����������ڵ�ṹ    **/
struct BTreeForeachNode
{
	BTreeNode* m_curNodePtr;
	bool m_flag;
};

/*�������ǵݹ����    **/
void foreachBTree(BTreeNode* curRoot);

/*�������ͷź���    **/
void freeBTree(BTreeNode* curRoot);

/*��������������    **/
BTreeNode* buildBTree();

int main()
{
	BTreeNode* pBTree = buildBTree();
	if (NULL != pBTree)
	{
		foreachBTree(pBTree);

		cout << endl;

		freeBTree(pBTree);
	}

	system("pause");
	return 0;
}

/*�������ǵݹ����    **/
void foreachBTree(BTreeNode* curRoot)
{
	BTreeForeachNode node;
	node.m_curNodePtr = curRoot;
	node.m_flag = false;

	stack<BTreeForeachNode> foreachStack;
	foreachStack.push(node);

	while (false == foreachStack.empty())
	{
		BTreeForeachNode popNode = foreachStack.top();
		foreachStack.pop();

		if (false == popNode.m_flag)
		{
			/*ѹ�뵱ǰ�ڵ���������ڵ�    **/
			if (NULL != popNode.m_curNodePtr->m_rightChildPtr)
			{
				BTreeForeachNode rightNode;
				rightNode.m_curNodePtr = popNode.m_curNodePtr->m_rightChildPtr;
				rightNode.m_flag = false;

				foreachStack.push(rightNode);
			}

			/*ѹ�뵱ǰ�ڵ���������ڵ�    **/
			if (NULL != popNode.m_curNodePtr->m_leftChildPtr)
			{
				BTreeForeachNode leftNode;
				leftNode.m_curNodePtr = popNode.m_curNodePtr->m_leftChildPtr;
				leftNode.m_flag = false;

				foreachStack.push(leftNode);
			}

			/*ѹ�뵱ǰ�ڵ�    **/
			popNode.m_flag = true;
			foreachStack.push(popNode);
		}
		else
		{
			cout << "Current Node: " << popNode.m_curNodePtr->m_data << endl;
		}
	}
}

/*�������ͷź���    **/
void freeBTree(BTreeNode* curRoot)
{
	if (NULL == curRoot)
		return;
	else
	{
		freeBTree(curRoot->m_leftChildPtr);
		freeBTree(curRoot->m_rightChildPtr);

		delete curRoot;
		curRoot = NULL;
	}
}

/*��������������    **/
BTreeNode* buildBTree()
{
	BTreeNode* pRootNode = new BTreeNode('a');
	BTreeNode* pFstNode = new BTreeNode('b');
	BTreeNode* pSecNode = new BTreeNode('c');
	BTreeNode* pThrNode = new BTreeNode('d');
	BTreeNode* pFourNode = new BTreeNode('e');
	BTreeNode* pFiveNode = new BTreeNode('f');
	BTreeNode* pSixNode = new BTreeNode('g');

	pRootNode->m_leftChildPtr = pFstNode;
	pRootNode->m_rightChildPtr = pSecNode;

	pFstNode->m_leftChildPtr = pThrNode;
	pFstNode->m_rightChildPtr = pFourNode;

	pSecNode->m_leftChildPtr = pFiveNode;
	pSecNode->m_rightChildPtr = pSixNode;

	return pRootNode;
}