#include "Header.h"
#include "Common.h"
#include "LoadFile.h"
#include "GlobalVar.h"
#include "Menu.h"
#include "Graphic.h"
#pragma comment (lib, "winmm.lib")

void main()
{

	ResizeConsole(120, 35);
	SetConsoleTitle(TEXT("GAME CARO"));//đặt tiêu đề
	FixConsoleWindow();
	Cursor(false);


	//system("cls");
	//StartGame();
	//control();
	//system("cls");

	BackgroundColor(0);
	system("cls");
	carotinh();
	nhapnhay();


	MainMenu();
}
