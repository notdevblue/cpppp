#include<Windows.h>
#include<iostream>
#include<conio.h>
#define UP 0
#define DOWN 1
#define SUBMIT 2

using namespace std;

class CMainText
{
public:
	CMainText();
	~CMainText();
private:
public:
	int MenuDraw();
	void Gotoxy(int, int);
	int KeyControl();
	void InfoDraw();
	int MenuPlay();
};

