#pragma once
#include <iostream>
#include <vector>
using namespace std;

/*��������������															**/
typedef enum TYPE_BTREE_FOREACH
{
	FIRST_SEQ_FOREACH				= 0,									// �������
	MIDDLE_SEQ_FOREACH				= 1,									// �������
	LAST_SEQ_FOREACH				= 2,									// �������

}BtreeForach_t;

/*�������ڵ�����															**/
typedef struct DATA_TYPE_BINARY_TREE_NODE
{
	int								iData;
	DATA_TYPE_BINARY_TREE_NODE*		pLeftNode;
	DATA_TYPE_BINARY_TREE_NODE*		pRightNode;

	DATA_TYPE_BINARY_TREE_NODE()
	{
		memset(this, 0, sizeof(DATA_TYPE_BINARY_TREE_NODE));
	}

	DATA_TYPE_BINARY_TREE_NODE(int data)
	{
		this->iData					= data;
		this->pLeftNode				= NULL;
		this->pRightNode			= NULL;
	}

}BTreeNode_dt;

/*������																	**/
class BinaryTree
{
public:
	BinaryTree();
	~BinaryTree();

public:
	bool						addNewNode(int val);															// ����½ڵ�
	int							getLeafNodeCount();																// ��ȡҶ�ӽڵ����
	int							getTreeDepth();																	// ��ȡ���������
	void						foreachTree(BtreeForach_t type);												// ����������
	BinaryTree*					copyBinaryTree();																// ����������

private:
	void						freeTree(BTreeNode_dt** pRootNodeAddr);											// �ͷŶ�����
	int							countLeafNode(BTreeNode_dt* pRootNode);											// ͳ��Ҷ�ӽڵ�(���ڲ�ʹ��)
	int							countTreeDepth(BTreeNode_dt* pRootNode);										// ��ȡ�����������(���ڲ�ʹ��)
	void						foreachTree(BTreeNode_dt* pRootNode, BtreeForach_t type);						// ����������(���ڲ�ʹ��)
	BTreeNode_dt*				copyBinaryTree(BTreeNode_dt* pRootNode, vector<BTreeNode_dt*>& nodeMgmtVec);	// ����������

private:
	BTreeNode_dt*				m_pRootNode;																	// ���������ڵ�
	vector<BTreeNode_dt*>		m_nodeMgmtVec;																	// ��������������
	int							m_leafNodeCount;																// ������Ҷ�ӽڵ����
};