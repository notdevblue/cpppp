#include "CMainText.h"

CMainText::CMainText()
{
	system(" mode  con lines=20   cols=56 ");
	//cout << "�÷��̾� ���� �Է��ϼ���" << endl;
	//cin >> player;
}

CMainText::~CMainText()
{}

void CMainText::Gotoxy(int x, int y)
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(consoleHandle, pos);
}

int CMainText::MenuDraw()
{
	int x = 24;
	int y = 12;
	Gotoxy(x - 2, y);
	cout << "> ���ӽ���";
	Gotoxy(x, y+1);
	cout << "�������� ";
	Gotoxy(x, y+2);
	cout << "  ����   ";
	while (1) {
		int n = KeyControl();
		switch (n)
		{
		case UP:
			if (y > 12) {
				Gotoxy(x - 2, y);
				cout << " ";
				Gotoxy(x - 2, --y);
				cout << ">";
			}
			break;
		case DOWN:
			if (y < 14) {
				Gotoxy(x - 2, y);
				cout << " ";
				Gotoxy(x - 2, ++y);
				cout << ">";
			}
			break;
		case SUBMIT: {
			return y - 12;
			}
		}
	}
}

int CMainText::KeyControl()
{
	int temp = _getch();
	if (temp == 87 || temp == 119){
		return UP;
	}else if (temp == 83 || temp == 115){
		return DOWN;
	}else if (temp == 32){
		return SUBMIT;
	}
}

void CMainText::InfoDraw()
{
	system("cls");
	cout << "��������";

	while(1){
		if (KeyControl() == SUBMIT)
			break;
	}
}

int CMainText::MenuPlay() {
	while (1)
	{
		int menuCode = MenuDraw();
		if (menuCode == 0) {
			return(0);
		}
		else if (menuCode == 1) {
			InfoDraw();
		}
		else if (menuCode == 2) {
			system("cls");
			Gotoxy(0, 0);
			printf("������ �����մϴ�...\n�ƹ� Ű�� ���� �����Ͻÿ�...\n");
			_getch();
			
			exit(0);
		}
		system("cls");
	}
}

void ServerText() 
{
	
}