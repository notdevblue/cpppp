#include "CCheckWord.h"

CCheckWord::CCheckWord() {}


void CCheckWord::FirstWord()
{
	wcout << "���� �ܾ �Է��ϼ��� : ";
	wcin >> wordFirst;
	wcout << endl << "���� �ܾ�� " << wordFirst << " �Դϴ�." << endl;
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
