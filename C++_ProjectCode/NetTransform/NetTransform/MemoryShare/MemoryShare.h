#pragma once
#include <iostream>
#include <sstream>
#include <map>
#include <string>
#include <ctime>
#include <cstring>
#include <cstdlib>
#include <atomic>
#include <Windows.h>
using namespace std;

/*�����ڴ����ݽṹ																											**/
typedef struct DATA_TYPE_MEMORY_SHARE_STRUCTURE
{
	int						iMemId;																							// �����ڴ��ʶID
	string					sMemName;																						// �����ڴ�����
	HANDLE					pMemHandle;																						// �����ڴ���
	LPVOID					pMemory;																						// �����ڴ����ָ��
	DWORD					ulMemSize;																						// �����ڴ��С

	DATA_TYPE_MEMORY_SHARE_STRUCTURE()
	{
		iMemId				= -1;
		sMemName			= "";
		pMemHandle			= NULL;
		pMemory				= NULL;
		ulMemSize			= 0;
	}
}MemShareStruct_dt;

/*�����ڴ���																												**/
class MemoryShare
{
public:
	MemoryShare();																											// ���캯��
	virtual ~MemoryShare();																									// ��������

public:
	bool									allocateMemory(int id, const char* name, DWORD size, double sec);				// �����ڴ�
	bool									releaseMemory(int id, double sec);												// �ͷ��ڴ�
	bool									clearMemory(int id, DWORD pos, DWORD clearSize, double sec);					// ���ָ����С���ڴ�ռ�

	DWORD									getMemorySize(int id, double sec);												// ��ȡ�����ڴ��С
	DWORD									writeData(int id, void* pData, DWORD dataSize, DWORD pos, double sec);			// д����
	DWORD									readData(int id, void* pData, DWORD dataSize, DWORD pos, double sec);			// ������

private:																													// ��ֹ����
	MemoryShare(const MemoryShare& other) {}
	void operator=(const MemoryShare& other) {}

private:
	void									setMemoryShareState(bool state);												// ����MemoryShare��״̬
	bool									getMemoryShareState();															// ��ȡMemoryShare��״̬

private:
	bool									m_memoryShareState;																// �жϵ�ǰMemoryShare���Ƿ����

private:
	static DWORD							GETMemorySize(int id, double sec);												// ��ȡ�����ڴ�ռ��С
	static DWORD							WRITEMemory(int id, void* pData, DWORD dataSize, DWORD pos, double sec);		// �����ڴ�д������
	static DWORD							READMemory(int id, void* pData, DWORD dataSize, DWORD pos, double sec);			// �����ڴ��ȡ����
	static bool								CLEARMemory(int id, DWORD pos, DWORD clearSize, double sec);					// �����ڴ��������
	static void								CLEARMemManageMap();															// ��չ����ڴ����map
	static bool								ALLOCATEMemory(int id, const char* name, DWORD size, double sec);				// ���빲���ڴ�ռ�
	static bool								RELEASEMemory(int id, double sec);												// �Ƴ�memory����

	static bool								CREATEMemManageMapMutex();														// �����ڴ����map����������
	static bool								RELEASEMemManageMapMutex();														// �����ڴ����map����������
	static bool								LOCKMemManageMapMutex(double sec);												// �����ڴ����map����������
	static bool								UNLOCKMemManageMapMutex();														// �����ڴ����map����������

	static void								ADDMemoryShareObject();															// ���ӹ����ڴ������
	static void								REDUCEMemoryShareObject();														// ���ٹ����ڴ������

private:
	static map<int, MemShareStruct_dt>		GBLMemManageMap;																// �����ڴ����map
	static HANDLE							GBLMemManageMapMutex;															// �����ڴ����map������
	static atomic<unsigned long>			GBLMemoryShareObjects;															// �����ڴ�������¼
};