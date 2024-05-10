#include "MyMessageTest.h"

/*protobufsʹ��MyMessage���Ժ���					**/
void funcMyMessageTest()
{
	/*����������									**/
	MyMessage sendMessage;

	/*��ʼ��������									**/
	sendMessage.set_name(1);
	sendMessage.set_age(18);
	sendMessage.set_sex(true);
	sendMessage.set_info("hello world.");
	int phoneArray[11] = { 1,7,7,2,3,5,7,2,1,2,3 };
	for (int i = 0; i < 11; ++i)
	{
		sendMessage.add_phone(phoneArray[i]);
	}

	/*���л�������									**/
	string sendData;
	sendMessage.SerializeToString(&sendData);

	/*�����л�������								**/
	MyMessage recvMessage;
	recvMessage.ParseFromString(sendData);

	/*ģ�����ݴ�����̵������ӡ					**/
	cout << "------------------ SEND SOURCE DATA --------------------" << endl;
	cout << "name  : " << sendMessage.name() << endl;
	cout << "age   : " << sendMessage.age() << endl;
	cout << "sex   : " << sendMessage.sex() << endl;
	cout << "phone : ";
	for (int i = 0; i < sendMessage.phone_size(); ++i)
	{
		cout << sendMessage.phone(i);
	}
	cout << endl << endl;

	cout << "------------------ SEND SERIAL DATA --------------------" << endl;
	cout << sendData << endl << endl;

	cout << "------------------    DATA TRANS    --------------------" << endl;
	for (int i = 0; i < 3; ++i)
	{
		cout << "data trans..." << endl;
		Sleep(1 * 1000);
	}
	cout << endl;

	cout << "------------------ RECV SERIAL DATA --------------------" << endl;
	cout << sendData << endl;

	cout << "------------------ RECV SOURCE DATA --------------------" << endl;
	cout << "name  : " << recvMessage.name() << endl;
	cout << "age   : " << recvMessage.age() << endl;
	cout << "sex   : " << recvMessage.sex() << endl;
	cout << "phone : ";
	for (int i = 0; i < recvMessage.phone_size(); ++i)
	{
		cout << recvMessage.phone(i);
	}
	cout << endl;
}