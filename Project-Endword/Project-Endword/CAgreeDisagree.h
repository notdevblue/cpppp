#pragma once
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <Windows.h>


using namespace std;


//인정 노인정 시스템

class CAgreeDisagree
{
public:
	/// <summary>
	/// 인정이면 참을, 노인정이면 거짓을 리턴
	/// </summary>
	/// <returns></returns>
	bool AgreeDisagree();
};