#include "AlgorithmTest.h"
#define ALGTHM_TEST_SEQ  7

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
	/*ֱ�Ӳ�������									**/
	funcCallDirectInsertSort();

#elif 7 == ALGTHM_TEST_SEQ
	/*���ֲ�������									**/
	funcCallBinaryInsertSort();

#elif 8 == ALGTHM_TEST_SEQ
	/*ϣ������										**/
	funcCallShellInsertSort();

#endif
}