#ifndef _GV
#define _GV

//Biến toàn cục
struct _POINT { int x, y, c; }; // x dòng, y cột, c đánh dấu ( 1,-1,0)
_POINT _A[BOARD_SIZE][BOARD_SIZE] = {}; // ma trận bàn cờ
bool _TURN = 1; // true là lượt người 1, false là lượt người -1
char  _COMMAND = 1; // biến nhận giá trị người dùng nhập
int _X = 1; // tọa độ hiện hành trên bàn cờ
int _Y = 1;
short _mode; //chế độ chơi (1-Gomoku, 2-Caro)
int _demX = 0, _demO = 0; //đếm lượt của X,O
int _WinX=0, _WinO=0; //Đếm số ván thắng của X,O
int _Round; //Lưu số round sẽ chơi (không chơi theo round thì _Round=0)
int _demRound=1; //lưu số round đã chơi
string _erX ="", _erO =""; //lưu tên người dùng
short _ArRound[50] = {}; // lưu kết quả từng round (-1 là X thắng, 1 là O thắng, 0 là hòa)



#endif // !_GV

