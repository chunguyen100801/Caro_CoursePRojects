#include <iostream>
#include "Common.h"
#include <conio.h>
#include "Menu.h"
#include "LoadFile.h"
#include "Header.h"
#include "Graphic.h"
#pragma comment (lib, "winmm.lib")

extern char _COMMAND;
extern bool _TURN;
extern short _mode;
struct _POINT { int x, y, c; };
extern _POINT _A[BOARD_SIZE][BOARD_SIZE];
extern int _Round;
extern int _demX, _demO;
extern int _WinX, _WinO;
extern int _demRound;
extern string _erX, _erO;


//MENU Ở MÀN HÌNH CHÍNH
void MainMenu()
{
	
	Cursor(false);
	while (1)
	{
		TextColor(15);
		BackgroundColor(0);
		system("cls");
		carotinh();
		_COMMAND = -1;
		int pos = 0;
		GotoXY(55, 19);
		TextColor(26);
		BackgroundColor(64);
		cout << char(30);
		GotoXY(55, 33);
		cout << char(31);

		//TextColor(15);
		//BackgroundColor(64);
		GotoXY(55, 20);
		cout << "W";
		GotoXY(55, 32);
		cout << "S";

		TextColor(15);
		BackgroundColor(64);
		GotoXY(52, 22);
		cout << "NEW GAME";
		GotoXY(51, 24);
		cout << "LOAD GAME";
		GotoXY(50, 26);
		cout << "HOW TO PLAY";
		GotoXY(53, 28);
		cout << "ABOUT";
		GotoXY(54, 30);
		cout << "QUIT";
		bool validEnter = true;
		while (_COMMAND != 13)
		{
			TextColor(44);
			BackgroundColor(64);
			GotoXY(48, 22 + pos);
			cout << char(16);
			GotoXY(62, 22 + pos);
			cout << char(17);
			_COMMAND = toupper(_getch());

			GotoXY(48, 22 + pos);
			cout << " ";
			GotoXY(62, 22 + pos);
			cout << " ";

			if (_COMMAND == 'S')
			{
				PlaySound(L"MenuMove.wav", NULL, SND_FILENAME );
				if (pos < 8) pos += 2;
			}
			else if (_COMMAND == 'W')
			{
				PlaySound(L"MenuMove.wav", NULL, SND_FILENAME );
				if (pos > 0) pos -= 2;
			}

		}
		_COMMAND = -1;
		PlaySound(L"BoardCheck.wav", NULL, SND_FILENAME);
		if (pos == 2)
		{
			
			OpenFile(0);
			system("cls");
			DrawBoard(BOARD_SIZE);
			demLuot();
			Luot();
			UpdateBoard();
			updateScore();
			control();
		}
		else if (pos == 4)
		{
			while (_COMMAND != 13)
			{

				system("cls");
				TextColor(8);
				BackgroundColor(0);
				GotoXY(20, 21);
				cout << "                  This app supports 2 common rules";

				GotoXY(20, 23);
				cout << " + GOMOKU (Freestyle): The winner is the fist  player to get an unbroken";
				GotoXY(20, 24);
				cout << "  row of five stones horizontally, vertically, or diagonally";
				GotoXY(20, 25);
				cout << " + CARO (Block rule) : The winner must have an overline or unbroken";
				GotoXY(20, 26);
				cout << " row of five stones that mustn't be blocked at both ends (XOOOOOX, OXXXXXO)";
				TextColor(18);
				BackgroundColor(0);
				GotoXY(20, 28);
				cout << "                       Press ENTER to go back";
				_COMMAND = toupper(_getch());
				if (_COMMAND != 13)
				{
					TextColor(12);
					BackgroundColor(64);
					GotoXY(20, 28);
					cout << "                       Press ENTER to go back";
					Sleep(20);
				}
			}
			MainMenu();
		}
		else if (pos == 0)
		{
			_Round = 0;
			_COMMAND = -1;
			_mode = 2;
			_erX = "Player1";
			_erO = "Player2";
			control0();
			//StartGame();
			//control();
		}
		else if (pos == 6)
		{
			system("cls");

			TextColor(8);
			BackgroundColor(0);
			GotoXY(20, 23);
			cout << "                      20120396 - TRAN ANH TUAN";
			GotoXY(20, 24);
			cout << "                      20120398 - BUI THANH TUNG";
			GotoXY(20,25);
			cout << "                      20120427 - LE NHUT ANH";
			GotoXY(20, 26);
			cout << "                      20120443 - NGUYEN TAN CHU";

			TextColor(18);
			BackgroundColor(0);
			GotoXY(20, 28);
			cout << "                      Press ANY KEY to go back";
			_getch();
		}
		else if (pos == 8)
		{
			system("cls");
			exit(1);
		}

	}

}

//MENU NEWGAME
void menu0()
{
	TextColor(15);
	BackgroundColor(64);
	GotoXY(51, 23);
	cout << "PLAY GAME";
	GotoXY(50, 24);
	if (_mode == 1) cout << "MODE: GOMOKU";
	else cout << "MODE:   CARO";
	GotoXY(50, 25);
	cout << "ROUND: " << _Round;
	_COMMAND = -1;
	GotoXY(50, 26);
	cout << "PLAYER ID ";
	GotoXY(53, 27);
	cout << "BACK";
}

//HÀM ĐIỀU KHIỂN MENU NEWGAME
void control0()
{
	int pos0 = 0;
	system("cls");
	GotoXY(55, 20);
	TextColor(26);
	BackgroundColor(64);
	cout << char(30);
	GotoXY(55, 30);
	cout << char(31);
	GotoXY(55, 21);
	cout << "W";
	GotoXY(55, 29);
	cout << "S";
	TextColor(12);

	while (_COMMAND != 13)
	{

		if ((pos0 != 0) && (pos0 != 3) && (pos0 != 4))
		{
			TextColor(12);
			BackgroundColor(64);
			GotoXY(44, 23 + pos0);
			cout << "- " << char(17)<<" A";

			GotoXY(63, 23 + pos0);
			TextColor(10);
			BackgroundColor(64);
			cout <<"D "<< char(16) << " +";
		}
		else
		{
			TextColor(10);
			BackgroundColor(64);
			GotoXY(47, 23 + pos0);
			cout << char(16);

			GotoXY(63, 23 + pos0);
			TextColor(10);
			BackgroundColor(64);
			cout << char(17);
		}


		TextColor(15);
		BackgroundColor(64);
		GotoXY(51, 23);
		cout << "PLAY GAME";
		GotoXY(50, 24);
		if (_mode == 1) cout << "MODE: GOMOKU";
		else cout << "MODE:   CARO";
		GotoXY(50, 25);
		if (_Round == 0)
		{
			cout << "ROUND: OFF";
		}
		else 
		{
			cout << "ROUND: " << _Round;
		}
		_COMMAND = -1;
		GotoXY(50, 26);
		cout << "PLAYER ID ";
		GotoXY(53, 27);
		cout << "BACK";
		_COMMAND = toupper(_getch());

		if ((pos0 == 0) && (_COMMAND == 13))
		{
			PlaySound(L"BoardCheck.wav", NULL, SND_FILENAME );
			StartGame();
			control();
			
		}

		if (pos0 == 1)
		{
			if ((_COMMAND == 'A') || (_COMMAND == 'D'))
			{
				PlaySound(L"MenuMove.wav", NULL, SND_FILENAME );
				if (_mode == 1) _mode = 2;
				else _mode = 1;
				_COMMAND = -1;
			}
		}
		 if (pos0 == 2)
		{

			if ((_COMMAND == 'A') && (_Round - 1 >= 0))
			{
				PlaySound(L"MenuMove.wav", NULL, SND_FILENAME );
				_Round = _Round - 1;
				_COMMAND = -1;
				if (_Round == 2) _Round = 1;
			}
			else if (_COMMAND == 'D')
			{
				PlaySound(L"MenuMove.wav", NULL, SND_FILENAME);
				if (_Round+1 == 51) _Round = 50;
				else _Round = _Round + 1;

				_COMMAND = -1;
				if (_Round == 2) _Round = 3;
			}
			GotoXY(50, 25);
			cout << "ROUND:     ";

// QUY DINH TOI DA 50 ROUND DE THUAN LOI CHO VIEC KHAI BAO MANG LUU KET QUA TUNG ROUND
		}
		if ((pos0 == 3) && (_COMMAND==13))
		{
			SetName();
			menu0();

			//Ve lai con tro
			GotoXY(55, 20);
			TextColor(26);
			BackgroundColor(64);
			cout << char(30);
			GotoXY(55, 30);
			cout << char(31);
			GotoXY(55, 21);
			cout << "W";
			GotoXY(55, 29);
			cout << "S";
			TextColor(12);
		}

		TextColor(12);
		BackgroundColor(64);
		GotoXY(44, 23 + pos0);
		cout << "     ";
		GotoXY(63, 23 + pos0);
		cout << "     ";

		if ((_COMMAND == 'W') && (pos0 - 1 >= 0))
		{
			PlaySound(L"MenuMove.wav", NULL, SND_FILENAME);
			_COMMAND = -1;
			pos0 = pos0 - 1;
		}
		else if ((_COMMAND == 'S') && (pos0 + 1 < 5))
		{
			PlaySound(L"MenuMove.wav", NULL, SND_FILENAME);
			_COMMAND = -1;
			pos0 = pos0 + 1;
		}


	}
	PlaySound(L"BoardCheck.wav", NULL, SND_FILENAME | SND_ASYNC);
}

//HÀM NHẬP TÊN NGƯỜI CHƠI
void SetName()
{
	Cursor(1);
	system("cls");
	_COMMAND = -1;

	GotoXY(50, 24);
	cout << "PLAYER ID X: " << _erX;
	GotoXY(50, 26);
	cout << "PLAYER ID O: " << _erO;

	GotoXY(50, 24);
	TextColor(15);
	BackgroundColor(64);
	cout << "PLAYER ID X:               "; ///cls
	GotoXY(50, 24);
	cout << "PLAYER ID X: "; cin >> _erX;
	GotoXY(50, 26);
	TextColor(15);
	BackgroundColor(64);
	cout << "PLAYER ID O:               "; ///cls
	GotoXY(50, 26);
	cout << "PLAYER ID O: "; cin >> _erO;

	GotoXY(46, 28);
	TextColor(2);
	Cursor(0);
	system("pause");
	system("cls");
}




