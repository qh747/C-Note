#include "LibApiTest.h"

//extern "C"
//{
//	/*���APPLINK��������										**/
//	#include <openssl\applink.c>
//};

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

/*OpenSSL SHA API����											**/
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

/*OpenSSL RSA API����											**/
void funcOpensslRsaSaveApiTest()
{
	/*��ʼ��RSA													**/
	RSA* pRsa = RSA_new();

	BIGNUM* pBigNum = BN_new();
	BN_set_word(pBigNum, RSA_F4);

	/*����RSA��Կ��												**/
	int genResult = RSA_generate_key_ex(pRsa, 2048, pBigNum, NULL);

	/*RSA��Կ��д���ļ�											**/
	FILE* pFile = fopen("./FuncTest/publickey.pem", "wb");
	PEM_write_RSAPublicKey(pFile, pRsa);
	fclose(pFile);

	pFile = fopen("./FuncTest/privatekey.pem", "wb");
	PEM_write_RSAPrivateKey(pFile, pRsa, NULL, NULL, 0, NULL, NULL);
	fclose(pFile);

	/*����RSA													**/
	BN_free(pBigNum);
	RSA_free(pRsa);
}

void funcOpensslRsaBIOSaveApiTest()
{
	/*��ʼ��RSA													**/
	RSA* pRsa = RSA_new();

	BIGNUM* pBigNum = BN_new();
	BN_set_word(pBigNum, RSA_F4);

	/*����RSA��Կ��												**/
	int genResult = RSA_generate_key_ex(pRsa, 2048, pBigNum, NULL);

	/*RSA��Կ��д���ļ�											**/
	BIO* pPubBio = BIO_new_file("./FuncTest/BIO_publickey.pem", "wb");
	PEM_write_bio_RSAPublicKey(pPubBio, pRsa);

	BIO* pPrvBio = BIO_new_file("./FuncTest/BIO_prvlickey.pem", "wb");
	PEM_write_bio_RSAPrivateKey(pPrvBio, pRsa, NULL, NULL, 0, NULL, NULL);

	/*����RSA													**/
	BN_free(pBigNum);
	RSA_free(pRsa);
	BIO_free(pPubBio);
	BIO_free(pPrvBio);
}

void funcOpensslRsaEnCodeApiTest()
{
	/*���ļ��ж�ȡ��Կ											**/
	RSA* pRsa = RSA_new();

	/*��ȡ��Կ													**/
	FILE* pFile = fopen("./FuncTest/publickey.pem", "rb");
	PEM_read_RSAPublicKey(pFile, &pRsa, NULL, NULL);
	fclose(pFile);

	/*��ȡ˽Կ													**/
	pFile = fopen("./FuncTest/privatekey.pem", "rb");
	PEM_read_RSAPrivateKey(pFile, &pRsa, NULL, NULL);
	fclose(pFile);

	/*ԭʼ���ݼ���												**/
	char originData[16] = "hello world.";
	int keyLen = RSA_size(pRsa);
	
	char* pEncryptBuf = new char[keyLen + 1];
	memset(pEncryptBuf, 0, sizeof(pEncryptBuf));
	int encryptSize = RSA_public_encrypt(strlen(originData), (unsigned char *)originData, (unsigned char *)pEncryptBuf, pRsa, RSA_PKCS1_PADDING);
	pEncryptBuf[encryptSize] = '\0';

	/*���ݽ���													**/
	char* pDecryptBuf = new char[keyLen];
	memset(pDecryptBuf, 0, sizeof(pDecryptBuf));
	int decryptSize = RSA_private_decrypt(keyLen, (const unsigned char *)pEncryptBuf, (unsigned char *)pDecryptBuf, pRsa, RSA_PKCS1_PADDING);
	pDecryptBuf[decryptSize] = '\0';

	cout << "ORIGIN  DATA: " << originData << endl << endl;
	cout << "ENCRYPT DATA: " << pEncryptBuf << endl << endl;
	cout << "DECRYPT DATA: " << pDecryptBuf << endl << endl;

	delete[] pEncryptBuf;
	delete[] pDecryptBuf;
	RSA_free(pRsa);
}

void funcOpensslRsaVertifyApiTest()
{
	/*���ļ��ж�ȡ��Կ											**/
	RSA* pRsa = RSA_new();

	/*��ȡ��Կ													**/
	FILE* pFile = fopen("./FuncTest/publickey.pem", "rb");
	PEM_read_RSAPublicKey(pFile, &pRsa, NULL, NULL);
	fclose(pFile);

	/*��ȡ˽Կ													**/
	pFile = fopen("./FuncTest/privatekey.pem", "rb");
	PEM_read_RSAPrivateKey(pFile, &pRsa, NULL, NULL);
	fclose(pFile);

	/*����ǩ������												**/
	char originData[16] = "hello world.";
	int sigVertifyLen = RSA_size(pRsa);
	char* sigVertify = new char[RSA_size(pRsa) + 1];
	
	int result = RSA_sign(NID_md5, (unsigned char *)originData, strlen(originData), (unsigned char *)sigVertify, (unsigned int *)&sigVertifyLen, pRsa);
	sigVertify[strlen(sigVertify)] = '\0';
	cout << "SIGN: " << result  << " " << sigVertify << endl;

	/*����ǩ����֤												**/
	result = RSA_verify(NID_md5, (unsigned char *)originData, strlen(originData), (unsigned char *)sigVertify, sigVertifyLen, pRsa);
	sigVertify[strlen(sigVertify)] = '\0';
	cout << "VERTIFY: " << result << " " << sigVertify << endl;

	delete[] sigVertify;
	RSA_free(pRsa);
}

/*OpenSSL AES API����											**/
void funcOpensslAesApiTest()
{
	/*ԭʼ����׼��						**/
	const unsigned char* originData = (const unsigned char *)"qwertyuiopasdfghjklzxcvbnm01234567899876543210mnbvcxzlkjhgfdsapoiuytrewq";
	cout << "SRC DATA: " << originData << endl;

	/*��Կ׼��							**/
	const char* userKey = "1234567887654321";
	int bits = strlen(userKey);

	/*���ü�����Կ						**/
	AES_KEY encryptKey;
	AES_set_encrypt_key((const unsigned char *)userKey, bits * 8, &encryptKey);

	/*����								**/
	int dataLen = strlen((const char *)originData) + 1;
	int padLen = AES_BLOCK_SIZE - (dataLen % AES_BLOCK_SIZE);
	int length = dataLen + padLen;

	unsigned char* enc = new unsigned char[length];
	unsigned char* enIvec = new unsigned char[bits];

	AES_cbc_encrypt(originData, enc, length, &encryptKey, enIvec, AES_ENCRYPT);
	cout << "ENC DATA: " << enc << endl;

	/*���ý�����Կ						**/
	AES_KEY decryptKey;
	AES_set_decrypt_key((const unsigned char *)userKey, bits * 8, &decryptKey);

	/*����								**/
	unsigned char* dec = new unsigned char[length];
	unsigned char* deIvec = new unsigned char[bits];

	AES_cbc_encrypt(enc, dec, length, &decryptKey, deIvec, AES_DECRYPT);
	cout << "DEC DATA: " << dec << endl;

	delete[] enc;
	delete[] enIvec;
	delete[] dec;
	delete[] deIvec;
}

/*OpenSSL Base64 API����										**/
void funcOpensslBase64ApiTest()
{
	const char* originData = "hello world";
	int originDataLen = strlen(originData);
	cout << "ORIGIN DATA: " << originData << endl;

	/*��������													**/
	BIO* pCodec = BIO_new(BIO_f_base64());
	BIO* pCodecMem = BIO_new(BIO_s_mem());
	BIO_push(pCodec, pCodecMem);

	BIO_write(pCodec, originData, originDataLen);
	BIO_flush(pCodec);

	BUF_MEM* pCodecBuf = NULL;
	BIO_get_mem_ptr(pCodec, &pCodecBuf);
	
	char* pCodecData = new char[pCodecBuf->length + 1];
	memcpy(pCodecData, pCodecBuf->data, pCodecBuf->length);
	pCodecData[pCodecBuf->length] = '\0';
	
	cout << "CODEC DATA : " << pCodecData << endl;
	BIO_free_all(pCodec);
	
	/*��������													**/
	BIO* pDeCodec = BIO_new(BIO_f_base64());
	BIO* pDecodecMem = BIO_new_mem_buf(pCodecData, strlen(pCodecData));
	BIO_push(pDeCodec, pDecodecMem);

	char decodecData[256] = "\0";
	int readLen = BIO_read(pDeCodec, decodecData, sizeof(decodecData));
	decodecData[readLen] = '\0';
	
	cout << "DECODEC DATA: " << decodecData << endl;
	BIO_free_all(pDeCodec);
	delete[] pCodecData;
}

/*JsonCpp д�ļ� API����										**/
void funcJsonCppOfstreamWriteFileApiTest()
{
	/*����Value���͵�json������									**/
	Value root;

	/*���int��������											**/
	root.append(1);												// append()�����������ʽת������int��������ת��ΪValue����

	/*���double��������										**/
	root.append(2.2);

	/*���bool��������											**/
	root.append(true);

	/*����ַ�����������										**/
	root.append("hello");

	/*���������������											**/
	Value subVec;												// Value�������Ͷ���֧����Ӳ�ͬ��������
	subVec[0] = 11;
	subVec[1] = true;
	subVec[2] = 22.22;
	subVec[3] = "bye";
	root.append(subVec);

	/*���object��������										**/
	Value subObj;
	subObj["key"] = "value";
	root.append(subObj);

	/*��������ת��												**/
	string sJson = root.toStyledString();

	/*д���ļ�													**/
	ofstream ofs("./FuncTest/JsonCppOfstreamWrite.json");
	ofs << sJson;
	ofs.close();
}

void funcJsonCppFastWriterWriteFileApiTest()
{
	/*����Value���͵�json������									**/
	Value root;

	Value fstSubObj;
	fstSubObj["key1"] = "value1";
	fstSubObj["key11"] = "value11";
	root.append(fstSubObj);

	Value secSubObj;
	secSubObj["key2"] = 2;
	root.append(secSubObj);

	Value thrSubObj;
	thrSubObj["key3"] = true;
	root.append(thrSubObj);

	Value forSubObj;
	forSubObj["key4"] = 4.4;
	root.append(forSubObj);

	/*����FastWriter���������ַ�������json����				**/
	FastWriter fWrtr;
	string sJson = fWrtr.write(root);

	/*д���ļ�													**/
	ofstream ofs("./FuncTest/JsonCppFastWriterWrite.json");
	ofs << sJson;
	ofs.close();
}

/*JsonCpp ���ļ� API����										**/
void funcJsonCppReadFileApiTest()
{
	/*���������󣬴�json�ļ�									**/
	ifstream ifs("./FuncTest/JsonCppOfstreamWrite.json");

	/*����Value����, �洢json����								**/
	Value root;
	
	/*����Reader����, ��ȡjson����								**/
	Reader jsonFileReader;
	jsonFileReader.parse(ifs, root);

	/*json���ݽ���												**/
	funcArrayProcess(root);

	/*������ر�												**/
	ifs.close();
}

void funcArrayProcess(Value& nodeVec)
{
	for (ValueIterator iter = nodeVec.begin(); iter != nodeVec.end(); iter++)
	{
		Value curSubNode = *iter;
		if (true == curSubNode.isBool())
			cout << "BOOL    : " << curSubNode.asBool() << endl;
		else if (true == curSubNode.isInt())
			cout << "INT     : " << curSubNode.asInt() << endl;
		else if (true == curSubNode.isDouble())
			cout << "DOUBLE  : " << curSubNode.asDouble() << endl;
		else if (true == curSubNode.isString())
			cout << "STRING  : " << curSubNode.asString() << endl;
		else if (true == curSubNode.isObject())
			funcObjectProcess(curSubNode);
		else if (true == curSubNode.isArray())
			funcArrayProcess(curSubNode);
	}
}

void funcObjectProcess(Value& nodeObj)
{
	vector<string> keyNameVec = nodeObj.getMemberNames();
	for (int i = 0; i < keyNameVec.size(); ++i)
	{
		string& keyName = keyNameVec[i];
		cout << "OBJ KEY : " << keyName << endl;
		cout << "OBJ VAL : " << nodeObj[keyName].asString() << endl;
	}
}