#include "LinkList.h"
#include "BinarySearch.h"
#include "BinaryTree.h"
#include "HeapStackQueue.h"
#include "HashAlg.h"
#include "RecursionAlg.h"
#include "DynamicPrograming.h"
#include "GreedyAlgorithm.h"

// ������Ժ���
void fundLinkTest() 
{
	// ��ת����
	// ReverseLinkList_Solution solu;
	// solu.ReverseListTest();

	// ������ָ�����䷴ת
	// ReverseBetween_Solution solu;
	// solu.ReverseBetweenTest();

	// �ϲ��������������
	// Merge_Solution solu;
	// solu.MergeTest();

	// �ϲ�K�������������
	// mergeKLists_Solution solu;
	// solu.mergeKListsTest();

	// �ж��������Ƿ��л�
	// HasCycle_Solution solu;
	// solu.hasCycleTest();

	// �����л�����ڽڵ�
	// EntryNodeOfLoop_Solution solu;
	// solu.EntryNodeOfLoopTest();

	// �����е������K���ڵ�
	// FindKthToTail_Solution solu;
	// solu.FindKthToTailTest();

	// ��������ĵ�һ�������ڵ�
	// FindFirstCommonNode_Solution solu;
	// solu.FindKthToTailTest();

	// ������ӣ�����
	// addInList_Solution solu;
	// solu.addInListTest();

	// �����������
	// sortInList_Solution solu;
	// solu.sortInListTest();

	// �ж�һ�������Ƿ�Ϊ���Ľṹ
	// isPail_Solution solu;
	// solu.isPailTest();

	// �������ż����
	// oddEvenList_Solution solu;
	// solu.oddEvenListTest();

	// ɾ�������������ظ���Ԫ��-I
	// deleteDuplicates_Solution solu;
	// solu.deleteDuplicatesTest();

	// ɾ�������������ظ���Ԫ��-II
	// deleteDuplicatesII_Solution solu;
	// solu.deleteDuplicatesIITest();
}

// ���ֲ��Ҳ��Ժ���
void binarySearchTest() 
{
	// BM1 - ���ֲ���-I
	// search_Solution solu;
	// solu.searchTest();

	// BM3 - Ѱ�ҷ�ֵ
	// findPeakElement_Solution solu;
	// solu.findPeakElementTest();

	// BM4 - �����е������
	// InversePairs_Solution solu;
	// solu.InversePairsTest();

	// BM5 - ��ת�������С����
	// minNumberInRotateArray_Solution solu;
	// solu.minNumberInRotateArrayTest();

	// BM6 - �Ƚϰ汾��
	compare_Solution solu;
	solu.compareTest();
}

// ���������Ժ���
void binaryTreeTest() 
{
	// BM1 - ��������ǰ�����
	// preorderTraversal_Solution solu;
	// solu.preorderTraversalTest();

	// BM2  -���������������
	// inorderTraversal_Solution solu;
	// solu.inorderTraversalTest();

	// BM3  -�������ĺ������
	// postorderTraversal_Solution solu;
	// solu.postorderTraversalTest();

	// BM6 - ��������������
	// maxDepth_Solution solu;
	// solu.maxDepthTest();

	// BM8 - ������������˫������
	// Convert_Solution solu;
	// solu.ConvertTest();

	// BM10 - �ϲ�������
	// mergeTrees_Solution solu;
	// solu.mergeTreesTest();

	// BM11 - �������ľ���
	// Mirror_Solution solu;
	// solu.MirrorTest();

	// BM12 - �ж��Ƿ�Ϊ����������
	// isValidBST_Solution solu;
	// solu.isValidBSTTest();

	// BM13 - �ж��Ƿ�Ϊ��ȫ������
	// isCompleteTree_Solution solu;
	// solu.isCompleteTreeTest();

	// BM14 - �ж��Ƿ�Ϊƽ�������
	// IsBalancedTree_Solution solu;
	// solu.IsBalancedTreeTest();

	// BM15 - �����������Ĺ�������
	// lowestCommonAncestor_Solution solu;
	// solu.lowestCommonAncestorTest();

	// BM17 - ���л�������
	// Serialize_Solution solu;
	// solu.demo();

	// BM18 - �ؽ�������
	// reConstructBinaryTree_Solution solu;
	// solu.demo();

	// BM19 - ������������ͼ
	// solve_Solution solu;
	// solu.demo();
}

// ��/ջ/������Ժ���
void heapStackQueueTest()
{
	// BM1 - ������ջʵ�ֶ���
	// TwoStackImplQueue_Solution solu;
	// solu.demo();

	// BM2 - ����min������ջ
	// IncludeMinStack_Solution solu;
	// solu.demo();

	// BM3 - ��Ч��������
	// isValid_Solution solu;
	// solu.demo();

	// BM4 - �������ڵ����ֵ
	// maxInWindows_Solution solu;
	// solu.demo();

	// BM5 - ��С��K����
	// GetLeastNumbers_Solution solu;
	// solu.demo();

	// BM6 - Ѱ�ҵ�K��
	// findKth_Solution solu;
	// solu.demo();

	// BM7 - ����������λ��
	// StreamMid_Solution solu;
	// solu.demo();

	// BM8 - ���ʽ��ֵ
	// ExpressionEvaluation_Solution solu;
	// solu.demo();
}

// ��ϣ���Ժ���
void haspTest()
{
	// BM2 - �����г��ִ�������һ�������
	// MoreThanHalfNum_Solution solu;
	// solu.demo();

	// BM3 - ������ֻ����һ�ε���������
	// FindNumsAppearOnce_Solution solu;
	// solu.demo();

	// BM4 - ȱʧ�ĵ�һ��������
	// minNumberDisappeared_Solution solu;
	// solu.demo();
}

// �ݹ�/���ݲ��Ժ���
void recursionTrackBackTest()
{
	// BM1 - û���ظ������ֵ�ȫ����
	// Permute_Solution solu;
	// solu.demo();

	// BM2 - ���ظ������ֵ�ȫ����
	// PermuteUnique_Solution solu;
	// solu.demo();

	// BM3 - ��������
	// IslandCount_Solution solu;
	// solu.demo();

	// BM4 - �ַ���������
	// Permutation_Solution solu;
	// solu.demo();

	// BM6 - ��������
	// GenerateParenthesis_Solution solu;
	// solu.demo();

	// BM7 - �����·��
	// MaxPath_Solution solu;
	// solu.demo();

	// BM13 - �����ַ���ת����IP��ַ
	// RestoreIpAddresses_Solution solu;
	// solu.demo();
}

// ��̬�滮���Ժ���
void dynamicProgrammingTest()
{
	// BM1 - 쳲���������
	// Fibonacci_Solution solu;
	// solu.demo();

	// BM2 - ��̨��
	// JumpFloor_Solution solu;
	// solu.demo();

	// BM3 - ��С������¥��
	// MinCostClimbingStairs_Solution solu;
	// solu.demo();

	// BM4 - ����������У�����
	// LCS_Solution solu;
	// solu.demo();

	// BM5 - ������Ӵ�
	// LCS2_Solution solu;
	// solu.demo();

	// BM6 - ��ͬ·������Ŀ��һ��
	// UniquePaths_Solution solu;
	// solu.demo();

	// BM7 - �������С·����
	// class MinPathSum_Solution solu;
	// solu.demo();

	// BM8 - �����ַ�����ַ���
	// class TransNum_Solution solu;
	// solu.demo();

	// BM9 - �һ���Ǯ��һ��
	// class MinMoney_Solution solu;
	// solu.demo();

	// BM10 - �����������(һ)
	// class LIS_Solution solu;
	// solu.demo();

	// BM14 - �༭���루һ��
	// EditDistance_Solution solu;
	// solu.demo();

	// BM17 - ��ҽ���(һ)
	Rob_Solution solu;
	solu.demo();
}

// ̰���㷨���Ժ���
void greedyAlgorithmTest()
{
	// BM12 - ������Ӵ�
	// class GetLongestPalindrome_Solution solu;
	// solu.demo();
}

int main()
{
	// ������Ժ���
	// fundLinkTest();

	// ���ֲ��Ҳ��Ժ���
	// binarySearchTest();

	// ���������Ժ���
	// binaryTreeTest();

	// ��/ջ/������Ժ���
	// heapStackQueueTest();

	// ��ϣ���Ժ���
	// haspTest();

	// �ݹ�/���ݲ��Ժ���
	// recursionTrackBackTest();

	// ��̬�滮���Ժ���
	dynamicProgrammingTest();

	// ̰���㷨���Ժ���
	// greedyAlgorithmTest();

	return 0;
}