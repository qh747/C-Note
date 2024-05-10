#pragma once
#include <iostream>
#include <stack>
#include <vector>
using std::stack;
using std::vector;
using std::cout;
using std::endl;

struct ListNode {
	int val;
	ListNode *next;

	ListNode(int x) : val(x), next(nullptr) {}
}; 

// 1.��ת���� 2024.04.18
class ReverseLinkList_Solution {
public:
	ListNode* ReverseList(ListNode* head);
	void ReverseListTest();
};

// 2.������ָ�����䷴ת 2024.04.18
class ReverseBetween_Solution {
public:
	ListNode* reverseBetween(ListNode* head, int m, int n);
	void ReverseBetweenTest();
};

// 3.�ϲ�������������� 2024.04.19
class Merge_Solution {
public:
	ListNode* Merge(ListNode* pHead1, ListNode* pHead2);
	void MergeTest();
};

// 4.�ϲ�k������������� 2024.04.20
class mergeKLists_Solution{
public:
	ListNode* mergeKLists(vector<ListNode*>& lists);
	ListNode* deverseLists(vector<ListNode*>& lists, int start, int end);
	ListNode* mergeLists(ListNode* pHeadFst, ListNode* pHeadSec);
	void mergeKListsTest();
};

// 5.�ж��������Ƿ��л� 2024.05.02
class HasCycle_Solution {
public:
	bool hasCycle(ListNode *head);
	void hasCycleTest();
};

// 6.������ڽڵ� 2024.05.02
class EntryNodeOfLoop_Solution {
public:
	ListNode* EntryNodeOfLoop(ListNode* pHead);
	void EntryNodeOfLoopTest();
};

// 7.�����е������K���ڵ� 2024.05.02
class FindKthToTail_Solution {
public:
	ListNode* FindKthToTail(ListNode* pHead, int k);
	void FindKthToTailTest();
};

// 8.��������ĵ�һ�������ڵ� 2024.05.02
class FindFirstCommonNode_Solution {
public:
	ListNode* FindFirstCommonNode(ListNode* pHead1, ListNode* pHead2);
	void FindKthToTailTest();
};

// 9.�����������(��)  2024.05.03
class addInList_Solution {
public:
	ListNode* addInList(ListNode* head1, ListNode* head2);
	ListNode* reverseList(ListNode* head);
	void addInListTest();
};

// 10.�����������  2024.05.03
class sortInList_Solution {
public:
	ListNode* sortInList(ListNode* head);
	void mergeSort(vector<ListNode*>& vec, int start, int end);
	void mergeAlg(vector<ListNode*>& vec, int start, int end);
	void sortInListTest();
};

// 11.�ж�һ�������Ƿ�Ϊ���Ľṹ 2024.05.10
class isPail_Solution {
public:
	bool isPail(ListNode* head);
	void isPailTest();
};

// 12.�������ż���� 2024.05.10
class oddEvenList_Solution {
public:
	ListNode* oddEvenList(ListNode* head);
	void oddEvenListTest();
};

// 13.ɾ�������������ظ���Ԫ��-I 2024.05.10
class deleteDuplicates_Solution {
public:
	ListNode* deleteDuplicates(ListNode* head);
	void deleteDuplicatesTest();
};

// 14.ɾ�������������ظ���Ԫ��-II 2024.05.10
class deleteDuplicatesII_Solution {
public:
	ListNode* deleteDuplicatesII(ListNode* head);
	void deleteDuplicatesIITest();
};