#include "ClientJsonCpp.h"

ClientJsonCpp::ClientJsonCpp(const string& fileName, bool& isPraseOk)
{
	ifstream ifs(fileName);
	if (false == ifs.is_open())
	{
		cerr << "CLIENT JSON OPEN FILE FAILED. FILENAME: " << fileName << endl;
		isPraseOk = false;
		return;
	}

	Json::Value root;
	Json::Reader fileReader;
	fileReader.parse(ifs, root);

	/*��ȡ�ͻ�������																**/
	ClitJsConf_dt clientJsonConf;
	clientJsonConf.iServerPort		 = root["ServerPt"].asInt();
	clientJsonConf.iClientMemShareId = root["MemShrId"].asInt();
	strcpy(clientJsonConf.sClientId, root["ClientId"].asString().c_str());
	strcpy(clientJsonConf.sServerId, root["ServerId"].asString().c_str());
	strcpy(clientJsonConf.sServerIp, root["ServerIp"].asString().c_str());
	this->setClientJsConf(clientJsonConf);

	/*��ȡ�ͻ������ݿ�������Ϣ														**/
	DBJsConf_dt dbJsonConf;
	dbJsonConf.iDBPort = root["DBPort"].asInt();
	strcpy(dbJsonConf.sDBIpAddr, root["DBIpAddr"].asString().c_str());
	strcpy(dbJsonConf.sDBUserName, root["DBUserName"].asString().c_str());
	strcpy(dbJsonConf.sDBUserPasswd, root["DBPasswd"].asString().c_str());
	strcpy(dbJsonConf.sDBName, root["DBName"].asString().c_str());
	strcpy(dbJsonConf.sDBTblName, root["DBTblName"].asString().c_str());
	this->setDBJsConf(dbJsonConf);

	ifs.close();
	isPraseOk = true;
}

ClientJsonCpp::~ClientJsonCpp()
{

}

ClitJsConf_dt ClientJsonCpp::getClientJsConf()
{
	return m_clitJsConf;
}

DBJsConf_dt ClientJsonCpp::getDBJsConf()
{
	return m_DbJsConf;
}

void ClientJsonCpp::setClientJsConf(const ClitJsConf_dt& conf)
{
	m_clitJsConf.iClientMemShareId  = conf.iClientMemShareId;
	m_clitJsConf.iServerPort		= conf.iServerPort;
	strcpy(m_clitJsConf.sClientId, conf.sClientId);
	strcpy(m_clitJsConf.sServerId, conf.sServerId);
	strcpy(m_clitJsConf.sServerIp, conf.sServerIp);
}

void ClientJsonCpp::setDBJsConf(const DBJsConf_dt& conf)
{
	m_DbJsConf.iDBPort = conf.iDBPort;
	strcpy(m_DbJsConf.sDBIpAddr, conf.sDBIpAddr);
	strcpy(m_DbJsConf.sDBName, conf.sDBName);
	strcpy(m_DbJsConf.sDBUserName, conf.sDBUserName);
	strcpy(m_DbJsConf.sDBUserPasswd, conf.sDBUserPasswd);
	strcpy(m_DbJsConf.sDBTblName, conf.sDBTblName);
}