#include "MyMessageTest.h"
#include "MyEnumMsgTest.h"
#include "MyImportInfoTest.h"
#include "MyImportPkgTest.h"

/*���Ժ������ƿ���									**/
#define CUR_TEST_SEQ 4

int main()
{
#if 1 == CUR_TEST_SEQ
	/*protobufsʹ��MyMessage���Ժ���				**/
	funcMyMessageTest();
#endif

#if 2 == CUR_TEST_SEQ
	/*protobufʹ��MyEnumMsg���Ժ���					**/
	funcMyEnumMsgTest();
#endif

#if 3 == CUR_TEST_SEQ
	/*protobufʹ��MyImportInfo���Ժ���				**/
	funcMyImportInfoTest();
#endif

#if 4 == CUR_TEST_SEQ
	/*protobufʹ��MyImportPkg���Ժ���				**/
	funcMyImportPkgTest();
#endif

	return 0;
}