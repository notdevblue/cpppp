#pragma once
#include <iostream>
#include <string>

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

public:
	CCheckWord();

	void Gotoxy(int, int);
	void FirstWord();
	bool WordInputCheck();
	void TextColor(int foreground);
	void PlayerName();
};

