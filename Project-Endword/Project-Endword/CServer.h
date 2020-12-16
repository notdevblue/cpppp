#pragma once
#include <WinSock2.h>
#include <stdio.h>

#include "CCheckWord.h"
#include "CAgreeDisagree.h"

#pragma region Debug
// Debug header
#include "Debug.h"
#pragma endregion

// Mother Multiplayer Class

class CServer /*: public CCheckWord, CAgreeDisagree*/
{
private:
	CCheckWord checkWord;
	CAgreeDisagree agreeDisagree;


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

	/// <summary>
	/// if iTurn is even, server has turn
	/// </summary>
	UINT iTurn;

	enum CLIENTCONNECTION
	{
		CLIENTERROR = -2,
		SERVERERROR = -1,
		DISCONNECTED = 0,
		CONNECTED = 1
	};

	enum SOCKETFLAG
	{
		CLIENTTURN,
		SERVERTURN
	};

public:
	/// <summary>
	/// Pakcet size must be 1024
	/// </summary>
	/// <param name="port"></param>
	/// <param name="pakcetSize"></param>
	CServer(USHORT port = 4578, WORD pakcetSize = 1024);
	~CServer();

	bool FIsHost();
	void Nickname();
	void CheckNickname(char ch);
	int InitServer();
	int JoinServer();
};

