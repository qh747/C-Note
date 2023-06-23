#include "LibApiTest.h"

/*OpenSSL MD5 API����											**/
void funcOpensslMd5ApiTest()
{
	/*md5�������ݼ���											**/
	/*md5��ϣ�����ĳ�ʼ��										**/
	MD5_CTX md5Data;
	MD5_Init(&md5Data);
	
	char fstSrcData[10] = "hello";
	char secSrcData[10] = " world.";
	printf("SRC DATA: %s%s\n", fstSrcData, secSrcData);

	/*�Զ������ݽ��м���										**/
	MD5_Update(&md5Data, fstSrcData, strlen(fstSrcData));
	MD5_Update(&md5Data, secSrcData, strlen(secSrcData));

	/*�õ���������												**/
	unsigned char totalDstData[MD5_DIGEST_LENGTH] = "\0";
	MD5_Final(totalDstData, &md5Data);

	/*��ӡ��������												**/
	printf("DST DATA: ");
	for (int i = 0; i < MD5_DIGEST_LENGTH; ++i)
	{
		printf("%02x", totalDstData[i]);
	}
	printf("\n\n");

	/*md5�������ݼ���											**/
	char srcData[20] = "hello md5\0";
	unsigned char dstData[MD5_DIGEST_LENGTH] = "\0";
	MD5((const unsigned char *)srcData, strlen(srcData), dstData);

	printf("SRC DATA: %s\n", srcData);
	printf("DST DATA: ");
	for (int i = 0; i < MD5_DIGEST_LENGTH; ++i)
	{
		printf("%02x", dstData[i]);
	}
	printf("\n");
}

/*OpenSSL SHA API����												**/
void funcOpensslShaApiTest()
{
	/*sha256�������ݼ���											**/
	/*sha256��ϣ�����ĳ�ʼ��										**/
	SHA256_CTX sha256Data;
	SHA256_Init(&sha256Data);

	char fstSrcData[10] = "hello";
	char secSrcData[10] = " world.";
	printf("SRC DATA: %s%s\n", fstSrcData, secSrcData);

	/*�Զ������ݽ��м���											**/
	SHA256_Update(&sha256Data, fstSrcData, strlen(fstSrcData));
	SHA256_Update(&sha256Data, secSrcData, strlen(secSrcData));

	/*�õ���������													**/
	unsigned char totalDstData[SHA256_DIGEST_LENGTH] = "\0";
	SHA256_Final(totalDstData, &sha256Data);

	/*��ӡ��������													**/
	printf("DST DATA: ");
	for (int i = 0; i < SHA256_DIGEST_LENGTH; ++i)
	{
		printf("%02x", totalDstData[i]);
	}
	printf("\n\n");

	/*sha256�������ݼ���											**/
	char srcData[20] = "hello sah256\0";
	unsigned char dstData[SHA256_DIGEST_LENGTH] = "\0";
	SHA256((const unsigned char *)srcData, strlen(srcData), dstData);

	printf("SRC DATA: %s\n", srcData);
	printf("DST DATA: ");
	for (int i = 0; i < SHA256_DIGEST_LENGTH; ++i)
	{
		printf("%02x", dstData[i]);
	}
	printf("\n");
}