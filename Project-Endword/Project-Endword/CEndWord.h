#pragma once
#include "CAgreeDisagree.h"
#include "CCheckWord.h"
#include "CMainText.h"
// mother class

class CEndWord/* : public CAgreeDisagree, CCheckWord, CMainText*/
{
private:
	enum GAMEMODE
	{
		SINGLEPC,
		MULTIPC
	};

	int iPlayerNumber;

	CCheckWord wordCheck;
	CAgreeDisagree agreeDisagree;
	CMainText mainText;

public:
	CEndWord();

	int SelectMode();

	void PlayerNumSet();

	bool Start();
};

