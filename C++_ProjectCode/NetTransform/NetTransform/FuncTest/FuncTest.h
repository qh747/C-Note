#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include "../Protobuf/Request.h"
#include "../Protobuf/Response.h"
#include "../Socket/TcpServer.h"
#include "../Socket/TcpSocket.h"
#include "../MemoryShare/MemoryShare.h"
#include "../MemoryShare/ClientMemShare.h"
#include "../OpenSSL/Encrypt.h"
#include "../OpenSSL/RsaEncrypt.h"
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
void funModelClientMemoryShareTest();

/*����ģ�����								**/
void funcEncryptTest();
void funcRsaEncryptTest();
