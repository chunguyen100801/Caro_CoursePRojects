// Nhóm Hàm View

#include <Windows.h>
#include <String>
#include <iostream>
using namespace std;

void ResizeConsole(SHORT width, SHORT height);//Thết lập kích cỡ console
void FixConsoleWindow(); // Cố định màn hình console
void GotoXY(int x, int y); // Di chuyển dến tọa độ x,y trên màn hình console
void DrawBoard(int pSize); // Vẽ bàn cờ
void TextColor(short c); //Thay đổi màu của text
void BackgroundColor(WORD color); //Thay đổi màu nền của text
void Cursor(BOOL bVisible = TRUE, DWORD dwSize = 25); //ẩn hiện trỏ chuột
