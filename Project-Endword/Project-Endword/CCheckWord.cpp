#include "CCheckWord.h"
//#include "CMainText.cpp"
#define CYAN 3 
#define WHITE 15 
#include <windows.h>
#include <conio.h>

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

void CCheckWord::PlayerName() 
{
	int x = 24;
	int y = 12;
	Gotoxy(x - 2, y);
	TextColor(CYAN);
	wcout << "�÷��̾� 1" << endl;
	TextColor(WHITE);
	wcout << "�÷��̾� 2" << endl;
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
