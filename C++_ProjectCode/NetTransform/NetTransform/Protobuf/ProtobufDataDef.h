#pragma once
#include <string>

/*������Ϣ						**/
typedef struct DATA_TYPE_REQUEST_MSG
{
	int				cmdType;		// �������ͣ�1.��ԿЭ��  2.��ԿУ��  3.��Կע��
	std::string		clientId;		// �ͻ���ID
	std::string		serverId;		// �����ID
	std::string		sign;
	std::string		data;
}RequestMsg_dt;


/*��Ӧ��Ϣ						**/
typedef struct DATA_TYPE_RESPONSE_MSG
{
	bool			status;
	int				seckeyId;
	std::string		clientId;		// �ͻ���ID
	std::string		serverId;		// �����ID
	std::string		data;
}ResponseMsg_dt;
