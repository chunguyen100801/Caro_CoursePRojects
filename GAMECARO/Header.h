#ifndef _HEADER_H_
#define _HEADER_H_

#include <conio.h>
#include<stdio.h>
#include <iostream>
#include "Const.h"


using namespace std;

// KHỞI TẠO DỮ LIỆU BAN ĐẦU CHO BÀN CỜ
void ResetData();

// BẮT ĐẦU GAME
void StartGame();

//CẬP NHẬT LẠI BẢN ĐƯỢC LOAD TỪ FILE
void UpdateBoard();

//ĐẾM LƯỢT, I
void demLuot();

//BẮT ĐẦU LẠI GAME
void Restart();

//KIỂM TRA MA TRẬN ĐẦY
bool FullBoard(); 

//KIỂM TRA THẮNG THUA TRÊN BÀN CỜ
int TestBoard();
bool CheckWin();

//NHÓM HÀM DUYỆT THẮNG THUA THEO TỪNG CHẾ ĐỘ
bool Duyetdoc(bool& checkcaro);
bool Duyetngang(bool& checkcaro);
bool Duyetcheo(bool& checkcaro);
void dem(int i, int j, int& dem1, int& dem2);

//NHÓM HÀM ĐIỀU KHIỂN CON TRỎ TRÊN BÀN CỜ
void MoveRight();
void MoveLeft();
void MoveDown();
void MoveUp();
int CheckBoard(int pX, int pY); //danh dau vao ma tran ban co khi nguoi dung nhan enter

//XỬ LÍ THẮNG THUA
int ProcessFinish(int pWhoWin);
bool AskContinue();

//HÀM ĐIỀU KHIỂN GAME
void control();

//HÀM KIỂM TRA THẮNG THUA THEO ROUND
int TestRound();
void fNewRound();

//HÀM HIỂN THỊ THÔNG TIN, THAO TÁC CỦA NGƯỜI DÙNG
void Luot();
void demLuot();
void updateScore();

void UseKeyA();
void  UseKeyS();
void  UseKeyD();
void  UseKeyW();
void  UseKeyEnter();

void KeyD(bool isPress);
void KeyA(bool isPress);
void KeyS(bool isPress);
void KeyW(bool isPress);
void KeyENTER(bool isPress);


//HÀM IN KẾT QUẢ CÁC TRẬN
void OutBoard();
void clsOutBoard();

#endif





