#pragma once
#include <iostream>
#include "../Protobuf/Request.h"
#include "../Protobuf/Response.h"
#include "../Socket/TcpServer.h"
#include "../Socket/TcpSocket.h"
#include <Windows.h>
#include <cstdio>
using namespace std;

/*Request_Codecģ�����						**/
void funcModelRequestCodecTest();

/*Response_Codecģ�����					**/
void funcModelResponseCodecTest();

/*Socketģ�����							**/
void funcThreadSocketTest();
void funcModelTcpServerTest();
void funcModelTcpClientTest();