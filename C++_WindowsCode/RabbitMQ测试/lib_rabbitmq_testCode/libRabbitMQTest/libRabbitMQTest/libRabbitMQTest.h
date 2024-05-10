#pragma once
#pragma warning(disable: 4996)
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <thread>
#include <mutex>
#include <Windows.h>
#include <sstream>
#include <assert.h>
#include "amqp.h"
#include "amqp_tcp_socket.h"
using namespace std;

// rabbitmq server IP��ַ
namespace RabbitmqServer
{
	const static char* sServerIpAddr = "192.168.3.16";
	const static int   iServerPort = 5672;
};


/*��ģʽ    **/
void simpleModeFunc();					
int  simpleMode_PublishThreadFunc();	
int  simpleMode_ConsumeThreadFunc();

/*��������ģʽ    **/
void workQueueModeFunc();
int  workQueueMode_PublishThreadFunc();
int  workQueueMode_ConsumeThreadFunc();

/*����/����ģʽ    **/
void pubAndSubModeFunc();
int  pubAndSubMode_PublishThreadFunc();
int  pubAndSubMode_ConsumeThreadFunc(const string& queueName);

/*·��ģʽ    **/
void routeModeFunc();
int  routeMode_PublishThreadFunc();
int  routeMode_ErrorConsumeThreadFunc();
int  routeMode_WarnConsumeThreadFunc();
int  routeMode_InfoConsumeThreadFunc();

/*����ģʽ    **/
void topicModeFunc();
int  topicMode_PublishThreadFunc();
int  topicMode_FirstConsumeThreadFunc();
int  topicMode_SecondConsumeThreadFunc();

/*RPCģʽ    **/
void rpcModeFunc();
int  rpcMode_ClientThreadFunc();
int  rpcMode_serverThreadFunc();
