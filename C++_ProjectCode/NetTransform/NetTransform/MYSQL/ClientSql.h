#pragma once
#pragma warning(disable: 4996)
#include <mysql.h>
#include <iostream>
#include <cstring>
#include <string>
#include "../PublicDataDef/PublicDataDef.h"
using namespace std;

class ClientSql
{
public:
	ClientSql();
	~ClientSql();

public:
	bool			connectDatabase(const DBJsConf_dt& dbInfo);			// �������ݿ�
	bool			insertKeyInfo(const KeyInfo_dt& data);				// ������Կ��Ϣ
	bool			getKeyInfo(int keyId, KeyInfo_dt& data);			// ��ȡ��Կ��Ϣ
	bool			getValuedKeyInfo(KeyInfo_dt& data);					// ��ȡ���ݿ��Ѿ��洢����Ч��Կ��Ϣ
	bool			removeKeyInfo(int keyId);							// �Ƴ���Կ��Ϣ

private:
	DBJsConf_dt		m_dbConnInfo;
	MYSQL*			m_pSqlHandle;
};