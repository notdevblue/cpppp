#include "CEndWord.h"

void CEndWord::Start()
{
	CMainText mainmenu;
	CCheckWord word;
	CAgreeDisagree agree;

	word.FirstWord();

	while (true)
	{
		
		if (word.WordInputCheck())
		{
			if (!agree.AgreeDisagree())
			{
				break;
			}
		}
	}
	
	return;
}