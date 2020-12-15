#include "CEndWord.h"

#ifndef DEBUG
#include "Debug.h"

#endif

CEndWord::CEndWord()
{
	std::wcin.imbue(locale("korean"));
	std::wcout.imbue(locale("korean"));
}

bool CEndWord::Start()
{
	MenuPlay();
	switch (SelectMode())
	{
		case SINGLEPC:
		{
			system("cls");
			FirstWord();

			while (true)
			{
				if (WordInputCheck())
				{
					if (!AgreeDisagree())
					{
						break;
					}
				}
			}
			break;
		}

		case MULTIPC:
		{
			return false;
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
bool CEndWord::MakeRoom()
{
	char buffer;
	std::cout << "1. �̹� ������� �� ����" << std::endl;
	std::cout << "2. �� ���� ����" << std::endl;
	std::cout << "�Է� : "; std::cin >> buffer;

	if (buffer == 1)
	{
		return SINGLEPC;
	}
	else if (buffer == 2)
	{
		return MULTIPC;
	}
	
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

	}
	else if (buffer == '2')
	{
#ifdef DEBUG
		printf("���� ��Ƽ�÷��̾�\n\r");
		//exit(0);
#endif
	}
#pragma endregion
}