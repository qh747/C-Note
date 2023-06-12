#pragma once
#include "Codec.h"
#include "Message.pb.h"
#include "ProtobufDataDef.h"

class Response_Codec : public Codec_Base
{
public:
	Response_Codec();
	Response_Codec(const std::string& encStr);			// ���ڽ���
	Response_Codec(const ResponseMsg_dt& respStr);		// ���ڱ���
	virtual ~Response_Codec();

public:
	void initMessage(const std::string& encStr);		// ���ڽ��룬ǰ��ʹ��Ĭ�Ͽչ��캯��
	void initMessage(const ResponseMsg_dt& respStr);	// ���ڱ��룬ǰ��ʹ��Ĭ�Ͽչ��캯��

public:
	virtual std::string encodeMsg();					// �������л�
	virtual void*       decodeMsg();					// ���ڷ����л�

private:
	std::string		 m_str;
	ResponseMessage  m_msg;
};