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

	void FirstWord();
	bool WordInputCheck();
};

