#include <iostream>
#include <iomanip>
#include <cstring>
#include <cstdlib>
using namespace std;

int main()
{
	int num = 0x12345678;			/*12Ϊ���ֽ�, 78Ϊ���ֽ�**/
	char* numPtr = (char*)&num;

	cout << "���Ա����洢��ʽ: ";
	int cmpNum = 0;
	memcpy(&cmpNum, &numPtr[0], sizeof(char));
	if (0x78 == cmpNum)					/*num�ڵ͵�ַ���ߵ�ַ��˳���У�С�˴洢��ʽΪ��78 56 34 12    **/
	{
		cout << "С�˴洢." << endl;	/*С�˴洢Ϊ���ֽڴ洢�ڵ͵�ַ�����ֽڴ洢�ڸߵ�ַ    **/
	}
	else if (0x12 == cmpNum)			/*num�ڵ͵�ַ���ߵ�ַ��˳���У���˴洢��ʽΪ��12 34 56 78    **/
	{
		cout << "��˴洢" << endl;		/*��˴洢Ϊ���ֽڴ洢�ڸߵ�ַ�����ֽڴ洢�ڵ͵�ַ    **/
	}
	else
		cout << "����." << endl;

	cout << "��С�˴洢ת��: ";			/*��С�˴洢��ת����ʽΪ��ԭ���͵�ַ�����ݿ������ߵ�ַ�л�ԭ���ߵ�ַ�����ݿ������͵�ַ��    **/
	int changeNum = 0;
	char* tmpNumPtr = (char *)&changeNum;
	for (int i = 0; i < 4; ++i)        
	{
		memcpy(&tmpNumPtr[i], &numPtr[3 - i], sizeof(char));
	}
	cout << setbase(16) << changeNum << endl;

	system("pause");
	return 0;
}