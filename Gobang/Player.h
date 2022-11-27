#ifndef _PLAYER_H_
#define _PLAYER_H_

#include <stdio.h>
#include "ChessBoard.h"

class Player
{
public:
	char y, last_y;
	int x, last_x;
	chessType _chessType;
public:
	Player();
	Player(chessType chessType);
	~Player();
	void play();//Âä×Ó
};

#endif // !_PLAYER_H_



