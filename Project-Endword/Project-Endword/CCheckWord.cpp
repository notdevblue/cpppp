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
			std::cout << "�̹� ����� �ܾ��Դϴ�." << std::endl;
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