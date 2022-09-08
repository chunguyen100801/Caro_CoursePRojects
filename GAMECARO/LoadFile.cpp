#include "LoadFile.h"
#include "Common.h"
#include "Header.h"
#include "Menu.h";
#pragma comment (lib, "winmm.lib")
extern bool _TURN;
extern short _mode;
struct _POINT { int x, y, c; };
extern _POINT _A[BOARD_SIZE][BOARD_SIZE];
extern int _Round;
extern int _demX, _demO;
extern int _WinX, _WinO;
extern int _demRound;
extern string _erX, _erO;
extern short _ArRound[];

void SaveFile()
{
	string name;
	ofstream listfile;
	ofstream f;
	listfile.open("list.txt", ios::app);
	///  SUA LAI CHO NAY
	TextColor(15);
	BackgroundColor(0);
	GotoXY(55, 26);
	cout << "                                           ";
	TextColor(8);
	GotoXY(55, 26);
	cout << ">>INPUT FILE NAME: ";
	Cursor(1);
	cin >> name;
	Cursor(0);
	listfile << name << endl; //ghi ten file vao list.txt
	listfile.close();

	//bat dau ghi du lieu file
	f.open(name, ios::out);


	f << _mode<<endl;
	f << _Round<<endl;
	f << _demRound << endl;

	for (int i = 1; i <=_demRound ; i++)
	{
		f << _ArRound[i] << " ";
	}
	f << endl;


	f << _WinX<<endl;
	f << _WinO<<endl;
	f << _TURN<<endl;
	f << _demX<<endl;
	f << _demO << endl;


	for (int i = 0; i < BOARD_SIZE; i++)
	{
		for (int j = 0; j < BOARD_SIZE; j++)
		{
			f << _A[i][j].c << " ";
		}
		f << endl;
	}

	f << _erX << endl;
	f << _erO << endl;
	f.close();
}

void ListFile(int x)
{
	fstream listfile;
	listfile.open("list.txt", ios::in);

	if (x == 0)
	{
		TextColor(15);
		BackgroundColor(0);
		system("cls");
		GotoXY(50, 13);
		int dem = 0;
		cout << "----LIST FILE----" << endl;
		while ((!listfile.eof()) && (dem<11))
		{
			dem++;
			GotoXY(55, 13 + dem);
			char temp[255];
			listfile.getline(temp, 255);
			string line = temp;
			cout << line;
		}
	} 
	else if (x == 1)
	{
		BackgroundColor(0);
		//cls 
		for (int i = 14; i <= 24; i++)
		{
			GotoXY(61, i);  cout << "                                           ";
		}

		TextColor(13);
		BackgroundColor(0);
		GotoXY(80, 13);
		cout << "LIST FILE";
		int a = 0;
		while (!listfile.eof() && (a<10))
		{
			a++;
			GotoXY(80, 13+a);
			TextColor(8);
			BackgroundColor(0);
			char temp[255];
			listfile.getline(temp, 255);
			string line = temp;
			cout << line << endl;
		}

	}

	listfile.close();

}

void OpenFile(int x)
{
	string name;
	ifstream f;

	ListFile(x);
	int a,b;
	if (x == 1)
	{
		a = 55;
		b = 26;
	}
	else
	{
		a = 45;
		b = 24;
	}

	GotoXY(a, b);
	cout << "                                           ";
	clsOutBoard();

	TextColor(8);
	GotoXY(a, b);
	Cursor(1);
	cout << ">>INPUT FILE NAME: ";
	cin >> name;
	Cursor(0);
	TextColor(7);
	BackgroundColor(0);
	f.open(name, ios::in);
	if (f.fail())
	{
		GotoXY(a, b+1);
		TextColor(12);
		PlaySound(L"FileError.wav", NULL, SND_FILENAME);
		cout << ">>File not found!" << endl;
		GotoXY(a, b+2);
		cout << ">>";
		system("pause");

		//cls list file
		for (int i = 14; i <= 24; i++)
		{
			GotoXY(61, i);  cout << "                                           ";
		}
		

		if (x == 0) MainMenu();
		else
		{
			Luot();
			UpdateBoard();
			updateScore();
		}
	}
	else
	{
		ResetData();

		f >> _mode;
		f >> _Round;
		f >> _demRound;

		for (int i = 1; i <= _demRound; i++)
		{
			f >> _ArRound[i];
		}


		f >> _WinX;
		f >> _WinO;
		f >> _TURN;
		f >> _demX;
		f >> _demO;

		for (int i = 0; i < BOARD_SIZE; i++)
		{
			for (int j = 0; j < BOARD_SIZE; j++)
			{
				f >> _A[i][j].c;
			}
		}

		char temp1[255];
		f.getline(temp1, 255); //dua con tro xuong dong
		f.getline(temp1, 255);
		_erX = temp1;

		char temp2[255];
		f.getline(temp2, 255);
		_erO = temp2;

		f.close();
		}
	}

