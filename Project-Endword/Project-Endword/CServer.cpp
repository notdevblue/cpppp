#include "CServer.h"

void CServer::CheckNickname(char ch)
{
	if (ch & 0x80)
	{
		bIsKoreanNickname = true;
	}
}

void CServer::Nickname()
{
	std::string temp;
	while (true)
	{
		bIsKoreanNickname = false;
		printf("����� �г����� �Է��ϼ���. : ");
		std::getline(std::cin, temp);
		if (temp == "")
		{
			printf("�г��ӿ� �ƹ��͵� �Է����� �ʾҽ��ϴ�.\n");
			continue;
		}
		if (temp.length() > 16)
		{
			printf("�г����� �ʹ� ��ϴ�. (�ִ� 16����)\n");
			continue;
		}
		for_each(temp.begin(), temp.end(), CheckNickname);
		if (bIsKoreanNickname)
		{
			printf("�г����� �ѱ�� ������ �� �����ϴ�.\n");
			continue;
		}
		break;
	}

	chlpServerNickname = (LPSTR)temp.c_str();
}

CServer::CServer(USHORT port, WORD pakcetSize) : PORT(port), PACKET_SIZE(pakcetSize)
{
	bKeepGoing = true;
	bIsKoreanNickname = false;
	if (pakcetSize != 1024)
	{
		system("cls");
		printf("��Ŷ ����� 1024�� �ƴմϴ�.\n���α׷��� ����˴ϴ�.");
		exit(EXIT_SUCCESS);
	}
	iTurn = 0;
	int inIsOK = WSAStartup(MAKEWORD(2, 2), &wsaData);
	if (inIsOK)
	{
		printf("Winsock ���� ����...\n�ƹ� Ű�� ���� �����Ͻʽÿ�...");
		buffer = _getch();
		exit(0);
	}
	Nickname();

#ifdef DEBUG
	printf("���� ���۵�.\n");
#endif // DEBUG
}

int CServer::InitServer()
{
	tServerInfo.sin_addr.S_un.S_addr = INADDR_ANY;
	tServerInfo.sin_port = PORT;
	tServerInfo.sin_family = AF_INET;

	sServer = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

	bind(sServer, (LPSOCKADDR)&tServerInfo, sizeof(tServerInfo));
	int inIsOK = listen(sServer, SOMAXCONN);
	if (inIsOK)
	{
		printf("���� ���� ����...\n�ƹ� Ű�� ���� �����Ͻʽÿ�...");
		
		buffer = _getch();
		return CLIENTCONNECTION::SERVERERROR;
	}

	printf("�ٸ� �� ����� ��ٸ��� ��...\n");

	tClientInfo = {};
	int iClientInfoSize = sizeof(tClientInfo);
	bool bClientOK = (sClient = accept(sServer, (LPSOCKADDR)&tClientInfo, &iClientInfoSize));
	
	if (!bClientOK)
	{
		printf("Ŭ���̾�Ʈ ���� ����...\n�ƹ� Ű�� ���� �����Ͻʽÿ�...");
		buffer = _getch();
		return CLIENTCONNECTION::CLIENTERROR;
	}

	recv(sClient, chlpClientMsg, PACKET_SIZE, 0); // �г�
	chlpClientNickname = chlpClientMsg;


	chlpClientMsg = new CHAR[PACKET_SIZE];
	while (bKeepGoing)
	{
		bool iClientDisconnected = recv(sClient, chlpClientMsg, PACKET_SIZE, 0);

		if (!iClientDisconnected)
		{
			printf("������ ������ϴ�...\n");
			bKeepGoing = false;
		}
		printf("������ Ư��. ù ���� �ܾ �Է��� �� �ֽ��ϴ�.\n\r");
		FirstWord();


		// ���⼭ �ܾ� üũ
		// ����������
		// ������
		// �ù� ������
	}
	
}

CServer::~CServer()
{
	delete[] chlpClientMsg;
	closesocket(sClient);
	closesocket(sServer);
	WSACleanup();
}