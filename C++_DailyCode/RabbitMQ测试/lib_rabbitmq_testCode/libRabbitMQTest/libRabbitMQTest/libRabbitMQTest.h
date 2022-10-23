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
#include "amqp.h"
#include "amqp_tcp_socket.h"

using namespace std;

/*��ģʽ    **/
void simpleModeFunc();

int simpleMode_PublishThreadFunc();
int simpleMode_ConsumeThreadFunc();

/*��������ģʽ    **/
void workQueueModeFunc();

int workQueueMode_PublishThreadFunc();
int workQueueMode_ConsumeThreadFunc();

/*����/����ģʽ    **/
void pubAndSubModeFunc();

int pubAndSubMode_PublishThreadFunc();
int pubAndSubMode_ConsumeThreadFunc();
int pubAndSubMode_SecondConsumeThreadFunc();