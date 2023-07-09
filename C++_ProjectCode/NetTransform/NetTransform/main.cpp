#include <iostream>
#include "FuncTest\FuncTest.h"
#include "FuncTest\LibApiTest.h"
using namespace std;

/*��ǰ����ģ���ʶ��							**/
#define CURRENT_TEST_FLAG						19

/*���Ժ���										**/
void funcTest();

int main()
{
	funcTest();

	return 0;
}

void funcTest()
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


#if 7 == CURRENT_TEST_FLAG
	/*OpenSSL RSA API����						**/
	funcOpensslRsaSaveApiTest();
#endif


#if 8 == CURRENT_TEST_FLAG
	/*OpenSSL RSA API����						**/
	funcOpensslRsaBIOSaveApiTest();
#endif


#if 9 == CURRENT_TEST_FLAG
	/*OpenSSL RSA API����						**/
	funcOpensslRsaSaveApiTest();
	funcOpensslRsaEnCodeApiTest();
#endif


#if 10 == CURRENT_TEST_FLAG
	/*OpenSSL RSA API����						**/
	funcOpensslRsaVertifyApiTest();
#endif


#if 11 == CURRENT_TEST_FLAG
	/*OpenSSL AES API����						**/
	funcOpensslAesApiTest();
#endif


#if 12 == CURRENT_TEST_FLAG
	/*JsonCpp д�ļ� API����					**/
	funcJsonCppOfstreamWriteFileApiTest();
#endif


#if 13 == CURRENT_TEST_FLAG
	/*JsonCpp д�ļ� API����					**/
	funcJsonCppFastWriterWriteFileApiTest();
#endif


#if 14 == CURRENT_TEST_FLAG
	/*JsonCpp ���ļ� API����					**/
	funcJsonCppReadFileApiTest();
#endif


#if 15 == CURRENT_TEST_FLAG
	/*OpenSSL Base64 API����					**/
	funcOpensslBase64ApiTest();
#endif


#if 16 == CURRENT_TEST_FLAG
	/*�ͻ��˹����ڴ�ģ�����					**/
	funModelClientMemoryShareTest();
#endif 
	

#if 17 == CURRENT_TEST_FLAG
	/*RSA����ģ�����							**/
	funcRsaEncryptTest();
#endif
	

#if 18 == CURRENT_TEST_FLAG
	/*json��ȡ����ģ�����						**/
	funcClientJsonConfTest();
#endif
	

#if 19 == CURRENT_TEST_FLAG
	/*����ģ�����								**/
	funcFactoryTest();
#endif
	
}