#include <iostream>
#include "FuncTest\FuncTest.h"
using namespace std;

/*��ǰ����ģ���ʶ��							**/
#define CURRENT_TEST_FLAG 1

int main()
{
#if 1 == CURRENT_TEST_FLAG

	/*Request_Codecģ�����						**/
	funcModelRequestCodecTest();

	/*Response_Codecģ�����					**/
	funcModelResponseCodecTest();

#endif // 1 == CURRENT_TEST_FLAG

	return 0;
}