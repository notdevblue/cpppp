#pragma once
#include <vector>
#include <WinSock2.h>
#include <stdio.h>
#include <conio.h>
#pragma comment(lib, "ws2_32")

class CServer
{
private:
	WSADATA wsaData;
	SOCKET sServer;
	SOCKET sClient;
	SOCKADDR_IN tServerInfo;
	SOCKADDR_IN tClientInfo;
	
	const USHORT PORT = 4578;
	const WORD PACKET_SIZE = 1024;
public:
	CServer();
	~CServer();

	bool InitServer();
};

