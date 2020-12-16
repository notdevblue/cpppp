#include "CEndWord.h"

#ifndef DEBUG
#include "Debug.h"

#endif

CEndWord::CEndWord()
{
	std::wcin.imbue(locale("korean"));
	std::wcout.imbue(locale("korean"));
	
}

void CEndWord::PlayerNumSet()
{
	int easteregg = 0;
	int buffer;
	while (true)
	{
		if (easteregg >= 5)
			printf("�ƿ� ���� Ʋ�������\r\n");
		if (easteregg >= 20)
		{
			system("cls");
			printf("����� ������! �� �޼����� ����� �̻��� ���Ÿ��� �ؼ� ���� ��Ȳ�� �������� ��Ÿ���� �޼�������.\r\n�׷��ϱ� �϶�� ��� ���� �� �� ��¥;\r\n�ƹ� Ű�� ���� �����ϼ���.");
			_getch();
			exit(EXIT_SUCCESS);
		}
		printf("�÷��̾� ���� �Է��ϼ��� : ");
		std::cin >> iPlayerNumber;
		std::cout << iPlayerNumber << " �� ���� ������ �����ұ��?\r\n1. ��\n1 �� �ƴ� �ٸ� �͵�. �ƴϿ�\r\n";
		std::cin >> buffer;
		if (buffer == 1)
		{
			break;
		}
		else
		{
			++easteregg;
			system("cls");
		}
			
	}
	
}

bool CEndWord::Start()
{
	mainText.MenuPlay();
	switch (SelectMode())
	{
		case SINGLEPC:
		{
			PlayerNumSet();

			system("cls");
			wordCheck.FirstWord();

			while (true)
			{
				wordCheck.WordInputCheck();

				if (!agreeDisagree.AgreeDisagree(iPlayerNumber))
				{
					break;
				}
				
			}
			break;
		}

		case MULTIPC:
		{
			return false;
			break;
		}

	}


	

	
	Sleep(2000);
	system("cls");
	std::cout << "��� �ܾ� �� ����� ���׿� ��������" << std::endl;
	std::cout << "Enter Ű�� ���� �����ϼ���..." << std::endl;
	std::cin.get();
	std::cin.get();


	return true;
}



int CEndWord::SelectMode()
{
#pragma region ��� ����
	system("cls");
	std::cout << "1. ���� ��Ƽ�÷��̾�" << std::endl;
	std::cout << "2. 1 �� 1 ���� ����" << std::endl;
	std::cout << "���ڸ� �Է��ϼ��� : ";

	char buffer = std::getchar();
	if (buffer == '1')
	{
#ifdef DEBUG
		printf("���ǰ�\n\r");
		//exit(0);
#endif
		return SINGLEPC;
	}
	else if (buffer == '2')
	{
#ifdef DEBUG
		printf("���� ��Ƽ�÷��̾�\n\r");
		//exit(0);
#endif
		return MULTIPC;
	}
	return(0);
#pragma endregion
}