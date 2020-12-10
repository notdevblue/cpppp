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
	wcout << L"시작 단어를 입력하세요 : ";
	wcin >> wordFirst;
	wcout << endl << L"시작 단어는 " << wordFirst << L" 입니다." << endl;
	
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
	wcout << "플레이어 1" << endl;
	TextColor(WHITE);
	wcout << "플레이어 2" << endl;
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
