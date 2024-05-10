#include "OpenSSL_Test.h"

/*OpenSSL��װ�Ƿ�ɹ�����				**/
void funcOpenSSLInstallSuccessTest()
{
	/*ԭʼ����					**/
	char srcStr[6] = "hello";

	/*���ܺ�����				**/
	char dstStr[33] = "\0";
	memset(dstStr, 0, sizeof(dstStr));

	/*ʹ��md5����				**/
	MD5_CTX ctx;
	MD5_Init(&ctx);
	MD5_Update(&ctx, srcStr, strlen(srcStr));
	unsigned char md[MD5_DIGEST_LENGTH] = "\0";
	MD5_Final(md, &ctx);
	for (int i = 0; i < MD5_DIGEST_LENGTH; ++i)
	{
		sprintf(&dstStr[i * 2], "%02x", md[i]);
	}

	/*�������ǰ����ַ���		**/
	cout << "SRC STR: " << srcStr << endl;
	cout << "DST STR: " << dstStr << endl;
}