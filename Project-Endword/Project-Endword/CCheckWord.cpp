#include "CCheckWord.h"
#define GRAY 8 
#define WHITE 15 


CCheckWord::CCheckWord()
{
	iter = vWordList.begin();
	bIsAtList = false;
}

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

// TODO : thread 로 뺴야 할 듯 하다.
// 무한루프 돌려서 한 귀퉁이에 계속 나오도록.
void CCheckWord::PlayerName(LPSTR playerOne, LPSTR playerTwo, int activePlayer) 
{
	int x = 24;
	int y = 12;
	if (activePlayer == 1)
	{
		Gotoxy(x - 2, y);
		TextColor(WHITE);
		wcout << "플레이어 1 : " << playerOne << endl;
		TextColor(GRAY);
		wcout << "플레이어 2 : " << playerTwo;
	}
	else
	{
		TextColor(GRAY);
		wcout << "플레이어 1 : " << playerOne << endl;
		TextColor(WHITE);
		wcout << "플레이어 2 : " << playerTwo;
	}
}

void CCheckWord::CheckWord(wstring str)
{
	bIsAtList = str == wordLast;
}
void CCheckWord::CheckWordClient(wstring str, char* clientMsg)
{
	bIsAtList = clientMsg == (char*)wordLast.c_str();
}

void CCheckWord::WordInputCheck()
{
	while (true)
	{
		bIsAtList = false;
		std::wcout << wordFirst << endl;
		std::wcin >> wordLast;
		for (iter = vWordList.begin(); iter != vWordList.end(); ++iter)
		{
			CheckWord(*iter);
		}
		if (bIsAtList)
		{
			std::cout << "이미 사용한 단어입니다." << std::endl;
			continue;
		}
		if (wordFirst.back() == wordLast.front())
		{
			vWordList.push_back(wordLast);
			wordFirst = wordLast;
			return;
		}
	}
}

const wchar_t* CCheckWord::ShowWord()
{
	const wchar_t* wcs = wordLast.c_str();
	return wcs;
}

bool CCheckWord::WordInputCheckClient(char* clientMsg)
{
	bIsAtList = false;
	for (iter = vWordList.begin(); iter != vWordList.end(); ++iter)
	{
		CheckWordClient(*iter, clientMsg);
	}
	if (bIsAtList)
	{
		return true;
	}
	if (wordFirst.back() == wordLast.front())
	{
		vWordList.push_back(wordLast);
		wordFirst = wordLast;
		return false;
	}
	else
	{
		return false;
	}
}