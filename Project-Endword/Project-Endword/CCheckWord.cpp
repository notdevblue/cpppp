#include "CCheckWord.h"

CCheckWord::CCheckWord() {}


void CCheckWord::FirstWord()
{
	wcout << "시작 단어를 입력하세요 : ";
	wcin >> wordFirst;
	wcout << endl << "시작 단어는 " << wordFirst << " 입니다." << endl;
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
