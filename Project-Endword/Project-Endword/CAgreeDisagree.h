#pragma once
#define _WINSOCKAPI_
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <Windows.h>


using namespace std;


//���� ������ �ý���

class CAgreeDisagree
{
public:
	CAgreeDisagree();

	/// <summary>
	/// �����̸� ����, �������̸� ������ ����
	/// </summary>
	/// <returns></returns>
	bool AgreeDisagree(int);
	bool AgreeDisagreeClient(int, int, LPSTR);

};