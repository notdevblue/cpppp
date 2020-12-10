#include "CServer.h"

CServer::CServer()
{
	if (WSAStartup(MAKEWORD(2, 2), &wsaData))
	{
		printf("Winsock ���� ����...\n�ƹ� Ű�� ���� �����Ͻʽÿ�...");
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
		printf("���� ���� ����...\n�ƹ� Ű�� ���� �����Ͻʽÿ�...");
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