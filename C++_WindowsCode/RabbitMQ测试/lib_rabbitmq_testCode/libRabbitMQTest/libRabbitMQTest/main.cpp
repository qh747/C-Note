#include <iostream>
#include "libRabbitMQTest.h"
using namespace std;

int main()
{
	/*��ģʽ����    **/
	// simpleModeFunc();     

	/*��������ģʽ    **/
	// workQueueModeFunc();

	/*����/������ģʽ    **/
	pubAndSubModeFunc();

	/*·��ģʽ    **/
	//routeModeFunc();

	/*����ģʽ    **/
	//topicModeFunc();

	/*RPCģʽ    **/
	//rpcModeFunc();

	return 0;
}
