#pragma once
#pragma warning(disable: 4996)
#include <openssl\rsa.h>
#include <openssl\pem.h>
#include <openssl\bio.h>
#include <openssl\err.h>
#include <openssl/buffer.h>
#include <string>
#include <iostream>
using namespace std;

class RsaEncrypt
{
public:
	typedef enum TYPE_SIGN_LEVEL																		// RSAǩ���ȼ�
	{
		SIGN_LEVEL1 = NID_md5,
		SIGN_LEVEL2 = NID_sha1,
		SIGN_LEVEL3 = NID_sha224,
		SIGN_LEVEL4 = NID_sha256,
		SIGN_LEVEL5 = NID_sha384,
		SIGN_LEVEL6 = NID_sha512
	}SignLevel_t;

public:
	RsaEncrypt();																						// ���캯��
	virtual ~RsaEncrypt();																				// ��������

public:
	bool	generateRsaKey(int bits, const string& pubKeyFileName, const string& priKeyFileName);		// ����RSA��Կ��
	bool	prasePubKeyFromFile(const string& pubKeyFileName);											// ���ļ��н�����Կ
	bool	prasePriKeyFromFile(const string& priKeyFileName);											// ���ļ��н���˽Կ

	string	encryptByPubKey(const string& origData);													// ʹ�ù�Կ����
	string  decryptByPriKey(const string& encryptData);													// ʹ��˽Կ����

	string	sign(const string& data, SignLevel_t level);												// ǩ��(ʹ��˽Կ)
	bool	signVerify(const string& data, const string& signData, SignLevel_t level);					// ǩ����֤(ʹ�ù�Կ)

private:
	string	encodeByBase64(const string& data, int size);												// ʹ��Base64����
	string	decodeByBase64(const string& encodeData);													// ʹ��Base64����

private:
	RSA*	m_pPrivateRsaKey;																			// RSA˽Կ
	RSA*	m_pPublicRsaKey;																			// RSA��Կ
};
