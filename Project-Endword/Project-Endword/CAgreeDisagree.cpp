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
			cout << "�÷��̾� " << curPlayer << " ���� ";
			switch (playerAgrees[curPlayer - 1])
			{
			case true: cout << "���� �ϼ̽��ϴ�." << endl; break;
			case false: cout << "������ �ϼ̽��ϴ�." << endl; break;
			}
				
		}
		string buffer;
		cout << "�� �ܾ� �����Ͻðڽ��ϱ� ? " << endl;
		cout << "1. ����" << endl;
		cout << "2. ������" << endl;

		bool bInputNormal = false;
		while (!bInputNormal)
		{
			cin >> buffer;
			if (buffer == "����" || buffer == "1")
			{
				playerAgrees[curPlayer] = true;
				bInputNormal = true;
				
			}
			else if (buffer == "������" || buffer == "2")
			{
				playerAgrees[curPlayer] = false;
				bInputNormal = true;
			}
			else
			{
				cout << "�ٽ� �Է��ϼ���." << endl;
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
		cout << "����." << endl;
		cout << "���� ����� �Է��ϼ���" << endl;
		delete[] playerAgrees;
		return true;
	}
	else if (playerAgreed < (playerNumber / 2))
	{
		cout << "������." << endl;
		delete[] playerAgrees;
		return false;
	}
	else
	{
		cout << "�� �����̴� �������� ���ô�." << endl;
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
			cout << "����." << endl;
			delete[] playerAgrees;
			return true;
		}
		else
		{
			cout << "������." << endl;
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
		std::cout << nickname << " ���� ���� �ϼ̽��ϴ�." << std::endl;
		++playerAgreed;
	}
	else
	{
		std::cout << nickname << " ���� ������ �ϼ̽��ϴ�." << std::endl;
	}



		string buffer;
		cout << "�� �ܾ� �����Ͻðڽ��ϱ� ? " << endl;
		cout << "1. ����" << endl;
		cout << "2. ������" << endl;

		bool bInputNormal = false;
		while (!bInputNormal)
		{
			cin >> buffer;
			if (buffer == "����" || buffer == "1")
			{
				++playerAgreed;
				bInputNormal = true;
				
			}
			else if (buffer == "������" || buffer == "2")
			{
				bInputNormal = true;
			}
			else
			{
				cout << "�ٽ� �Է��ϼ���." << endl;
			}
		}
		bInputNormal = false;
		std::system("cls");
	
	if (playerAgreed > (playerNumber / 2))
	{
		cout << "����." << endl;
		cout << "���� ����� �Է��ϼ���" << endl;
		return true;
	}
	else if (playerAgreed < (playerNumber / 2))
	{
		cout << "������." << endl;
		return false;
	}
	else
	{
		cout << "�� �����̴� �������� ���ô�." << endl;
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
			cout << "����." << endl;
			return true;
		}
		else
		{
			cout << "������." << endl;
			return false;
		}
	}
}



CAgreeDisagree::CAgreeDisagree()
{
	
}