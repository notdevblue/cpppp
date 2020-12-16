#pragma once
#define _WINSOCKAPI_
#include <iostream>
#include <string>
#include <windows.h>
#include <conio.h>
#include <vector>
#include <algorithm>
using namespace std;

// ����'��'
// '��'�� == ����
// '��'���� == �Ұ���
// �� ��� ����
// ù �ܾ�

class CCheckWord
{
private:
	wstring wordFirst;
	wstring wordLast;

	vector<wstring> vWordList;
	vector<wstring>::iterator iter;

	bool bIsAtList;

public:
	CCheckWord();
	
	const wchar_t* ShowWord();

	void CheckWord(wstring);
	void CheckWordClient(wstring, char*);
	void Gotoxy(int, int);
	void FirstWord();
	void WordInputCheck();
	void TextColor(int foreground);
	void PlayerName(LPSTR, LPSTR, int);

	bool WordInputCheckClient(char*);
};

