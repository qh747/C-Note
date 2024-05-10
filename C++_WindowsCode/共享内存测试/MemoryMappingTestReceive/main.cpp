#pragma warning(disable:4996)
#include <iostream>
#include <cstring>
#include <string>
#include <windows.h>
using namespace std;

int firstRecvTestFunc();

/*���ն˴���	**/
int main()
{
	firstRecvTestFunc();
	
	system("pause");
	return 0;
}

int firstRecvTestFunc()
{
	int GLOBAL_SIZE = 64;
	string memObjName = "ShareMemory";

	/*�����ڴ�ӳ�����		**/
	HANDLE hMemObj = CreateFileMapping(INVALID_HANDLE_VALUE, NULL, PAGE_READWRITE, 0, GLOBAL_SIZE, (LPCWSTR)memObjName.c_str());
	if (NULL == hMemObj)
	{
		cout << "ERROR: CreateFileMapping() - " << GetLastError() << endl;
		return -1;
	}

	/*��ȡӳ�����ݵĵ�ַ	**/
	LPVOID pData = MapViewOfFile(hMemObj, FILE_MAP_READ, 0, 0, 0);
	if (NULL == pData)
	{
		cout << "ERROR: MapViewOfFile() - " << GetLastError() << endl;
		return -1;
	}

	/*��ȡ����	  **/
	cout << "READ DATA SUCCESS." << endl;

	char* buf = (char*)pData;
	cout << "DATA: " << buf << endl;

	/*����ļ�ӳ��		**/
	UnmapViewOfFile(pData);

	/*�ر��ļ�ӳ����		**/
	CloseHandle(hMemObj);

	return 0;
}