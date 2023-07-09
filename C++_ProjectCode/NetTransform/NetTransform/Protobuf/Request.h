#pragma once
#include "Codec.h"
#include "Message.pb.h"
#include "../PublicDataDef/PublicDataDef.h"

class Request_Codec : public Codec_Base
{
public:
	Request_Codec();
	Request_Codec(const std::string& encStr);			// ���ڽ���
	Request_Codec(const RequestMsg_dt& reqStr);			// ���ڱ���
	virtual ~Request_Codec();

public:
	void initMessage(const std::string& encStr);		// ���ڽ��룬ǰ��ʹ��Ĭ�Ͽչ��캯��
	void initMessage(const RequestMsg_dt& reqStr);		// ���ڱ��룬ǰ��ʹ��Ĭ�Ͽչ��캯��

public:
	virtual std::string encodeMsg();					// �������л�
	virtual void*       decodeMsg();					// ���ڷ����л�

private:
	std::string		m_str;
	RequestMessage  m_msg;
};