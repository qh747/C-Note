#include <iostream>
#include "FuncTest\FuncTest.h"
using namespace std;

/*��ǰ����ģ���ʶ��							**/
#define CURRENT_TEST_FLAG 3

int main()
{
#if 1 == CURRENT_TEST_FLAG
	/*�����ģ�����							**/
	funcThreadCodecTest();
#endif // 1 == CURRENT_TEST_FLAG

#if 2 == CURRENT_TEST_FLAG
	/*Socketģ�����							**/
	funcThreadSocketTest();
#endif // 2 == CURRENT_TEST_FLAG

#if 3 == CURRENT_TEST_FLAG
	/*�����ڴ�ģ�����							**/
	funcMemoryShareTest();
#endif // 3 == CURRENT_TEST_FLAG

	return 0;
}