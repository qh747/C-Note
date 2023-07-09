#pragma once
#include "CodecFactory.h"
#include "../Protobuf/Request.h"

class ReqCodecFactory : public CodecFactory
{
public:
	ReqCodecFactory(const string& serialData);								// ������Ϣ���죬���ڽ��������������л�������
	ReqCodecFactory(const RequestMsg_dt& data);								// ������Ϣ���죬���ڽ������������л�������
	virtual ~ReqCodecFactory();

public:
	virtual Codec_Base* createCodec();										// ��������	
	virtual void		modifyType(Serial_t type, void* pModData);			// �޸���������
		
private:
	string				m_serialData;										// ���л��������
	RequestMsg_dt		m_originData;										// ԭʼ����
};