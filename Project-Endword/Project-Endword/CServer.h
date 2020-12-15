#pragma once
#include <WinSock2.h>
#include <vector>
#include <stdio.h>
#include <conio.h>
#include <algorithm>

#include "CCheckWord.h"
#include "CAgreeDisagree.h"

#define DEBUG

class CServer : public CCheckWord, CAgreeDisagree
{
private:
	WSADATA wsaData;
	SOCKET sServer;
	SOCKET sClient;
	SOCKADDR_IN tServerInfo;
	SOCKADDR_IN tClientInfo;
	
	CONST USHORT PORT;
	CONST WORD PACKET_SIZE;
	
	
	CHAR buffer;
	LPSTR chlpClientMsg;
	LPSTR chlpClientNickname;
	LPSTR chlpServerNickname;

	BOOL bKeepGoing;
	BOOL bIsKoreanNickname;

	INT iTurn;

	enum CLIENTCONNECTION
	{
		CLIENTERROR = -2,
		SERVERERROR = -1,
		DISCONNECTED = 0,
		CONNECTED = 1
	};

public:
	/// <summary>
	/// Pakcet size must be 1024
	/// </summary>
	/// <param name="port"></param>
	/// <param name="pakcetSize"></param>
	CServer(USHORT port = 4578, WORD pakcetSize = 1024);
	~CServer();

	void Nickname();
	void CheckNickname(char ch);
	int InitServer();
};

