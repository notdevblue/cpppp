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
		for (int i = 0; i < temp.size(); ++i)
		{
			CheckNickname(temp[i]);
		}
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
	iTurn = 1;
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

bool CServer::FIsHost()
{
	system("cls");
	printf("1. ���� ����\n\r������ ��� �ܾ�� ���ڵ�. ���� ����\n\r");
	std::cin >> buffer;
	bool bIsHost = buffer == 1;
	if (!bIsHost)
	{
		return false;
	}
	else
	{
		return true;
	}
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
	
	system("cls");
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

	printf("������ Ư��. ù ���� �ܾ �Է��� �� �ֽ��ϴ�.\n\r");
	checkWord.FirstWord();

	while (bKeepGoing)
	{
		// ���� �� Ŭ���̾�Ʈ ��
		bool bTurn = iTurn % 2 == 1;

		bool iClientDisconnected = recv(sClient, chlpClientMsg, PACKET_SIZE, 0);
		if (!iClientDisconnected)
		{
			printf("������ ������ϴ�...\n");
			bKeepGoing = false;
		}

		if (!bTurn)
		{
			while (true)
			{
				char cMsg[] = "0";
				char cAgree[] = "1";
				send(sClient, cMsg, strlen(cMsg), 0); // �ڱ����̶�°� �˷� ��
				const wchar_t* word = checkWord.ShowWord();
				send(sClient, (const char*)word, wcslen(word), 0); // �� �ܾ� ������

				recv(sClient, chlpClientMsg, PACKET_SIZE, 0); // Ŭ���̾�Ʈ�� ���� �ܾ� Ȯ��
				if (checkWord.WordInputCheckClient(chlpClientMsg))
				{
					send(sClient, cMsg, strlen(cMsg), 0); // �ܾ� �ٽ� �Է��ؾ� �Ѵٴ°� ����
				}
				else
				{
					bool bResult;
					while (true)
					{
						
						send(sClient, cAgree, strlen(cAgree), 0); // ����������
						recv(sClient, chlpClientMsg, PACKET_SIZE, 0); // Ŭ���̾�Ʈ�� ���� ���������� Ȯ��
						if (chlpClientMsg == "����" || chlpClientMsg == "1")
						{
							bResult = agreeDisagree.AgreeDisagreeClient(2, 1, chlpClientNickname);
							break;
						}
						else if (chlpClientMsg == "������" || chlpClientMsg == "2")
						{
							bResult = agreeDisagree.AgreeDisagreeClient(2, 2, chlpClientNickname);
							break;
						}
					}
					if (bResult)
					{
						++iTurn;
					}
					else
					{
						std::cout << "����� " << chlpClientNickname << " ���� �̰���ϴ�!" << std::endl;
						bKeepGoing = false;
						continue;
					}

				}
			}


		}
		else
		{
			checkWord.WordInputCheck();
			// ���� ��
		}



		
		
		// ���⼭ �ܾ� üũ
		// ����������
		// ������
		// �ù� ������
	}
	
}

int CServer::JoinServer()
{
	printf("��Ÿ���Ե� ������");
	return(0);
}

CServer::~CServer()
{
	delete[] chlpClientMsg;
	closesocket(sClient);
	closesocket(sServer);
	WSACleanup();
}