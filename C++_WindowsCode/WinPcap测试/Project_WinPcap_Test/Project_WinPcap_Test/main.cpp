#include "WinPcap_BasicTest.h"

int main()
{
	/*WinPcap������������					**/
	//funcWinPcapEnviromentTest();

	/*����������Ϣ�ӿں�������				**/
	//funcFindDevsTest();

	/*��ʾ������ϸ��Ϣ����					**/
	//funcDisplayDevsDetailInfo();

	/*������, �ص�������ʽ�������ݰ�		**/
	//funcOpenAdapterTest();

	/*������, �ǻص�������ʽ�������ݰ�	**/
	//funcOpenAdapterNonCbTest();

	/*���ݰ�����							**/
	//funcPacketFliterTest();

	/*���ݰ�����							**/
	//funcPacketPraseTest();

	/*���ݰ��洢							**/
	//funcPacketDumpTest();

	/*��ץ���ļ�							**/
	//funcOpenCaptureFileTest();

	/*��������								**/
	funcSendPacketTest();

	system("pause");
	return 0;
}
