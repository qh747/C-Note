#pragma warning(disable:4996)
#include <iostream>
#include <cstring>
#include <string>
#include <windows.h>
using namespace std;

int firstSendTestFunc();

/*���Ͷ˴���	**/
int main()
{
	firstSendTestFunc();

	system("pause");
	return 0;
}

int firstSendTestFunc()
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
	LPVOID pData = MapViewOfFile(hMemObj, FILE_MAP_ALL_ACCESS, 0, 0, 0);
	if (NULL == pData)
	{
		cout << "ERROR: MapViewOfFile() - " << GetLastError() << endl;
		return -1;
	}

	/*д������	  **/
	string shareData = "This Is Share Data.";
	strncpy((char*)pData, shareData.c_str(), shareData.length() + 1);
	cout << "WRITE DATA SUCCESS." << endl;
	cout << "DATA: " << shareData << endl;

	/*����ļ�ӳ��		**/
	UnmapViewOfFile(pData);

	/*�ر��ļ�ӳ����, �رվ��ǰ��Ҫ����ʱ����������ݽ��̶�ȡ����		**/
	Sleep(5 * 1000);
	CloseHandle(hMemObj);

	return 0;
}