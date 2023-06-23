#pragma once
#pragma warning(disable: 4996)
#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <openssl\md4.h>
#include <openssl\md5.h>
#include <openssl\sha.h>
using namespace std;

/*������																		**/
class Encrypt
{
public:
	typedef enum TYPE_ENCRYPT													// ��������
	{
		TYPE_MD4			= 0,												// MD4����
		TYPE_MD5			= 1,												// MD5����
		TYPE_SHA1			= 2,												// SHA1����
		TYPE_SHA224			= 3,												// SHA224����
		TYPE_SHA256			= 4,												// SHA256����
		TYPE_SHA384			= 5,												// SHA384����
		TYPE_SHA512			= 6,												// SHA512����
	}Encrypt_t;

public:
	Encrypt(Encrypt_t type);													// ���캯��
	virtual ~Encrypt();															// ��������

public:
	bool			addOriginalData(const string& data, size_t dataSize);		// ���ԭʼ����
	string			getEncryptData();											// ��ü�������(ԭʼ����Ϊ������)
	string			getEncryptHexData();										// ���ʮ�����Ƽ�������

private:
	void			initEncryptStruct(Encrypt_t type);							// ��ʼ�����ܽṹ��
	void			releaseEncryptStruct(Encrypt_t type);						// ���ټ��ܽṹ��
	void			initDftEncryptStruct();										// ��ʼ��Ĭ�ϼ��ܽṹ��
	void			releaseDftEncryptStruct();									// ����Ĭ�ϼ��ܽṹ��

private:
	Encrypt_t		m_type;														// ��������
	void*			m_pEncrtpyStruct;											// ���ܹ�ϣ�ṹ��
};