#pragma once
#include "CAgreeDisagree.h"
#include "CCheckWord.h"
#include "CMainText.h"
// mother class

class CEndWord : public CAgreeDisagree, CCheckWord, CMainText
{
private:
	enum GAMEMODE
	{
		SINGLEPC,
		MULTIPC
	};

public:
	CEndWord();

	int SelectMode();

	bool Start();
	bool MakeRoom();
};

