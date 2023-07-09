#pragma once
#include "CodecFactory.h"
#include "../Protobuf/Response.h"

class RespCodecFactory : public CodecFactory
{
public:
	RespCodecFactory(const string& serialData);								// ��Ӧ��Ϣ���죬���ڽ��������������л�������
	RespCodecFactory(const ResponseMsg_dt& data);							// ��Ӧ��Ϣ���죬���ڽ������������л�������
	virtual ~RespCodecFactory();

public:
	virtual Codec_Base* createCodec();										// ��������	
	virtual void		modifyType(Serial_t type, void* pModData);			// �޸���������

private:
	string				m_serialData;										// ���л��������
	ResponseMsg_dt		m_originData;										// ԭʼ����
};