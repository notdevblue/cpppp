#pragma once
#include <iostream>
#include <string>

using namespace std;

// 가나'다'
// '다'라마 == 가능
// '라'마사 == 불가능
// 이 기능 구현
// 첫 단어
class CCheckWord
{
private:
	wstring wordFirst;
	wstring wordLast;

public:
	CCheckWord();

	void FirstWord();
	bool WordInputCheck();
};

