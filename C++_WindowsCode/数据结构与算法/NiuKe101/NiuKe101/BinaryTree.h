#pragma once
#pragma warning(disable: 4996)
#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <cstring>
#include <string>
#include <sstream>
#include <algorithm>
using std::cout;
using std::endl;
using std::initializer_list;
using std::vector;
using std::queue;
using std::string;
using std::stringstream;

// �������ڵ�����
struct TreeNode 
{
	int val;
	TreeNode *left;
	TreeNode *right;

	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// ����������
void preorder(TreeNode* root);
void inorder(TreeNode* root);
void postorder(TreeNode* root);

// ���ٶ�����
void cycle(TreeNode* root);

// BM1  -��������ǰ�����
class preorderTraversal_Solution 
{
public:
	vector<int> preorderTraversal(TreeNode* root);
	void preorder(TreeNode* root, vector<int>& vec);
	void preorderTraversalTest();
};

// BM2  -���������������
class inorderTraversal_Solution 
{
public:
	vector<int> inorderTraversal(TreeNode* root);
	void inorder(TreeNode* root, vector<int>& vec);
	void inorderTraversalTest();
};

// BM3  -�������ĺ������
class postorderTraversal_Solution
{
public:
	vector<int> postorderTraversal(TreeNode* root);
	void postorder(TreeNode* root, vector<int>& vec);
	void postorderTraversalTest();
};

// BM6 - ��������������
class maxDepth_Solution 
{
public:
	int maxDepth(TreeNode* root);
	void maxDepthTest();
};

// BM8 - ������������˫������
class Convert_Solution 
{
public:
	TreeNode* Convert(TreeNode* pRootOfTree);
	void ConvertTest();

private:
	TreeNode* pCur = nullptr;
	TreeNode* pPrev = nullptr;
};

// BM10 - �ϲ�������
class mergeTrees_Solution
{
public:
	TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2);
	void mergeTreesTest();
	void preorder(TreeNode* root);
	void recycle(TreeNode* root);
};

// BM11 - �������ľ���
class Mirror_Solution 
{
public:
	TreeNode* Mirror(TreeNode* pRoot);
	void MirrorTest();
};

// BM12 - �ж��Ƿ�Ϊ����������
class isValidBST_Solution 
{
public:
	bool isValidBST(TreeNode* root);
	void isValidBSTTest();

private:
	long pre = LONG_MIN;
};

// BM13 - �ж��Ƿ�Ϊ��ȫ������
class isCompleteTree_Solution
{
public:
	bool isCompleteTree(TreeNode* root);
	void isCompleteTreeTest();
};

// BM14 - �ж��Ƿ�Ϊƽ�������
class IsBalancedTree_Solution 
{
public:
	bool IsBalancedTree(TreeNode* pRoot);
	int getTreeDepth(TreeNode* pRoot);
	void IsBalancedTreeTest();
};

// BM15 - �����������Ĺ�������
class lowestCommonAncestor_Solution
{
public:
	int lowestCommonAncestor(TreeNode* root, int p, int q);
	void lowestCommonAncestorTest();
};

// BM17 - ���л�������
class Serialize_Solution 
{
public:
	char* Serialize(TreeNode* root);
	void serialHelp(TreeNode* root, stringstream& ss);

	TreeNode* Deserialize(char* str);
	TreeNode* deSerialHelp(queue<int>& que);

public:
	void demo();
};

// BM18 - �ؽ�������
class reConstructBinaryTree_Solution 
{
public:
	TreeNode* reConstructBinaryTree(vector<int>& preOrder, vector<int>& inOrder);
	TreeNode* reConstructHelp(vector<int>& preOrder, int plPos, int prPos, vector<int>& inOrder, int vlPos, int vrPos);

	void demo();
};

// BM19 - ���������������ͼ
class solve_Solution 
{
public:
	vector<int> solve(vector<int>& preOrder, vector<int>& inOrder);
	TreeNode* buildTree(vector<int>& preOrder, int pStart, int pEnd, vector<int>& inOrder, int iStart, int iEnd);
	void getTreeRightView(TreeNode* root, vector<int>& rightView);

public:
	void demo();
};