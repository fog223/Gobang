#ifndef _ChessBoard_H_
#define _ChessBoard_H_

#include <windows.h>
#include <stdio.h>
#include <assert.h>
#include <iostream>
#include <vector>
#include <string>

#define SIZE 15
#define BLACKtem 10
#define WHITEtem 11
#define BLACKChess 20
#define WHITEChess 21

//枚举(棋子类型)
enum chessType { black, white };
enum Piece { EMPTY = 2, WHITE = 0, BLACK = 1, OUTSIDE = 3 };

class ChessBoard
{
public:
	ChessBoard();
	~ChessBoard();
	void InitBoardArray();  //初始化空棋盘
	void DisplayBoard();	//显示棋盘
	void ChangeStatus(chessType _chessType, char _y, int _x, char _last_y, int _last_x);   //改变盘面状态
	int GetStatus(int x, int y) { return Board[x][y]; };//供外界访问棋盘上x,y处的状态信息
	bool judge_overlap(char _y, int _x);//判断玩家落子是否覆盖已经存在的棋子

	//获取棋盘上空格的八个方向棋子情况，并转字符串
	void Get_Shape(int x, int y);
	//禁手检测
	bool Detect_Prohibit(int x, int y);

public:
	int Board[SIZE][SIZE];//棋盘显示
	int Board_Status[SIZE][SIZE];//棋盘状态(Piece)
	std::vector<std::string> chessshape;//八个方向棋形
};

#endif // !_ChessBoard_H_
