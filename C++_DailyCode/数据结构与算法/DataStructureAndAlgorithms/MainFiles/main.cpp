#include  <iostream>
#include "AlgorithmTest.h"
#include "DataStructTest.h"
using namespace std;

#define TEST_TYPE 2

int main()
{
#if 1 == TEST_TYPE

	/*�㷨����									**/
	algorithmTest();

#endif 

#if 2 == TEST_TYPE

	/*���ݽṹ����								**/
	dataStructTest();

#endif 

	return 0;
}

