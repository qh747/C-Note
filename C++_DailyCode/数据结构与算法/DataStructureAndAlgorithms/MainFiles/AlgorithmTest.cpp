#include "AlgorithmTest.h"
#define ALGTHM_TEST_SEQ  4

/*���ܲ���											**/
void algorithmTest()
{
#if 1 == ALGTHM_TEST_SEQ
	/*ð���������									**/
	funcBubbleSort();
#endif

#if 2 == ALGTHM_TEST_SEQ
	/*ð������Ľ�����								**/
	funcBubbleImproveSort();
#endif

#if 3 == ALGTHM_TEST_SEQ
	/*��������										**/
	funcCallQuickSort();
#endif


#if 4 == ALGTHM_TEST_SEQ
	/*����ת										**/
	funcLinkListReverse();
#endif
}