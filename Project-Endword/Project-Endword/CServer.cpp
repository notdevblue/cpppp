#include "CServer.h"

CServer::CServer()
{
	if (WSAStartup(MAKEWORD(2, 2), &wsaData))
	{
		printf("Winsock 시작 오류...\n아무 키나 눌러 종료하십시오...");
		WSACleanup();
		_getch();
		exit(0);
	}

}

bool CServer::InitServer()
{
	tServerInfo.sin_addr.S_un.S_addr = INADDR_ANY;
	tServerInfo.sin_port = PORT;
	tServerInfo.sin_family = AF_INET;

	sServer = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

	bind(sServer, (LPSOCKADDR)&tServerInfo, sizeof(tServerInfo));
	if (listen(sServer, SOMAXCONN) == INVALID_SOCKET)
	{
		printf("서버 소켓 오류...\n아무 키나 눌러 종료하십시오...");
		WSACleanup();
		_getch();
		return false;
	}

	tClientInfo = {};
	int iClientInfoSize = sizeof(tClientInfo);
	sClient = accept(sServer, (LPSOCKADDR)&tClientInfo, &iClientInfoSize);
}

CServer::~CServer()
{
	closesocket(sClient);
	closesocket(sServer);
	WSACleanup();
}