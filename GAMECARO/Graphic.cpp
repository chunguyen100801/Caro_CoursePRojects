#include "Graphic.h"
#include "Common.h"
#pragma comment (lib, "winmm.lib")
//THÔNG BÁO THẮNG THUA HÒA
void win1(int i)
{
	GotoXY(3, 6);  TextColor(i); cout << "XXXXXXX       XXXXXXX      WWWWWWWW                           WWWWWWWW     IIIIIIIIII     NNNNNNNN        NNNNNNNN" << endl;
	GotoXY(3, 7);  TextColor(i); cout << "X:::::X       X:::::X      W::::::W                           W::::::W     I::::::::I     N:::::::N       N::::::N" << endl;
	GotoXY(3, 8);  TextColor(i); cout << "X:::::X       X:::::X      W::::::W                           W::::::W     I::::::::I     N::::::::N      N::::::N" << endl;
	GotoXY(3, 9);  TextColor(i); cout << "X::::::X     X::::::X      W::::::W                           W::::::W     II::::::II     N:::::::::N     N::::::N" << endl;
	GotoXY(3, 10); TextColor(i); cout << "XXX:::::X   X:::::XXX       W:::::W           WWWWW           W:::::W        I::::I       N::::::::::N    N::::::N" << endl;
	GotoXY(3, 11); TextColor(i); cout << "   X:::::X X:::::X           W:::::W         W:::::W         W:::::W         I::::I       N:::::::::::N   N::::::N" << endl;
	GotoXY(3, 12); TextColor(i); cout << "    X:::::X:::::X             W:::::W       W:::::::W       W:::::W          I::::I       N:::::::N::::N  N::::::N" << endl;
	GotoXY(3, 13); TextColor(i); cout << "     X:::::::::X               W:::::W     W:::::::::W     W:::::W           I::::I       N::::::N N::::N N::::::N" << endl;
	GotoXY(3, 14); TextColor(i); cout << "     X:::::::::X                W:::::W   W:::::W:::::W   W:::::W            I::::I       N::::::N  N::::N:::::::N" << endl;
	GotoXY(3, 15); TextColor(i); cout << "    X:::::X:::::X                W:::::W W:::::W W:::::W W:::::W             I::::I       N::::::N   N:::::::::::N" << endl;
	GotoXY(3, 16); TextColor(i); cout << "   X:::::X X:::::X                W:::::W:::::W   W:::::W:::::W              I::::I       N::::::N    N::::::::::N" << endl;
	GotoXY(3, 17); TextColor(i); cout << "XXX:::::X   X:::::XXX              W:::::::::W     W:::::::::W               I::::I       N::::::N     N:::::::::N" << endl;
	GotoXY(3, 18); TextColor(i); cout << "X::::::X     X::::::X               W:::::::W       W:::::::W              II::::::II     N::::::N      N::::::::N" << endl;
	GotoXY(3, 19); TextColor(i); cout << "X:::::X       X:::::X                W:::::W         W:::::W               I::::::::I     N::::::N       N:::::::N" << endl;
	GotoXY(3, 20); TextColor(i); cout << "X:::::X       X:::::X                 W:::W           W:::W                I::::::::I     N::::::N        N::::::N" << endl;
	GotoXY(3, 21); TextColor(i); cout << "XXXXXXX       XXXXXXX                  WWW             WWW                 IIIIIIIIII     NNNNNNNN         NNNNNNN" << endl;
}
void win2(int i)
{
	GotoXY(3, 6); TextColor(i);  cout << "     OOOOOOOOO             WWWWWWWW                           WWWWWWWW     IIIIIIIIII     NNNNNNNN        NNNNNNNN";
	GotoXY(3, 7); TextColor(i);  cout << "   OO:::::::::OO           W::::::W                           W::::::W     I::::::::I     N:::::::N       N::::::N";
	GotoXY(3, 8); TextColor(i);  cout << " OO:::::::::::::OO         W::::::W                           W::::::W     I::::::::I     N::::::::N      N::::::N";
	GotoXY(3, 9); TextColor(i);  cout << "O:::::::OOO:::::::O        W::::::W                           W::::::W     II::::::II     N:::::::::N     N::::::N";
	GotoXY(3, 10); TextColor(i); cout << "O::::::O   O::::::O         W:::::W           WWWWW           W:::::W        I::::I       N::::::::::N    N::::::N";
	GotoXY(3, 11); TextColor(i); cout << "O:::::O     O:::::O          W:::::W         W:::::W         W:::::W         I::::I       N:::::::::::N   N::::::N";
	GotoXY(3, 12); TextColor(i); cout << "O:::::O     O:::::O           W:::::W       W:::::::W       W:::::W          I::::I       N:::::::N::::N  N::::::N";
	GotoXY(3, 13); TextColor(i); cout << "O:::::O     O:::::O            W:::::W     W:::::::::W     W:::::W           I::::I       N::::::N N::::N N::::::N";
	GotoXY(3, 14); TextColor(i); cout << "O:::::O     O:::::O             W:::::W   W:::::W:::::W   W:::::W            I::::I       N::::::N  N::::N:::::::N";
	GotoXY(3, 15); TextColor(i); cout << "O:::::O     O:::::O              W:::::W W:::::W W:::::W W:::::W             I::::I       N::::::N   N:::::::::::N";
	GotoXY(3, 16); TextColor(i); cout << "O:::::O     O:::::O               W:::::W:::::W   W:::::W:::::W              I::::I       N::::::N    N::::::::::N";
	GotoXY(3, 17); TextColor(i); cout << "O::::::O   O::::::O                W:::::::::W     W:::::::::W               I::::I       N::::::N     N:::::::::N";
	GotoXY(3, 18); TextColor(i); cout << "O:::::::OOO:::::::O                 W:::::::W       W:::::::W              II::::::II     N::::::N      N::::::::N";
	GotoXY(3, 19); TextColor(i); cout << " OO:::::::::::::OO                   W:::::W         W:::::W               I::::::::I     N::::::N       N:::::::N";
	GotoXY(3, 20); TextColor(i); cout << "   OO:::::::::OO                      W:::W           W:::W                I::::::::I     N::::::N        N::::::N";
	GotoXY(3, 21); TextColor(i); cout << "     OOOOOOOOO                         WWW             WWW                 IIIIIIIIII     NNNNNNNN         NNNNNNN";


}
void draw(int i)
{
	GotoXY(3, 6);  TextColor(i);  cout << "DDDDDDDDDDDDD          RRRRRRRRRRRRRRRRR                     AAA       WWWWWWWW                           WWWWWWWW";
	GotoXY(3, 7);  TextColor(i);  cout << "D::::::::::::DDD       R::::::::::::::::R                   A:::A      W::::::W                           W::::::W";
	GotoXY(3, 8);  TextColor(i);  cout << "D:::::::::::::::DD     R::::::RRRRRR:::::R                 A:::::A     W::::::W                           W::::::W";
	GotoXY(3, 9);  TextColor(i);  cout << "DDD:::::DDDDD:::::D    RR:::::R     R:::::R               A:::::::A    W::::::W                           W::::::W";
	GotoXY(3, 10); TextColor(i);  cout << "  D:::::D    D:::::D     R::::R     R:::::R              A:::::::::A    W:::::W           WWWWW           W:::::W";
	GotoXY(3, 11); TextColor(i);  cout << "  D:::::D     D:::::D    R::::R     R:::::R             A:::::A:::::A    W:::::W         W:::::W         W:::::W";
	GotoXY(3, 12); TextColor(i);  cout << "  D:::::D     D:::::D    R::::RRRRRR:::::R             A:::::A A:::::A    W:::::W       W:::::::W       W:::::W";
	GotoXY(3, 13); TextColor(i);  cout << "  D:::::D     D:::::D    R:::::::::::::RR             A:::::A   A:::::A    W:::::W     W:::::::::W     W:::::W";
	GotoXY(3, 14); TextColor(i);  cout << "  D:::::D     D:::::D    R::::RRRRRR:::::R           A:::::A     A:::::A    W:::::W   W:::::W:::::W   W:::::W";
	GotoXY(3, 15); TextColor(i);  cout << "  D:::::D     D:::::D    R::::R     R:::::R         A:::::AAAAAAAAA:::::A    W:::::W W:::::W W:::::W W:::::W";
	GotoXY(3, 16); TextColor(i);  cout << "  D:::::D     D:::::D    R::::R     R:::::R        A:::::::::::::::::::::A    W:::::W:::::W   W:::::W:::::W";
	GotoXY(3, 17); TextColor(i);  cout << "  D:::::D    D:::::D     R::::R     R:::::R       A:::::AAAAAAAAAAAAA:::::A    W:::::::::W     W:::::::::W";
	GotoXY(3, 18); TextColor(i);  cout << "DDD:::::DDDDD:::::D    RR:::::R     R:::::R      A:::::A             A:::::A    W:::::::W       W:::::::W";
	GotoXY(3, 19); TextColor(i);  cout << "D:::::::::::::::DD     R::::::R     R:::::R     A:::::A               A:::::A    W:::::W         W:::::W";
	GotoXY(3, 20); TextColor(i);  cout << "D::::::::::::DDD       R::::::R     R:::::R    A:::::A                 A:::::A    W:::W           W:::W";
	GotoXY(3, 21); TextColor(i);  cout << "DDDDDDDDDDDDD          RRRRRRRR     RRRRRRR   AAAAAAA                   AAAAAAA    WWW             WWW";

}


void Flag()
{
	for (int i = 0; i < 120; i++)
	{
		BackgroundColor(i); GotoXY(i, 4); cout << " ";
		BackgroundColor(i); GotoXY(120 - i, 23); cout << " ";
		Sleep(20);
	}
}

void DRAW()
{
	Cursor(false);
	Flag();
	BackgroundColor(0);
	for (int i = 1; i < 15; i++)
	{
		draw(i); Sleep(150);
	}
}
void WIN1()
{
	Cursor(false);
	Flag();
	BackgroundColor(0);
	for (int i = 1; i < 15; i++)
	{
		win1(i); Sleep(150);
	}
}
void WIN2()
{
	Cursor(false);
	Flag();
	BackgroundColor(0);
	for (int i = 1; i < 15; i++)
	{
		win2(i); Sleep(150);
	}
}
//===============================
void Loading()
{
	
	TextColor(15);
	BackgroundColor(0);
	system("cls");
	GotoXY(50, 10); TextColor(7);
	cout << "  LOADING....";
	PlaySound(TEXT("Loading.wav"), NULL, SND_FILENAME);
	for (int i = 45; i < 68; i++)
	{
		GotoXY(i, 12); TextColor(202);
		cout << " ";
		Sleep(10);
	}
	TextColor(15);
	BackgroundColor(0);
	system("cls");
}

void caro(int i)
{

	TextColor(i + 6);
	GotoXY(28, 3); cout << " @@@@@@@@@@ " << endl;
	GotoXY(28, 4); cout << "@@@       @@" << endl;
	GotoXY(28, 5); cout << "@@@          " << endl;
	GotoXY(28, 6); cout << "@@@         " << endl;
	GotoXY(28, 7); cout << "@@@          " << endl;
	GotoXY(28, 8); cout << "@@@          " << endl;
	GotoXY(28, 9); cout << "@@@       @@" << endl;
	GotoXY(28, 10); cout << " @@@@@@@@@@ " << endl;


	TextColor(i);
	GotoXY(43, 3); cout << "    @@@@@@    " << endl;
	GotoXY(43, 4); cout << "  @@@    @@@  " << endl;
	GotoXY(43, 5); cout << " @@@      @@@ " << endl;
	GotoXY(43, 6); cout << "@@@        @@@" << endl;
	GotoXY(43, 7); cout << "@@@@@@@@@@@@@@" << endl;
	GotoXY(43, 8); cout << "@@@        @@@" << endl;
	GotoXY(43, 9); cout << "@@@        @@@" << endl;
	GotoXY(43, 10); cout << "@@@        @@@" << endl;


	TextColor(i + 1);
	GotoXY(61, 3); cout << "@@@@@@@@@@@  " << endl;
	GotoXY(61, 4); cout << "@@@      @@@" << endl;
	GotoXY(61, 5); cout << "@@@       @@@           " << endl;
	GotoXY(61, 6); cout << "@@@      @@@          " << endl;
	GotoXY(61, 7); cout << "@@@@@@@@@@@          " << endl;
	GotoXY(61, 8); cout << "@@@     @@@               " << endl;
	GotoXY(61, 9); cout << "@@@      @@@            " << endl;
	GotoXY(61, 10); cout << "@@@       @@@                " << endl;



	TextColor(i + 3);
	GotoXY(78, 3); cout << " @@@@@@@@@@@@                   " << endl;
	GotoXY(78, 4); cout << "@@@        @@@     " << endl;
	GotoXY(78, 5); cout << "@@@        @@@       " << endl;
	GotoXY(78, 6); cout << "@@@        @@@   " << endl;
	GotoXY(78, 7); cout << "@@@        @@@      " << endl;
	GotoXY(78, 8); cout << "@@@        @@@       " << endl;
	GotoXY(78, 9); cout << "@@@        @@@      " << endl;
	GotoXY(78, 10); cout << " @@@@@@@@@@@@           " << endl;
}

void carotinh()
{

	TextColor(14);
	GotoXY(28, 3); cout << " @@@@@@@@@@ " << endl;
	GotoXY(28, 4); cout << "@@@       @@" << endl;
	GotoXY(28, 5); cout << "@@@          " << endl;
	GotoXY(28, 6); cout << "@@@         " << endl;
	GotoXY(28, 7); cout << "@@@          " << endl;
	GotoXY(28, 8); cout << "@@@          " << endl;
	GotoXY(28, 9); cout << "@@@       @@" << endl;
	GotoXY(28, 10); cout << " @@@@@@@@@@ " << endl;

	TextColor(9);
	GotoXY(43, 3); cout << "    @@@@@@    " << endl;
	GotoXY(43, 4); cout << "  @@@    @@@  " << endl;
	GotoXY(43, 5); cout << " @@@      @@@ " << endl;
	GotoXY(43, 6); cout << "@@@        @@@" << endl;
	GotoXY(43, 7); cout << "@@@@@@@@@@@@@@" << endl;
	GotoXY(43, 8); cout << "@@@        @@@" << endl;
	GotoXY(43, 9); cout << "@@@        @@@" << endl;
	GotoXY(43, 10); cout << "@@@        @@@" << endl;

	TextColor(10);
	GotoXY(61, 3); cout << "@@@@@@@@@@@  " << endl;
	GotoXY(61, 4); cout << "@@@      @@@" << endl;
	GotoXY(61, 5); cout << "@@@       @@@           " << endl;
	GotoXY(61, 6); cout << "@@@      @@@          " << endl;
	GotoXY(61, 7); cout << "@@@@@@@@@@@          " << endl;
	GotoXY(61, 8); cout << "@@@     @@@               " << endl;
	GotoXY(61, 9); cout << "@@@      @@@            " << endl;
	GotoXY(61, 10); cout << "@@@       @@@                " << endl;

	TextColor(12);
	GotoXY(78, 3); cout << " @@@@@@@@@@@@                   " << endl;
	GotoXY(78, 4); cout << "@@@        @@@     " << endl;
	GotoXY(78, 5); cout << "@@@        @@@       " << endl;
	GotoXY(78, 6); cout << "@@@        @@@   " << endl;
	GotoXY(78, 7); cout << "@@@        @@@      " << endl;
	GotoXY(78, 8); cout << "@@@        @@@       " << endl;
	GotoXY(78, 9); cout << "@@@        @@@      " << endl;
	GotoXY(78, 10); cout << " @@@@@@@@@@@@           " << endl;
}

void nhapnhay()
{
	for (int i = 1; i < 10; i++)
	{
		caro(i);
		Sleep(70);
	}
	PlaySound(TEXT("Theme.wav"), NULL, SND_FILENAME | SND_LOOP | SND_ASYNC);
}