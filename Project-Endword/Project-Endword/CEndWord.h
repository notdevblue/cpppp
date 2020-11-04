#pragma once
#include "CAgreeDisagree.h"
#include "CCheckWord.h"
#include "CMainText.h"

// mother class

class CEndWord : public CAgreeDisagree, CCheckWord, CMainText
{
public:
	void Start();
};

