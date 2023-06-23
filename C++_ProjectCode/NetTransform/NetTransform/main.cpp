#include <iostream>
#include "FuncTest\FuncTest.h"
#include "FuncTest\LibApiTest.h"
using namespace std;

/*��ǰ����ģ���ʶ��							**/
#define CURRENT_TEST_FLAG						6

int main()
{
#if 1 == CURRENT_TEST_FLAG
	/*�����ģ�����							**/
	funcThreadCodecTest();
#endif 


#if 2 == CURRENT_TEST_FLAG
	/*Socketģ�����							**/
	funcThreadSocketTest();
#endif 


#if 3 == CURRENT_TEST_FLAG
	/*�����ڴ�ģ�����							**/
	funcMemoryShareTest();
#endif 


#if 4 == CURRENT_TEST_FLAG
	/*OpenSSL MD5 API����						**/
	funcOpensslMd5ApiTest();
#endif


#if 5 == CURRENT_TEST_FLAG
	/*OpenSSL SHA API����						**/
	funcOpensslShaApiTest();
#endif


#if 6 == CURRENT_TEST_FLAG
	/*����ģ�����								**/
	funcEncryptTest();
#endif
	

	return 0;
}