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
			printf("아오 작작 틀려어어어어\r\n");
		if (easteregg >= 20)
		{
			system("cls");
			printf("놀라지 마세요! 이 메세지는 당신이 이상한 짓거리를 해서 예외 상황에 들어왔을때 나타나는 메세지에요.\r\n그러니까 하라는 대로 하지 거 참 진짜;\r\n아무 키나 눌러 종료하세요.");
			_getch();
			exit(EXIT_SUCCESS);
		}
		printf("플레이어 수를 입력하세요 : ");
		std::cin >> iPlayerNumber;
		std::cout << iPlayerNumber << " 명 으로 게임을 진행할까요?\r\n1. 네\n1 이 아닌 다른 것들. 아니요\r\n";
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
	std::cout << "방금 단어 쓴 사람이 졌네요 ㄹㅇㅋㅋ" << std::endl;
	std::cout << "Enter 키를 눌러 종료하세요..." << std::endl;
	std::cin.get();
	std::cin.get();


	return true;
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
		return SINGLEPC;
	}
	else if (buffer == '2')
	{
#ifdef DEBUG
		printf("로컬 멀티플레이어\n\r");
		//exit(0);
#endif
		return MULTIPC;
	}
	return(0);
#pragma endregion
}