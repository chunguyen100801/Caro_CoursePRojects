#include "Header.h"
#include "Common.h"
#include "LoadFile.h"
#include "Menu.h"
#include "Graphic.h"
#pragma comment (lib, "winmm.lib")
extern char  _COMMAND;
extern bool _TURN;
extern short _mode;
struct _POINT { int x, y, c; };
extern _POINT _A[BOARD_SIZE][BOARD_SIZE];
extern int _Round;
extern int _demX, _demO;
extern int _WinX, _WinO;
extern int _Round;
extern string _erX, _erO;
extern int _X;
extern int _Y;
extern int _demRound;
extern short _ArRound[];

void ResetData()
{
	for (int i = 0; i < BOARD_SIZE; i++)
	{
		for (int j = 0; j < BOARD_SIZE; j++)
		{
			_A[i][j].x = 4 * j + LEFT + 2;
			_A[i][j].y = 2 * i + TOP + 1;
			_A[i][j].c = 0; // 0 la chua ai danh, -1 la true danh, 1 la false danh
		}

	}
	_TURN = true; _COMMAND = -1; // gan luot, phim mac dinh
	_X = _A[0][0].x; _Y = _A[0][0].y; // thiet lap lai toa do ban dau
	_demO = 0;
	_demX = 0;
	if ((_Round==0) && (_demRound > 1))
	{
		if (_ArRound[_demRound - 1] == -1) _TURN = 0;
		else if ((_ArRound[_demRound - 1] == 0) && (_WinX > _WinO)) _TURN = 0;
	}
	GotoXY(_X, _Y);
}

//VẼ BÀN CỜ VÀ CÁC ĐỐI TƯỢNG KHÁC
void DrawBoard(int pSize)
{

	GotoXY(35,0);
	TextColor(2);
	BackgroundColor(0);
	cout << "              HCMUS - 20CTT3 - GROUP 2 ";
	Cursor(true);//hien con tro
	TextColor(7);
	BackgroundColor(64);

	//VẼ BÀN CỜ
	//Code ban co caro tham khao cua anh HUYNH THAI ANH (Khoa K17)
	for (int i = 0; i < pSize * 2; i++)
	{
	// Ve cot phai
		GotoXY(pSize * 4+LEFT, i + 1+TOP);
		if ((i + 1) % 2 == 1)
			cout << char(186);
		else
			cout << char(182);
	}
	// Dong thuong
	for (int i = 0; i < pSize * 2; i = i + 2)
	{
		GotoXY(LEFT, i+TOP);
		for (int j = 0; j < pSize * 4; j++)
		{
			if (j % 4 == 0)
				cout << char(197);
			else
				cout << char(196);
		}
	}
	// ##########################
	for (int i = 0; i < pSize * 2; i++)
	{
		// Ve cot trai
		GotoXY(LEFT, i + 1+TOP);
		if ((i + 1) % 2 == 1)
			cout << char(186);
		else
			cout << char(199);
	}
	// Cot thuong
	for (int i = 1; i < pSize * 2; i = i + 2)
	{
		for (int j = 0; j < pSize * 4; j = j + 4)
		{
			GotoXY(j+LEFT, i+TOP);
			if (j == 0)
				continue;
			cout << char(179);
		}
	}
	// Ve dong dau
	GotoXY(LEFT, TOP);
	for (int i = 0; i < pSize * 4; i++)
	{
		if (i % 4 == 0)
			cout << char(209);
		else
			cout << char(205);
	}
	GotoXY(LEFT, TOP); cout << char(201);
	GotoXY(pSize * 4+LEFT, TOP); cout << char(187);

	// Ve dong cuoi
	GotoXY(LEFT, pSize * 2+TOP);
	for (int i = 0; i < pSize * 4; i++)
	{
		if (i % 4 == 0)
			cout << char(207);
		else
			cout << char(205);
	}
	GotoXY(LEFT, pSize * 2+TOP); cout << char(200);
	GotoXY(pSize * 4+LEFT, pSize * 2+TOP);
	cout << char(188);


	// VẼ BẢNG ĐIỀU KHIỂU
	TextColor(56);
	BackgroundColor(0);

	for (int i = 3; i <= 50; i++)
	{
		GotoXY(i, 26);
		cout << char(205);
		GotoXY(i, 34);
		cout << char(205);
	}
	for (int i = 26; i <= 34; i++)
	{
		GotoXY(2, i);
		cout << char(186);
		GotoXY(50, i);
		cout << char(186);
		//GotoXY(118, i);
		//cout << char(186);

	}
	GotoXY(2, 26); cout << char(201);//bo goc trai tren
	GotoXY(2, 34); cout << char(200);//bo goc trai duoi
	GotoXY(50, 26); cout << char(187);//bo goc phai tren
	GotoXY(50, 34); cout << char(188);//bo goc phai duoi

	TextColor(56);
	BackgroundColor(0);

	//ve phim A
	GotoXY(12, 30); cout << "+---+";
	GotoXY(12, 31); cout << "| A |";
	GotoXY(12, 32); cout << "+---+";
	//ve phim S
	GotoXY(18, 30); cout << "+---+";
	GotoXY(18, 31); cout << "| S |";
	GotoXY(18, 32); cout << "+---+";
	//ve phim D
	GotoXY(24, 30); cout << "+---+";
	GotoXY(24, 31); cout << "| D |";
	GotoXY(24, 32); cout << "+---+";
	//ve phim W
	GotoXY(18, 27); cout << "+---+";
	GotoXY(18, 28); cout << "| W |";
	GotoXY(18, 29); cout << "+---+";
	//ve phim ENTER
	GotoXY(30, 29); cout << "+-------+";
	GotoXY(30, 30); cout << "| Enter |";
	GotoXY(30, 31); cout << "+-------+";\

	TextColor(7);
	GotoXY(7, 33); cout << "MOVE: W/S/A/D";
	GotoXY(29, 33); cout << "TICK: ENTER";

	GotoXY(55, 33);
	cout << "SAVE GAME: L           LOAD GAME: T           QUIT: ESC";

	OutBoard();

	TextColor(8);
	for (int i = 51; i <= 117; i++)
	{
		GotoXY(i, 1);
		cout << char(205);
		GotoXY(i, 34);
		cout << char(205);
	}
	for (int i = 1; i <= 34; i++)
	{
		GotoXY(51, i);
		cout << char(186);
		GotoXY(117, i);
		cout << char(186);
	}
	GotoXY(51, 1); cout << char(201);//bo goc trai tren
	GotoXY(51, 34); cout << char(200);//bo goc trai duoi
	GotoXY(117, 1); cout << char(187);//bo goc phai tren
	GotoXY(117, 34); cout << char(188);//bo goc phai duoi
}

void StartGame()
{
	system("cls");
	Loading();


	_WinX = 0, 
	_WinO = 0;
	_demRound = 1;

	TextColor(0);
	system("cls");

	ResetData();
	DrawBoard(BOARD_SIZE);
	Luot();
	demLuot();
}

int ProcessFinish(int pWhoWin)
{
	switch (pWhoWin)
	{
	case -1:
		PlaySound(TEXT("Win.wav"), NULL, SND_FILENAME | SND_ASYNC);
		Sleep(1000);
		
		BackgroundColor(0);
		system("cls");
		WIN1();
		//LineWin();
		break;
	case 1:
		PlaySound(TEXT("Win.wav"), NULL, SND_FILENAME | SND_ASYNC);
		Sleep(1000);
		
		BackgroundColor(0);
		system("cls");
		WIN2();
		//LineWin();
		break;
	case 0:
		Sleep(1000);
		BackgroundColor(0);
		system("cls");
		DRAW();
		break;
	case 2:
		_TURN = !_TURN;
		Luot();
	}

	GotoXY(_X, _Y);
	return pWhoWin;
}

bool AskContinue() //tra ve y/n
{

	GotoXY(47, 25);
	bool check = 1;
	TextColor(15);
	cout<<"Do you want to play again?";
	GotoXY(60, 26);
	cout << "<NO>";
	GotoXY(53, 26);
	TextColor(10);
	cout << "<YES>";

	_COMMAND = -1;
	while (_COMMAND != 13)
	{
		_COMMAND = toupper(_getch());
		if ((_COMMAND == 'A') || (_COMMAND == 'D'))
		{
			PlaySound(L"BoardMove.wav", NULL, SND_FILENAME | SND_ASYNC);
			check = !check;
		}

		if (check)
		{
			GotoXY(53, 26);
			TextColor(10);
			cout << "<YES>";
			TextColor(15);
			GotoXY(60, 26);
			cout << "<NO>";
		}
		else
		{
			GotoXY(53, 26);
			TextColor(15);
			cout << "<YES>";
			TextColor(10);
			GotoXY(60, 26);
			cout << "<NO>";
		}
	}
	PlaySound(L"BoardCheck.wav", NULL, SND_FILENAME | SND_ASYNC);
	return check;
}

//===================================
//ĐÁNH DẤU VÀO BÀN CỜ
int CheckBoard(int pX, int pY)
{
	for (int i = 0; i < BOARD_SIZE; i++)
		for (int j = 0; j < BOARD_SIZE; j++) 
			if (_A[i][j].x == pX && _A[i][j].y == pY && _A[i][j].c == 0)
			{
				if (_TURN == true)
				{
					_A[i][j].c = -1;
					_demX++;
				}
				else
				{
					_A[i][j].c = 1;
					_demO++;
				}
				return _A[i][j].c;
			}

	return 0;
}

//NHÓM HÀM DI CHUYỂN TRÊN BÀN CỜ
void MoveRight()
{
	if (_X == _A[BOARD_SIZE - 1][BOARD_SIZE - 1].x)
	{
		_X = _A[BOARD_SIZE - 1][BOARD_SIZE - 1].x;
		GotoXY(_X, _Y);
	}
	else
	{
		_X += 4;
		GotoXY(_X, _Y);
	}
}
void MoveLeft()
{
	if (_X == _A[0][0].x)
	{
		_X = _A[0][0].x;
		GotoXY(_X, _Y);
	}
	else
	{
		_X -= 4;
		GotoXY(_X, _Y);
	}
}
void MoveDown()
{
	if (_Y == _A[BOARD_SIZE - 1][BOARD_SIZE - 1].y)
	{
		_Y = _A[BOARD_SIZE - 1][BOARD_SIZE - 1].y;
		GotoXY(_X, _Y);
	}
	else
	{
		_Y += 2;
		GotoXY(_X, _Y);
	}
}
void MoveUp()
{
	if (_Y == _A[0][0].y)
	{
		_Y = _A[0][0].y;
		GotoXY(_X, _Y);
	}
	else
	{
		_Y -= 2;
		GotoXY(_X, _Y);
	}
}
//===================================


//HÀM KIỂM TRA BÀN CỜ ĐẦY
bool FullBoard()
{
	bool check = 1;
	for (int i = 0; i < BOARD_SIZE; i++)
	{
		for (int j = 0; j < BOARD_SIZE; j++)
		{
			if (_A[i][j].c == 0)
				{
				check = 0;
				return check;
				}
		}
	}
	for (int i = 0; i < BOARD_SIZE; i++)
		for (int j = 0; j < BOARD_SIZE; j++)
		{
			_X = _A[i][j].x;
			_Y = _A[i][j].y;
			GotoXY(_X, _Y);

			if (_A[i][j].c==-1)
			{
				TextColor(7);
				BackgroundColor(1);
				cout << "X";
			}
			else if (_A[i][j].c == 1)
			{
				TextColor(7);
				BackgroundColor(4);
				cout << "O";
			}
		}
	return check;
}

//HÀM ĐIẾM QUÂN TỪNG HÀNG
void dem(int i, int j, int& dem1, int& dem2)
{
	if (_A[i][j].c == -1)
	{
		dem2 = 0;
		dem1++;
	}
	else if (_A[i][j].c == 1)
	{
		dem1 = 0;
		dem2++;
	}
	else //gap o trong
	{
		dem1 = 0;
		dem2 = 0;
	}
}

//KT THẮNG THUA HÒA
int TestBoard()
{
	if (FullBoard()) return 0;
	if (CheckWin()) return (_TURN == true ? -1 : 1); // -1  ‘true’ thang (X THANG) ////SUA LAI KHI TAO MENU CHON MODE
	else return 2; // 2 chua ai thang
}

//NHÓM HÀM KIỂM TRA THẮNG THUA
bool Duyetdoc(bool& checkcaro)
{
	char x;
	if (_TURN == 1) 
	{
		TextColor(7);
		BackgroundColor(1);
		x = 'X';
	}
	else
	{
		TextColor(7);
		BackgroundColor(4);
		x = 'O';
	}

	int i, j;
	int dem1 = 0, dem2 = 0; //dem 1 dem so quan -1
	for (j = 0; j < BOARD_SIZE && ((dem1 < 5 && dem2 < 5 && _mode == 1) || (_mode == 2 && ((dem1 < 5 & dem2 < 5) || checkcaro == 0))); j++)
	{
		for (i = 0; i < BOARD_SIZE && ((dem1 < 5 && dem2 < 5 && _mode == 1) || (_mode == 2 && ((dem1 < 5 & dem2 < 5) || checkcaro == 0))); i++)
		{
			dem(i, j, dem1, dem2);
			if ((dem1 == 5) || (dem2 == 5))
			{
				int dem1_tmp = dem1;
				int dem2_tmp = dem2;

				dem(i + 1, j, dem1, dem2);
				if ((dem1 == 6) || (dem2 == 6)) checkcaro = 0;
				else
				{
					if ((i + 1 < BOARD_SIZE && _A[i + 1][j].c == 0) || (i - 5 >= 0 && _A[i - 5][j].c == 0)) checkcaro = 1;
					else
					{
						if (i-4==0)  checkcaro = 1;
						else  checkcaro = 0;
					}
				}
				dem1 = dem1_tmp;
				dem2 = dem2_tmp;
			}
		}
		if ((dem1 != 5) && (dem2 != 5)) //reset lai bien dem, khi chuyen cot
		{
			dem1 = 0;
			dem2 = 0;
		}

	}
	if ((dem1 == 5) || (dem2 == 5))
	{
		if (_mode == 1)
		{
			for (int h = i - 5; h < i; h++)
			{
				_X = _A[h][j - 1].x;
				_Y = _A[h][j - 1].y;
				GotoXY(_X, _Y);
				cout << x;
			}
			return 1;
		}
		else if ((_mode == 2) && (checkcaro == 1))
		{
			for (int h = i - 5; h < i; h++)
			{
				_X = _A[h][j - 1].x;
				_Y = _A[h][j - 1].y;
				GotoXY(_X, _Y);
				cout << x;
			}
			return 1;
		}
	}
	return 0;
}
bool Duyetngang(bool& checkcaro)
{
	char x;
	if (_TURN == 1)
	{
		TextColor(7);
		BackgroundColor(1);
		x = 'X';
	}
	else
	{
		TextColor(7);
		BackgroundColor(4);
		x = 'O';
	}
	int i, j;
	int dem1 = 0, dem2 = 0; //dem 1 dem so quan -1

	for (i = 0; i < BOARD_SIZE && ((dem1 < 5 && dem2 < 5 && _mode == 1) || (_mode == 2 && ((dem1 < 5 & dem2 < 5) || checkcaro == 0))); i++)
	{
		for (j = 0; j < BOARD_SIZE && ((dem1 < 5 && dem2 < 5 && _mode == 1) || (_mode == 2 && ((dem1 < 5 & dem2 < 5) || checkcaro == 0))); j++)
		{
			dem(i, j, dem1, dem2);

			if ((dem1 == 5) || (dem2 == 5))
			{
				int dem1_tmp = dem1;
				int dem2_tmp = dem2;

				dem(i, j+1, dem1, dem2);
				if ((dem1 == 6) || (dem2 == 6)) checkcaro = 0;
				else
				{
					if ((j + 1 < BOARD_SIZE && _A[i][j+1].c == 0) || (j - 5 >= 0 && _A[i][j-5].c == 0)) checkcaro = 1;
					else
					{
						if (j-4==0) checkcaro = 1;
						else checkcaro = 0;
					}
				}

				dem1 = dem1_tmp;
				dem2 = dem2_tmp;
			}
		}
		if ((dem1 != 5) && (dem2 != 5)) //reset lai bien dem, khi chuyen cot
		{
			dem1 = 0;
			dem2 = 0;
		}
	}
	if ((dem1 == 5) || (dem2 == 5))
	{
		if (_mode == 1)
		{
			for (int h = j - 5; h < j; h++)
			{
				_X = _A[i - 1][h].x;
				_Y = _A[i - 1][h].y;
				GotoXY(_X, _Y);
				cout << x;
			}
			return 1;
		}
		else if ((_mode == 2) && checkcaro == 1)
		{
			for (int h = j - 5; h < j; h++)
			{
				_X = _A[i - 1][h].x;
				_Y = _A[i - 1][h].y;
				GotoXY(_X, _Y);
				cout << x;
			}
			return 1;
		}
	}
	return 0;
}
bool Duyetcheo(bool& checkcaro)
{
	char x;
	if (_TURN == 1)
	{
		TextColor(7);
		BackgroundColor(1);
		x = 'X';
	}
	else
	{
		TextColor(7);
		BackgroundColor(4);
		x = 'O';
	}
	// cheo phai

	int dem1 = 0, dem2 = 0;
	for (int h = 0; (((dem1 < 5 && dem2 < 5 && _mode == 1) || (_mode == 2 && ((dem1 < 5 & dem2 < 5) || checkcaro == 0))) && (h+4<BOARD_SIZE)); h++)
		for (int k = 0; (((dem1 < 5 && dem2 < 5 && _mode == 1) || (_mode == 2 && ((dem1 < 5 & dem2 < 5) || checkcaro == 0))) && (k + 4 < BOARD_SIZE)); k++)
		{
			int i = h;
			int j = k;
			do
			{
				dem(i, j, dem1, dem2);
				if ((dem1 == 5) || (dem2 == 5))
				{
					int dem1_tmp = dem1;
					int dem2_tmp = dem2;
					if (j + 1 < BOARD_SIZE && i + 1 < BOARD_SIZE)
					dem(i+1,j+1, dem1, dem2);
					if ((dem1 == 6) || (dem2 == 6)) checkcaro = 0;
					else
					{
						dem1 = dem1_tmp;
						dem2 = dem2_tmp;
						if (j - 5 >= 0 && i - 5 >= 0) dem(i - 5, j - 5, dem1, dem2);
						if ((dem1 == 6) || (dem2 == 6)) checkcaro = 0;
						else
						{
							if ((j + 1 < BOARD_SIZE && i + 1 < BOARD_SIZE && _A[i + 1][j + 1].c == 0)
								|| (j - 5 >= 0 && i - 5 >= 0 && _A[i - 5][j - 5].c == 0)
								|| (i - 4 == 0)
								|| (j - 4 == 0)
								|| (i== BOARD_SIZE-1)
								|| (j== BOARD_SIZE-1))
								checkcaro = 1;
							else checkcaro = 0;
						}
					}
					dem1 = dem1_tmp;
					dem2 = dem2_tmp;
				}

				if ((dem1 == 5) || (dem2 == 5))
				{
					if (_mode == 1)
					{
						int m = i - 4;
						int n = j - 4;
						do
						{
							_X = _A[m][n].x;
							_Y = _A[m][n].y;
							GotoXY(_X, _Y);
							cout << x;
							m++;
							n++;
						} while ((m <= i) && (n <= j));
						return 1;
					}
					else if ((_mode == 2) && checkcaro == 1)
					{
						int m = i - 4;
						int n = j - 4;
						do
						{
							_X = _A[m][n].x;
							_Y = _A[m][n].y;
							GotoXY(_X, _Y);
							cout << x;
							m++;
							n++;
						} while ((m <= i) && (n <= j));
						return 1;
					}
				}
				i++;
				j++;

			} while (i<BOARD_SIZE && j<BOARD_SIZE);

				dem1 = 0;
				dem2 = 0;
		}


	//cheo trai
	 dem1 = 0, dem2 = 0;
	for (int h = 0; (((dem1 < 5 && dem2 < 5 && _mode == 1) || (_mode == 2 && ((dem1 < 5 & dem2 < 5) || checkcaro == 0))) && (h + 4 < BOARD_SIZE)); h++)
		for (int k = BOARD_SIZE - 1; (((dem1 < 5 && dem2 < 5 && _mode == 1) || (_mode == 2 && ((dem1 < 5 & dem2 < 5) || checkcaro == 0))) && (k - 4 >= 0)); k--)
		{
			int i = h;
			int j = k;
			do
			{
				dem(i, j, dem1, dem2);
				if ((dem1 == 5) || (dem2 == 5))
				{
					int dem1_tmp = dem1;
					int dem2_tmp = dem2;
					if (j - 1 >=0 && i + 1 < BOARD_SIZE)
						dem(i + 1, j - 1, dem1, dem2);
					if ((dem1 == 6) || (dem2 == 6)) checkcaro = 0;
					else
					{
						dem1 = dem1_tmp;
						dem2 = dem2_tmp;
						if (j + 5 < BOARD_SIZE && i - 5 >= 0) dem(i - 5, j + 5, dem1, dem2);
						if ((dem1 == 6) || (dem2 == 6)) checkcaro = 0;
						else
						{
							if ((j - 1 >=0 && i + 1 < BOARD_SIZE && _A[i + 1][j - 1].c == 0)
								|| (j + 5 <BOARD_SIZE && i - 5 >= 0 && _A[i - 5][j + 5].c == 0)
								|| (i == BOARD_SIZE-1)
								|| (j == 0)
								|| (i-4==0)
								|| (j+4==BOARD_SIZE-1))
								checkcaro = 1;
							else checkcaro = 0;
						}
					}
					dem1 = dem1_tmp;
					dem2 = dem2_tmp;
				}

				if ((dem1 == 5) || (dem2 == 5))
				{
					if (_mode == 1)
					{
						int m = i - 4;
						int n = j + 4;
						do
						{
							_X = _A[m][n].x;
							_Y = _A[m][n].y;
							GotoXY(_X, _Y);
							cout << x;
							m++;
							n--;
						} while ((m <= i) && (n >= j));
						return 1;
					}
					else if ((_mode == 2) && checkcaro == 1)
					{
						int m = i - 4;
						int n = j + 4;
						do
						{
							_X = _A[m][n].x;
							_Y = _A[m][n].y;
							GotoXY(_X, _Y);
							cout << x;
							m++;
							n--;
						} while ((m <= i) && (n >= j));
						return 1;
					}
				}
				i++;
				j--;

			} while (i < BOARD_SIZE && j >=0);

			dem1 = 0;
			dem2 = 0;
		}
	return 0;
}

//KIỂM TRA THẮNG
bool CheckWin() 
{
	bool checkcaro;
	switch (_mode)
	{
	case 1:
		if (Duyetngang(checkcaro) == 1) return 1;
		else if (Duyetdoc(checkcaro) == 1) return 1;
		else if (Duyetcheo(checkcaro) == 1) return 1;
		return 0;
	case 2:
		checkcaro = 1;
		if ((Duyetdoc(checkcaro) == 1) && (checkcaro == 1)) return 1;
		else if ((Duyetngang(checkcaro) == 1) && (checkcaro == 1)) return 1;
		else if (Duyetcheo(checkcaro) == 1 && (checkcaro == 1)) return 1;
	}
}

//CẬP NHẬT BÀN CỜ
void UpdateBoard()
{
	BackgroundColor(64);
	for (int i = 0; i < BOARD_SIZE; i++)
	{
		for (int j = 0; j < BOARD_SIZE; j++)
		{
			_X = _A[i][j].x;
			_Y = _A[i][j].y;
			int tmp = _A[i][j].c;
			GotoXY(_X, _Y);
			if (tmp == -1)
			{
				TextColor(1);
				cout << "X";
			}
			else if (tmp==1)
			{
				TextColor(4);
				cout << "O";
			}
		}
	}
	_X = _A[0][0].x;
	_Y = _A[0][0].y;
	GotoXY(_X, _Y);
}


//CẬP NHẬT ĐIỂM
void updateScore()
{
	TextColor(0);
	BackgroundColor(1);
	GotoXY(76, 6);
	cout << " X ";

	TextColor(15);
	BackgroundColor(0);
	cout << "   " << _WinX << " - " << _WinO << "   ";

	TextColor(0);
	BackgroundColor(4);
	cout << " O ";
	GotoXY(_X, _Y);
}

//BẢNG THÔNG TIN
void demLuot()
{




	if (_mode == 1) {
		TextColor(6);
		BackgroundColor(0);
		GotoXY(72, 2);
		cout << "--- G  O  M  O  K  U ---" ;
	}
	else
	{
		TextColor(6);
		BackgroundColor(0);
		GotoXY(75, 2);
		cout << "--- C  A  R  O ---";
	}
	// VE TABLE
	TextColor(56);
	BackgroundColor(0);
	GotoXY(70, 3);
	cout << "+--------------------------+";
	GotoXY(70, 7);
	cout << "+--------------------------+";;


	TextColor(2);
	BackgroundColor(0);
	GotoXY(78, 4);
	cout << "R O U N D : " << _demRound;

	
	GotoXY(82, 5);
	TextColor(13);
	BackgroundColor(0);
	cout << "SCORE";

	updateScore();

	TextColor(56);
	BackgroundColor(0);
	GotoXY(67, 8);
	cout << ".------.------------.------------."<<endl;
	GotoXY(67, 9);
	cout << "|      |            |            |" << endl;
	GotoXY(67, 10);
	cout << ":------+------------+------------:" << endl;
	GotoXY(67, 11);
	cout << "|      |            |            |" << endl;
	GotoXY(67, 12);
	cout << "'------'------------'------------'" << endl;

	// DUA DU LIEU VAO TABLE
	GotoXY(82, 5);
	TextColor(13);
	GotoXY(70, 9);
	cout << "ID";
	GotoXY(69, 11);
	cout << "STEP";

	TextColor(15);
	BackgroundColor(0);
	GotoXY(80, 11);
	cout << _demX;
	GotoXY(93, 11);
	cout << _demO;


	TextColor(1);
	BackgroundColor(0);
	int tmp = _erX.size() / 2;
	GotoXY(81 - tmp, 9); //DUA CON TRO VAO GIUA BANG
	cout << _erX;


	TextColor(4);
	BackgroundColor(0);
	tmp = _erO.size() / 2;
	GotoXY(94 -tmp, 9);
	cout << _erO;



	GotoXY(_X, _Y); //tra ve vi tri con tro game

}

//THÔNG TIN CỦA TỪNG LƯỢT, ĐIẾM LƯỢT
void Luot()
{
	TextColor(13);
	BackgroundColor(0);
	GotoXY(81, 13);
	cout << "T U R N";

	if (_TURN == 1)
	{

		TextColor(1);
		BackgroundColor(0);

		GotoXY(61, 14);  cout << "       x x x x x x           x x x x x x   ";
		GotoXY(61, 15);  cout << "         x.........x       x.........x     ";
		GotoXY(61, 16);  cout << "           x.........x   x.........x      ";
		GotoXY(61, 17);  cout << "             x.........x.........x        ";
		GotoXY(61, 18);  cout << "               x...............x         ";
		GotoXY(61, 19);  cout << "                 x...........x            ";
		GotoXY(61, 20);  cout << "               x...............x          ";
		GotoXY(61, 21);  cout << "             x.........x.........x        ";
		GotoXY(61, 22);  cout << "           x.........x   x.........x      ";
		GotoXY(61, 23);  cout << "         x.........x       x.........x    ";
		GotoXY(61, 24);  cout << "       x x x x x x           x x x x x x  ";

	}
	else
	{

		TextColor(4);
		BackgroundColor(0);

		GotoXY(61, 14);  cout << "                 oooooooooooo           ";
		GotoXY(61, 15);  cout << "              oo..............oo        ";
		GotoXY(61, 16);  cout << "            oo..................oo      ";
		GotoXY(61, 17);  cout << "          oo.........oooo.........oo    ";
		GotoXY(61, 18);  cout << "          oo......oo      oo......oo    ";
		GotoXY(61, 19);  cout << "          oo.....oo        oo.....oo    ";
		GotoXY(61, 20);  cout << "          oo......oo      oo......oo    ";
		GotoXY(61, 21);  cout << "          oo.........oooo.........oo    ";
		GotoXY(61, 22);  cout << "            oo..................oo      ";
		GotoXY(61, 23);  cout << "              oo..............oo        ";
		GotoXY(61, 24);   cout << "                 oooooooooooo           ";
	}


	GotoXY(_X, _Y);
}



//KHỞI TẠO ROUND MỚI
void fNewRound()
{
	TextColor(7);
	BackgroundColor(0);
	system("cls");
	ResetData();
	DrawBoard(BOARD_SIZE);
	demLuot();
	
	//Thay đổi lượt đi đầu tiên là cùa người thua từ round thứ 2
	if (_demRound >1)
	{
		if (_ArRound[_demRound - 1] == -1) _TURN = 0;
		else if ((_ArRound[_demRound - 1] == 0) && (_WinX > _WinO)) _TURN = 0;
	}
	Luot();
	control();
}

//KIỂM TRA THẮNG THUA THEO ROUND
int TestRound()
{
	extern int _line;
	if (_Round!=0)
	{
		if (TestBoard() == -1)
		{
			_WinX++;
			_ArRound[_demRound] = -1;
			updateScore();
			if (_WinX >= (_Round / 2 + 1)) return -1;
			else if (_Round == _demRound) return 0;
			_demRound++;
			OutBoard();
			GotoXY(55, 26 + _line - 2);
			TextColor(9);
			cout << ">>";
			system("pause");
			fNewRound();;
		}
		else if (TestBoard() == 1)
		{

			_WinO++;
			_ArRound[_demRound] = 1;
			updateScore();
			if (_WinO >= (_Round / 2 + 1)) return 1;
			else if (_Round == _demRound) return 0;
			_demRound++;
			OutBoard();
			GotoXY(55, 26 + _line - 2);
			TextColor(12);
			cout << ">>";
			system("pause");
			fNewRound();
		}
		else if (FullBoard() == 1)
		{
			_ArRound[_demRound] = 0;
			_demRound++;
			OutBoard();
			GotoXY(55, 26 + _line - 1);
			TextColor(2);
			cout << ">>";
			system("pause");
			fNewRound();
		}
	}
	else
	{
		if (TestBoard() == -1)
		{
			_WinX++;
			_ArRound[_demRound] = -1;
			return -1;
		}
		else if (TestBoard() == 1)
		{
			_WinO++;
			_ArRound[_demRound] = 1;
			return 1;
		}
		else if (FullBoard() == 1)
		{
			_ArRound[_demRound] = 0;
			return 0;
		}
	}


	 return 2; //TIEP TUC DANH
}

void Restart()
{
	if (_Round == 0)
	{
		_demRound++;
		//đổi lượt

	}
	else
	{
		_WinX = 0;
		_WinO = 0;
		_demRound = 1;
	}

	TextColor(7);
	BackgroundColor(0);
	system("cls");
	ResetData();
	DrawBoard(BOARD_SIZE);
	demLuot();
	Luot();
}
//HÀM ĐIỀU KHIỂN
void control()
	{
		while (1)
		{

			bool validEnter = true;
			_COMMAND = toupper(_getch());
			if (_COMMAND == 27) //phim ESC
			{
				MainMenu();
			}
			else
			{
				if (_COMMAND == 'A')
				{
					PlaySound(L"BoardMove.wav", NULL, SND_FILENAME | SND_ASYNC);
					UseKeyA();
					MoveLeft();
					
				}
				else if (_COMMAND == 'W')
				{
					PlaySound(L"BoardMove.wav", NULL, SND_FILENAME | SND_ASYNC);
					UseKeyW();
					MoveUp();
					
				}
				else if (_COMMAND == 'S') 
				{
					PlaySound(L"BoardMove.wav", NULL, SND_FILENAME | SND_ASYNC);
					UseKeyS();
					MoveDown();
					
				}
				else if (_COMMAND == 'D')
				{
					PlaySound(L"BoardMove.wav", NULL, SND_FILENAME | SND_ASYNC);
					UseKeyD();
					MoveRight();
					
				}
				else if (_COMMAND == 13) //NGUOI DUNG NHAN ENTER DE DANH DAU
				{
					
					
					switch (CheckBoard(_X, _Y))
					{
					case -1:
						PlaySound(L"BoardCheck.wav", NULL, SND_FILENAME | SND_ASYNC);
						TextColor(1);
						cout << "X";
						UseKeyEnter();
						demLuot();
						break;
					case 1:
						PlaySound(L"BoardCheck.wav", NULL, SND_FILENAME| SND_ASYNC);
						TextColor(4);
						cout << "O";
						UseKeyEnter();
						demLuot();
						break;
					case 0: 
						validEnter = false; //danh vao o da danh roi
						PlaySound(L"FileError.wav", NULL, SND_FILENAME);
					}
					if (validEnter)
						switch (ProcessFinish(TestRound()))
						{
						case -1: case 1: case 0:
							if (AskContinue())
							{
								Restart();
							}
							else MainMenu();
						}

				}
				else if (_COMMAND == 'L')
				{
					clsOutBoard();
					SaveFile();
					GotoXY(55, 27);
					TextColor(8);
					BackgroundColor(0);
					cout << ">>Game has been saved!";
					GotoXY(55, 28);
					cout << ">>";
					system("pause");
					MainMenu();

				}
				else if (_COMMAND == 'T')
				{
					OpenFile(1);
					Loading();
					DrawBoard(BOARD_SIZE);
					demLuot();
					Luot();
					UpdateBoard();
					updateScore();
				}

			}

		}
	}

//===================================
//HIỆU ỨNG KHI NGƯỜI DÙNG ĐIỀU KHIỂN
void KeyA(bool isPress)
{
	
	if (isPress)
	{
		int color = (_TURN == true ? 1 : 4);
		TextColor(color);
		GotoXY(12, 30); cout << "+---+";
		GotoXY(12, 31); cout << "| A |";
		GotoXY(12, 32); cout << "+---+";
		Sleep(60);
	}
	// hieu ung nhan trong 1s neu nhan phim

	TextColor(56);
	BackgroundColor(0);
	GotoXY(12, 30); cout << "+---+";
	GotoXY(12, 31); cout << "| A |";
	GotoXY(12, 32); cout << "+---+";
}
void KeyD(bool isPress)
{
	if (isPress)
	{
		int color = (_TURN == true ? 1 : 4);
		TextColor(color);
		GotoXY(24, 30); cout << "+---+";
		GotoXY(24, 31); cout << "| D |";
		GotoXY(24, 32); cout << "+---+";
		Sleep(60);
	}

	TextColor(56);
	BackgroundColor(0);
	GotoXY(24, 30); cout << "+---+";
	GotoXY(24, 31); cout << "| D |";
	GotoXY(24, 32); cout << "+---+";
}
void KeyW(bool isPress)
{
	if (isPress)
	{
		int color = (_TURN == true ? 1 : 4);
		TextColor(color);
		GotoXY(18, 27); cout << "+---+";
		GotoXY(18, 28); cout << "| W |";
		GotoXY(18, 29); cout << "+---+";
		Sleep(60);
	}

	TextColor(56);
	BackgroundColor(0);
	GotoXY(18, 27); cout << "+---+";
	GotoXY(18, 28); cout << "| W |";
	GotoXY(18, 29); cout << "+---+";
}
void KeyS(bool isPress)
{
	if (isPress)
	{
		int color = (_TURN == true ? 1 : 4);
		TextColor(color);
		GotoXY(18, 30); cout << "+---+";
		GotoXY(18, 31); cout << "| S |";
		GotoXY(18, 32); cout << "+---+";
		Sleep(60);
	}

	TextColor(56);
	BackgroundColor(0);
	GotoXY(18, 30); cout << "+---+";
	GotoXY(18, 31); cout << "| S |";
	GotoXY(18, 32); cout << "+---+";
}
void KeyENTER(bool isPress)
{
	if (isPress)
	{
		int color = (_TURN == true ? 1 : 4);
		TextColor(color);
		GotoXY(30, 29); cout << "+-------+";
		GotoXY(30, 30); cout << "| Enter |";
		GotoXY(30, 31); cout << "+-------+";
		Sleep(60);
	}

	TextColor(56);
	BackgroundColor(0);
	GotoXY(30, 29); cout << "+-------+";
	GotoXY(30, 30); cout << "| Enter |";
	GotoXY(30, 31); cout << "+-------+";
}

void  UseKeyA()
{
	Cursor(0);
	KeyA(1);
	KeyS(0);
	KeyW(0);
	KeyD(0);
	KeyENTER(0);
	Cursor(1);
}
void  UseKeyS()
{
	Cursor(0);
	KeyA(0);
	KeyS(1);
	KeyW(0);
	KeyD(0);
	KeyENTER(0);
	Cursor(1);
}
void  UseKeyD()
{
	Cursor(0);
	KeyA(0);
	KeyS(0);
	KeyW(0);
	KeyD(1);
	KeyENTER(0);
	Cursor(1);
}
void  UseKeyW()
{
	Cursor(0);
	KeyA(0);
	KeyS(0);
	KeyW(1);
	KeyD(0);
	KeyENTER(0);
	Cursor(1);
}
void  UseKeyEnter()
{
	Cursor(0);
	KeyA(0);
	KeyS(0);
	KeyW(0);
	KeyD(0);
	KeyENTER(1);
	Cursor(1);
}
//===================================


//KẾT QUẢ THẮNG THUA TỪNG ROUND
int _line;
void OutBoard() 
{
	TextColor(2);
	_line = 1;
	int dem = 1;
	while (dem < _demRound)
	{
		if (_mode == 2)
		{
			GotoXY(55, 25 + _line);
			cout << ">>Game:"; cout << char(92); cout << "Caro"; cout << char(92);

			if (_ArRound[dem] == -1)
			{
				if (_Round == 0)
				{
					cout << "Round " << dem <<": " << _erX << " WIN! ";
				}
				else
				{
					cout << "Round(" << dem << "/" << _Round << ")>" << _erX << " WIN! ";
				}

			}
			else
			{
				if (_ArRound[dem] == 1)
				{
					if (_Round == 0)
					{
						cout << "Round " << dem << ": " << _erO << " WIN! ";
					}
					else
					{
						cout << "Round(" << dem << "/" << _Round << ")>" << _erO << " WIN! ";
					}

				}

				else
				{
					if (_Round == 0)
					{
						cout << "Round " << dem << ": DRAW! ";
					}
					else
					{
						cout << "Round(" << dem << "/" << _Round << ")>DRAW! ";
					}
				}
			}
			_line = _line + 1;
		}
		else if (_mode == 1)
		{
			GotoXY(55, 25 + _line);
			cout << ">>Game:"; cout << char(92); cout << "Gomoku"; cout << char(92);

			if (_ArRound[dem] == -1)
			{
				if (_Round == 0)
				{
					cout << "Round " << dem << ": " << _erX << " WIN! ";
				}
				else
				{
					cout << "Round(" << dem << "/" << _Round << ")>" << _erX << " WIN! ";
				}

			}
			else
			{
				if (_ArRound[dem] == 1)
				{
					if (_Round == 0)
					{
						cout << "Round " << dem << ": " << _erO << " WIN! ";
					}
					else
					{
						cout << "Round(" << dem << "/" << _Round << ")>" << _erO << " WIN! ";
					}

				}

				else
				{
					if (_Round == 0)
					{
						cout << "Round " << dem << ": DRAW! ";
					}
					else
					{
						cout << "Round(" << dem << "/" << _Round << ")>DRAW! ";
					}
				}
			}
			_line = _line + 1;
		}
		dem++;
		if (_line == 7)
		{
			dem = dem - 5;
			_line = 1;
			clsOutBoard();
		}
	}

	if (_mode == 2)
	{
		GotoXY(55, 25 + _line);
		cout << ">>Game:"; cout << char(92); cout << "Caro"; cout << char(92);
		if (_Round == 0)
		{
			cout << "Round " << _demRound << ": ...";
		}
		else
		{
			cout << "Round(" << _demRound << "/" << _Round << ")>...";
		}

		_line++;
	}
	else if (_mode == 1)
	{
		GotoXY(55, 25 + _line);
		cout << ">>Game:"; cout << char(92); cout << "Gomoku"; cout << char(92);
		if (_Round == 0)
		{
			cout << "Round " << _demRound << ": ...";
		}
		else
		{
			cout << "Round(" << _demRound << "/" << _Round << ")>...";
		}
		_line++;
	}

	//Opiton();
	//TextColor(2);
}

void clsOutBoard()
{
	//Opiton();
	int line = 1;
	TextColor(2);
	while (line <= 7)
	{
		GotoXY(55, 25 + line);
		BackgroundColor(0);
		cout << "                                                  ";
		line++;
	}



}
/*-----------------------------------------*/
