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
	std::cout << "��� �ܾ� �� ����� ���׿� ��������" << std::endl;
	std::cout << "Enter Ű�� ���� �����ϼ���..." << std::endl;
	std::cin.get();
	std::cin.get();


	return;
}