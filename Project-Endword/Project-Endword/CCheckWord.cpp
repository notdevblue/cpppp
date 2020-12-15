#include "CCheckWord.h"
#define GRAY 8 
#define WHITE 15 


CCheckWord::CCheckWord() {}

void CCheckWord::Gotoxy(int x, int y)
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(consoleHandle, pos);
}
void CCheckWord::FirstWord()
{
	wcout << L"���� �ܾ �Է��ϼ��� : ";
	wcin >> wordFirst;
	wcout << endl << L"���� �ܾ�� " << wordFirst << L" �Դϴ�." << endl;
	
}
void CCheckWord::TextColor(int foreground)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),foreground);

}

// TODO : thread �� ���� �� �� �ϴ�.
// ���ѷ��� ������ �� �����̿� ��� ��������.
void CCheckWord::PlayerName(LPSTR playerOne, LPSTR playerTwo, int activePlayer) 
{
	int x = 24;
	int y = 12;
	if (activePlayer == 1)
	{
		Gotoxy(x - 2, y);
		TextColor(WHITE);
		wcout << "�÷��̾� 1 : " << playerOne << endl;
		TextColor(GRAY);
		wcout << "�÷��̾� 2 : " << playerTwo;
	}
	else
	{
		TextColor(GRAY);
		wcout << "�÷��̾� 1 : " << playerOne << endl;
		TextColor(WHITE);
		wcout << "�÷��̾� 2 : " << playerTwo;
	}
}
bool CCheckWord::WordInputCheck()
{
	std::wcout << wordFirst << endl;
	std::wcin >> wordLast;
	if (wordFirst.back() == wordLast.front())
	{
		wordFirst = wordLast;
		return true;
	}
	else
	{
		return false;
	}
}
