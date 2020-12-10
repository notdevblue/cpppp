#include "CEndWord.h"

void CEndWord::Start()
{
	//CMainText mainmenu;
	//CCheckWord word;
	//CAgreeDisagree agree;

	
	/*mainmenu.*/MenuPlay();
	system("cls");
	/*word.*/FirstWord();



	while (true)
	{
		
		if (/*word.*/WordInputCheck())
		{
			if (!/*agree.*/AgreeDisagree())
			{
				break;
			}
		}
	}
	
	system("cls");
	std::cout << "방금 단어 쓴 사람이 졌네요 ㄹㅇㅋㅋ" << std::endl;
	std::cout << "Enter 키를 눌러 종료하세요..." << std::endl;
	std::cin.get();
	std::cin.get();


	return;
}