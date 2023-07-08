#pragma once 
#pragma warning(disable: 4996)
#include <cstring>

const int CLIENT_ID_LENGTH		= 128;											// �ͻ���ID����
const int SERVER_ID_LENGTH		= 128;											// �����ID����
const int KEY_INFO_LENGTH		= 128;											// ��Կ����
const int KEY_IN_USE_STATE		= 1;											// ��Կ����
const int KEY_IN_UNUSE_STATE	= 0;											// ��Կ������

/*��Կ��Ϣ																		**/
typedef struct DATA_TYPE_KEY_INFO
{
	char			sClientId[CLIENT_ID_LENGTH];
	char			sServerId[SERVER_ID_LENGTH];
	char			sKeyInfo[KEY_INFO_LENGTH];
	int				iKetStatus;
	int				iKeyId;

	DATA_TYPE_KEY_INFO()
	{
		memset(this, 0, sizeof(DATA_TYPE_KEY_INFO));
	}
}KeyInfo_dt;