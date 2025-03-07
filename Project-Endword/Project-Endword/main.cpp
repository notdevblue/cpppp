// C++++ 연구반
// 김원식, 유건욱, 한우엽, 강기호, 김동하

// 우앱 서버
// 건욱, 원식 클라이언트
// 기호, 동하 도움
#include "CEndWord.h"
#include "CServer.h"

#pragma comment(lib, "ws2_32")


int main()
{
#ifdef DEBUG
	printf("!!! 디버그 모드 !!!\n\r");
	printf("디버그 선언 위치 : CServer.h");
	Sleep(1500);
#endif
	CEndWord game;
	if (!game.Start())
	{
#ifdef DEBUG
		printf("서버 모드에 들어와 있어요.\n\r");
		printf("안타깝게도 아직 개발 중인 기능이라서 아직 작동하지 않습니다...\r\n아무 키나 눌러 종료하세요...\r\n");
		_getch();
		return(0);
#endif // DEBUG

		CServer server;
		if (!server.FIsHost())
		{
			server.JoinServer();
		}
		else
		{
			server.InitServer();
			std::cout << "아무 키나 눌러 종료하세요..." << std::endl;
			_getch();
		}
	}

	return(0);
}

