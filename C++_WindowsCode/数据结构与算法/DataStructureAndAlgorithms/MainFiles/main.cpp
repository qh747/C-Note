#include  <iostream>
#include "AlgorithmTest.h"
#include "DataStructTest.h"
#include "AlgorithmPracticeTest.h"
using namespace std;

#define TEST_TYPE 1

int main()
{
#if 1 == TEST_TYPE

	/*�㷨����									**/
	algorithmTest();

#elif 2 == TEST_TYPE

	/*���ݽṹ����								**/
	dataStructTest();

#elif 3 == TEST_TYPE

	/*�㷨��ϰ����								**/
	algorithmPracticeTest();

#endif 

	return 0;
}

