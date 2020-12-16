#include "CAgreeDisagree.h"

bool CAgreeDisagree::AgreeDisagree(int playerNumber)
{
	srand((unsigned int)time(nullptr));


	bool* playerAgrees = new bool[playerNumber];
	for (int i = 0; i < playerNumber; ++i)
	{
		playerAgrees[i] = false;
	}


	int playerAgreed = 0;


	for (int curPlayer = 0; curPlayer < playerNumber; ++curPlayer)
	{
		if (curPlayer != 0)
		{
			cout << "플레이어 " << curPlayer << " 님이 ";
			switch (playerAgrees[curPlayer - 1])
			{
			case true: cout << "인정 하셨습니다." << endl; break;
			case false: cout << "노인정 하셨습니다." << endl; break;
			}
				
		}
		string buffer;
		cout << "이 단어 인정하시겠습니까 ? " << endl;
		cout << "1. 인정" << endl;
		cout << "2. 노인정" << endl;

		bool bInputNormal = false;
		while (!bInputNormal)
		{
			cin >> buffer;
			if (buffer == "인정" || buffer == "1")
			{
				playerAgrees[curPlayer] = true;
				bInputNormal = true;
				
			}
			else if (buffer == "노인정" || buffer == "2")
			{
				playerAgrees[curPlayer] = false;
				bInputNormal = true;
			}
			else
			{
				cout << "다시 입력하세요." << endl;
			}
		}
		bInputNormal = false;
		std::system("cls");
	}
	
	for (int curPlayer = 0; curPlayer < playerNumber; ++curPlayer)
	{
		switch (playerAgrees[curPlayer])
		{
		case true: ++playerAgreed; break;
		case false: break;
		}
	}
	
	if (playerAgreed > (playerNumber / 2))
	{
		cout << "인정." << endl;
		cout << "다음 사람이 입력하세요" << endl;
		delete[] playerAgrees;
		return true;
	}
	else if (playerAgreed < (playerNumber / 2))
	{
		cout << "노인정." << endl;
		delete[] playerAgrees;
		return false;
	}
	else
	{
		cout << "딱 절반이니 랜덤으로 갑시다." << endl;
		Sleep(1000);
		cout << ".";
		Sleep(1000);
		cout << ".";
		Sleep(1000);
		cout << "." << endl;
		Sleep(2000);
		bool agree = rand() % 2;
		if (agree)
		{
			cout << "인정." << endl;
			delete[] playerAgrees;
			return true;
		}
		else
		{
			cout << "노인정." << endl;
			delete[] playerAgrees;
			return false;
		}
	}
}
bool CAgreeDisagree::AgreeDisagreeClient(int playerNumber, int agreeDis, LPSTR nickname)
{
	srand((unsigned int)time(nullptr));




	int playerAgreed = 0;

	if (agreeDis == 1)
	{
		std::cout << nickname << " 님이 인정 하셨습니다." << std::endl;
		++playerAgreed;
	}
	else
	{
		std::cout << nickname << " 님이 노인정 하셨습니다." << std::endl;
	}



		string buffer;
		cout << "이 단어 인정하시겠습니까 ? " << endl;
		cout << "1. 인정" << endl;
		cout << "2. 노인정" << endl;

		bool bInputNormal = false;
		while (!bInputNormal)
		{
			cin >> buffer;
			if (buffer == "인정" || buffer == "1")
			{
				++playerAgreed;
				bInputNormal = true;
				
			}
			else if (buffer == "노인정" || buffer == "2")
			{
				bInputNormal = true;
			}
			else
			{
				cout << "다시 입력하세요." << endl;
			}
		}
		bInputNormal = false;
		std::system("cls");
	
	if (playerAgreed > (playerNumber / 2))
	{
		cout << "인정." << endl;
		cout << "다음 사람이 입력하세요" << endl;
		return true;
	}
	else if (playerAgreed < (playerNumber / 2))
	{
		cout << "노인정." << endl;
		return false;
	}
	else
	{
		cout << "딱 절반이니 랜덤으로 갑시다." << endl;
		Sleep(1000);
		cout << ".";
		Sleep(1000);
		cout << ".";
		Sleep(1000);
		cout << "." << endl;
		Sleep(2000);
		bool agree = rand() % 2;
		if (agree)
		{
			cout << "인정." << endl;
			return true;
		}
		else
		{
			cout << "노인정." << endl;
			return false;
		}
	}
}



CAgreeDisagree::CAgreeDisagree()
{
	
}