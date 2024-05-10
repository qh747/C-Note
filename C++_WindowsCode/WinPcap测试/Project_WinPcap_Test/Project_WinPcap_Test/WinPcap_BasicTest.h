#pragma once
#pragma warning(disable: 4996)

// �궨��WIN32, �����Ĭ�ϵ���Linuxϵͳ�Ŀ�
#define WIN32

#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include <pcap.h>
#include "WinPcapDataDef.h"
using namespace std;

/*�����������ò���						**/
void funcWinPcapEnviromentTest();

/*����������Ϣ�ӿں�������				**/
void funcFindDevsTest();

/*��ʾ������ϸ��Ϣ����					**/
void funcDisplayDevsDetailInfo();
string funcIPIntToStr(u_long pAddr);

/*������, �ص�������ʽ�������ݰ�		**/
void funcOpenAdapterTest();
void funcOpenCb(u_char* param, const struct pcap_pkthdr* header, const u_char* pkt_data);

/*������, �ǻص�������ʽ�������ݰ�	**/
void funcOpenAdapterNonCbTest();

/*���ݰ�����							**/
void funcPacketFliterTest();
void funcPacketFliterTestCb(u_char* param, const struct pcap_pkthdr* header, const u_char* pkt_data);

/*���ݰ�����							**/
void funcPacketPraseTest();
void funcPacketPraseTestCb(u_char* param, const struct pcap_pkthdr* header, const u_char* pkt_data);

/*���ݰ��洢							**/
void funcPacketDumpTest();
void funcPacketDumpTestCb(u_char* param, const struct pcap_pkthdr* header, const u_char* pkt_data);

/*��ץ���ļ�							**/
void funcOpenCaptureFileTest();
void funcOpenCaptureFileTestCb(u_char* param, const struct pcap_pkthdr* header, const u_char* pkt_data);

/*��������								**/
void funcSendPacketTest();
void funcSendPacketTestCb(u_char* param, const struct pcap_pkthdr* header, const u_char* pkt_data);