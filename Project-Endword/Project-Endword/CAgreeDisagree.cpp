#include "CAgreeDisagree.h"

bool CAgreeDisagree::AgreeDisagree()
{
	srand((unsigned int)time(nullptr));

	bool playerAgrees[3] = {false};
		// TODO : �ӽ� ����
	int playerAgreed = 0;
	int playerCount = _countof(playerAgrees);


	for (int curPlayer = 0; curPlayer < playerCount; ++curPlayer)
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
	
	for (int curPlayer = 0; curPlayer < playerCount; ++curPlayer)
	{
		switch (playerAgrees[curPlayer])
		{
		case true: ++playerAgreed; break;
		case false: break;
		}
	}
	
	if (playerAgreed > (playerCount / 2))
	{
		cout << "����." << endl;
		cout << "���� ����� �Է��ϼ���" << endl;
		return true;
	}
	else if (playerAgreed < (playerCount / 2))
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