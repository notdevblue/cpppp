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
	std::cout << "방금 단어 쓴 사람이 졌네요 ㄹㅇㅋㅋ" << std::endl;
	std::cout << "Enter 키를 눌러 종료하세요..." << std::endl;
	std::cin.get();
	std::cin.get();


	return true;
}
bool CEndWord::MakeRoom()
{
	char buffer;
	std::cout << "1. 이미 만들어진 방 참가" << std::endl;
	std::cout << "2. 방 새로 생성" << std::endl;
	std::cout << "입력 : "; std::cin >> buffer;

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
#pragma region 모드 선택
	system("cls");
	std::cout << "1. 현실 멀티플레이어" << std::endl;
	std::cout << "2. 1 대 1 로컬 대전" << std::endl;
	std::cout << "숫자를 입력하세요 : ";

	char buffer = std::getchar();
	if (buffer == '1')
	{
#ifdef DEBUG
		printf("현실갱\n\r");
		//exit(0);
#endif

	}
	else if (buffer == '2')
	{
#ifdef DEBUG
		printf("로컬 멀티플레이어\n\r");
		//exit(0);
#endif
	}
#pragma endregion
}