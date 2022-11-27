#ifndef _Referee_H_
#define _Referee_H_

#include <iostream>
#include "ChessBoard.h"
#include "Player.h"
#include "AI.h"

//枚举(游戏类型)
enum GAME_TYPE { Man2Man, Man2AI };
//裁判
class Referee
{
public:
	Referee();
	~Referee();
	void Set_gametype();
	void start();//比赛开始

private:
	Piece who, opp;//对战模式（1-执黑，2-执白）
	int mode;//对战模式（1-人人，2-人机）
	GAME_TYPE _game_type;
	ChessBoard _chessboard;
	Player *player1;
	Player *player2;
	AI *wind;

private:
	bool victory();//判断是否有一方胜利
	bool row(int x, int y);//判断横线是否成五子
	bool col(int x, int y);//判断竖线是否成五子
	bool oblique(int x, int y);//判断斜线是否成五子
};

#endif // !_Referee_H_
