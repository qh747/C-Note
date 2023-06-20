#pragma once
#include <iostream>
#include "../Protobuf/Request.h"
#include "../Protobuf/Response.h"
#include "../Socket/TcpServer.h"
#include "../Socket/TcpSocket.h"
#include "../MemoryShare/MemoryShare.h"
#include <Windows.h>
#include <cstdio>
using namespace std;

/*�����ģ�����							**/
void funcThreadCodecTest();
void funcModelRequestCodecTest();
void funcModelResponseCodecTest();

/*Socketģ�����							**/
void funcThreadSocketTest();
void funcModelTcpServerTest();
void funcModelTcpClientTest();

/*�����ڴ�ģ�����							**/
void funcMemoryShareTest();
void funcModelMemoryShareWriteTest();
void funcModelMemoryShareReadTest();