#include "AlgorithmTest.h"
#define ALGTHM_TEST_SEQ  14

/*���ܲ���											**/
void algorithmTest()
{
#if 1 == ALGTHM_TEST_SEQ
	/*ð���������									**/
	funcBubbleSort();

#elif 2 == ALGTHM_TEST_SEQ
	/*ð������Ľ�����								**/
	funcBubbleImproveSort();

#elif 3 == ALGTHM_TEST_SEQ
	/*��������										**/
	funcCallQuickSort();

#elif 4 == ALGTHM_TEST_SEQ
	/*����ת										**/
	funcLinkListReverse();

#elif 5 == ALGTHM_TEST_SEQ
	/*ѡ������										**/
	funcCallChooseSort();

#elif 6 == ALGTHM_TEST_SEQ
	/*������										**/
	funcCallHeapSort();

#elif 7 == ALGTHM_TEST_SEQ
	/*ֱ�Ӳ�������									**/
	funcCallDirectInsertSort();

#elif 8 == ALGTHM_TEST_SEQ
	/*���ֲ�������									**/
	funcCallBinaryInsertSort();

#elif 9 == ALGTHM_TEST_SEQ
	/*ϣ������										**/
	funcCallShellInsertSort();

#elif 10 == ALGTHM_TEST_SEQ
	/*�鲢����										**/
	funcCallMergeSort();

#elif 11 == ALGTHM_TEST_SEQ
	/*��������										**/
	funcCallRadixSort();

#elif 12 == ALGTHM_TEST_SEQ
	/*���ֲ���										**/
	funcCallBinarySort();

#elif 13 == ALGTHM_TEST_SEQ
	/*��ֵ����										**/
	funcCallInsertSort();

#elif 14 == ALGTHM_TEST_SEQ
	/*�ֿ����										**/
	funcCallBlockSort();

#endif
}