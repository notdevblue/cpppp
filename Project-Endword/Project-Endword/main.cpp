// C++++ ������
// �����, ���ǿ�, �ѿ쿱, ����ȣ, �赿��

// ��� ����
// �ǿ�, ���� Ŭ���̾�Ʈ
// ��ȣ, ���� ����
#include "CEndWord.h"
#include "CServer.h"

#pragma comment(lib, "ws2_32")


int main()
{
#ifdef DEBUG
	printf("!!! ����� ��� !!!\n\r");
	printf("����� ���� ��ġ : CServer.h");
	Sleep(1500);
#endif
	CEndWord game;
	if (!game.Start())
	{
#ifdef DEBUG
		printf("���� ��忡 ���� �־��.\n\r");
		printf("��Ÿ���Ե� ���� ���� ���� ����̶� ���� �۵����� �ʽ��ϴ�...\r\n�ƹ� Ű�� ���� �����ϼ���...\r\n");
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
			std::cout << "�ƹ� Ű�� ���� �����ϼ���..." << std::endl;
			_getch();
		}
	}

	return(0);
}

