// C++++ 연구반
// 김원식, 유건욱, 한우엽, 강기호, 김동하

#include "CEndWord.h"

int main()
{
	std::wcin.imbue(locale("korean"));
	std::wcout.imbue(locale("korean"));

	//cout << "게임을 시작하기에 앞서 간단한 룰 설명을 시작하겠습니다" << endl;
	//cout << "첫 플레이어가 단어를 입력합니다 \n그 뒤 두번 째 플레이어가 끝 말과 이어지는 단어를 입력합니다. \n단어가 존재하거나 이 정도 단어는 인정할 수 있는 단어다 싶으면 \n인정 또는 1을 입력하고\n이 단어는 절대 인정할 수 없는 것 같다면 \n노인정 또는 2를 입력하세요 \n그럼 지금부터 게임을 시작하겠습니다" << endl;
	//cout << "3인 게임 입니다. Enter 를 눌러 시작하세요..." << endl;
	//cin.get();

	CEndWord game;
	game.Start();
	return(0);
}