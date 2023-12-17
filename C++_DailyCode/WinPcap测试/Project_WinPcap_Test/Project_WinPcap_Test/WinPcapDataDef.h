#pragma once
#include <WinSock2.h>

/*IP��ַ�ṹ										**/
typedef struct DATA_TYPE_IP_ADDRESS
{
	u_char		ucByteFst;
	u_char		ucByteSec;
	u_char		ucByteTrd;
	u_char		ucByteFrth;

}IPAddress_dt;


/*IP�ײ��ṹ										**/
typedef struct DATA_TYPE_IP_HEADER
{
	u_char			ucVersionAndLength;				// �汾 + �ײ�����
	u_char			ucTos;							// ��������
	u_short			usTotalLength;					// IP�����ܳ���
	u_short			usIdentification;				// ��ʶ
	u_short			usFlagAndFragmentOffset;		// ��־λ + ��ƫ����
	u_char			ucTtl;							// ��������
	u_char			ucProto;						// Э������
	u_short			ucCrc;							// ѭ��У����
	IPAddress_dt	ipSrcAddr;						// IPԴ��ַ
	IPAddress_dt	ipDstAddr;						// IPĿ�ĵ�ַ
	u_int			uiOption;						// ѡ��

}IPHeader_dt;


/*UDP�ײ�											**/
typedef struct DATA_TYPE_UDP_HEADER
{
	u_short			usSrcPort;						// UDPԴ�˿�
	u_short			usDstPort;						// UDPĿ�Ķ˿�
	u_short			usLength;						// UDP���ݳ���
	u_short			usCrc;							// ѭ��У����

}UDPHeader_dt;


/*�������ݽṹ										**/
typedef struct DATA_TYPE_SEND_DATA
{
	char*			pData;
	int				iDataSize;

}SendData_dt;