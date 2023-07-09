#pragma once 
#pragma warning(disable: 4996)
#include <cstring>
#include <string>
using std::string;

const int CLIENT_ID_LENGTH		= 128;											// �ͻ���ID����
const int SERVER_ID_LENGTH		= 128;											// �����ID����
const int KEY_INFO_LENGTH		= 128;											// ��Կ����
const int KEY_IN_USE_STATE		= 1;											// ��Կ����
const int KEY_IN_UNUSE_STATE	= 0;											// ��Կ������
const int SERVER_IP_LENGTH		= 32;											// �����IP��ַ����


/*���л���������																**/
typedef enum TYPE_SERIAL
{
	SERIAL_TYPE		= 1,														// ���л�����
	UNSERIAL_TYPE	= 2,														// δ���л�����
}Serial_t;


/*��Կ��Ϣ																		**/
typedef struct DATA_TYPE_KEY_INFO
{
	char			sClientId[CLIENT_ID_LENGTH];								// �ͻ���ID
	char			sServerId[SERVER_ID_LENGTH];								// �����ID
	char			sKeyInfo[KEY_INFO_LENGTH];									// �������Կ
	int				iKetStatus;													// ��Կ״̬
	int				iKeyId;														// ��ԿID

	DATA_TYPE_KEY_INFO()
	{
		memset(this, 0, sizeof(DATA_TYPE_KEY_INFO));
	}
}KeyInfo_dt;


/*�ͻ���������Ϣ																**/
typedef struct DATA_TYPE_CLIENT_JSON_CONFIGURE
{
	char			sClientId[CLIENT_ID_LENGTH];								// �ͻ���ID
	char			sServerId[SERVER_ID_LENGTH];								// �����ID
	char			sServerIp[SERVER_IP_LENGTH];								// �����IP
	int				iServerPort;												// ����˶˿�
	int				iClientMemShareId;											// �ͻ����ڴ�ӳ��ID

	DATA_TYPE_CLIENT_JSON_CONFIGURE()
	{
		memset(this, 0, sizeof(DATA_TYPE_CLIENT_JSON_CONFIGURE));
	}
}ClitJsConf_dt;


/*������Ϣ																		**/
typedef struct DATA_TYPE_REQUEST_MSG
{
	int				iCmdType;													// �������ͣ�1.��ԿЭ��  2.��ԿУ��  3.��Կע��
	std::string		sClientId;													// �ͻ���ID
	std::string		sServerId;													// �����ID
	std::string		sSign;														// ǩ������
	std::string		sData;														// ԭʼ����

	DATA_TYPE_REQUEST_MSG() : sClientId(""), sServerId(""), sSign(""), sData("")
	{
		iCmdType	= -1;
	}
}RequestMsg_dt;


/*��Ӧ��Ϣ																		**/
typedef struct DATA_TYPE_RESPONSE_MSG
{
	bool			bStatus;													// �������Կ״̬
	int				iSeckeyId;													// �������ԿID
	std::string		sClientId;													// �ͻ���ID
	std::string		sServerId;													// �����ID
	std::string		sData;														// �������Կ

	DATA_TYPE_RESPONSE_MSG() : sClientId(""), sServerId(""), sData("")
	{
		bStatus		= false;
		iSeckeyId	= -1;
	}
}ResponseMsg_dt;