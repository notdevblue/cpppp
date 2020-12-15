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
		printf("당신의 닉네임을 입력하세요. : ");
		std::getline(std::cin, temp);
		if (temp == "")
		{
			printf("닉네임에 아무것도 입력하지 않았습니다.\n");
			continue;
		}
		if (temp.length() > 16)
		{
			printf("닉네임이 너무 깁니다. (최대 16글자)\n");
			continue;
		}
		for_each(temp.begin(), temp.end(), CheckNickname);
		if (bIsKoreanNickname)
		{
			printf("닉네임은 한국어를 포함할 수 없습니다.\n");
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
		printf("패킷 사이즈가 1024가 아닙니다.\n프로그램이 종료됩니다.");
		exit(EXIT_SUCCESS);
	}
	iTurn = 0;
	int inIsOK = WSAStartup(MAKEWORD(2, 2), &wsaData);
	if (inIsOK)
	{
		printf("Winsock 시작 오류...\n아무 키나 눌러 종료하십시오...");
		buffer = _getch();
		exit(0);
	}
	Nickname();

#ifdef DEBUG
	printf("서버 시작됨.\n");
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
		printf("서버 소켓 오류...\n아무 키나 눌러 종료하십시오...");
		
		buffer = _getch();
		return CLIENTCONNECTION::SERVERERROR;
	}

	printf("다른 한 사람을 기다리는 중...\n");

	tClientInfo = {};
	int iClientInfoSize = sizeof(tClientInfo);
	bool bClientOK = (sClient = accept(sServer, (LPSOCKADDR)&tClientInfo, &iClientInfoSize));
	
	if (!bClientOK)
	{
		printf("클라이언트 소켓 오류...\n아무 키나 눌러 종료하십시오...");
		buffer = _getch();
		return CLIENTCONNECTION::CLIENTERROR;
	}

	recv(sClient, chlpClientMsg, PACKET_SIZE, 0); // 닉넴
	chlpClientNickname = chlpClientMsg;


	chlpClientMsg = new CHAR[PACKET_SIZE];
	while (bKeepGoing)
	{
		bool iClientDisconnected = recv(sClient, chlpClientMsg, PACKET_SIZE, 0);

		if (!iClientDisconnected)
		{
			printf("접속이 끊겼습니다...\n");
			bKeepGoing = false;
		}
		printf("방장의 특권. 첫 시작 단어를 입력할 수 있습니다.\n\r");
		FirstWord();


		// 여기서 단어 체크
		// 인정노인정
		// 돌린다
		// 시발 어케해
	}
	
}

CServer::~CServer()
{
	delete[] chlpClientMsg;
	closesocket(sClient);
	closesocket(sServer);
	WSACleanup();
}