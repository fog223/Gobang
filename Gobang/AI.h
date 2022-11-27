#ifndef _AI_H_
#define _AI_H_

#include <vector>
#include <string>
#include "ChessBoard.h"

#define FIVE 50000 //连五
#define FLEX4 20000 //活四
#define BLOCK4 5000 //冲四
#define FLEX3 2000 //活三
#define BLOCK3 500 //眠三
#define FLEX2 200 //活二
#define BLOCK2 50 //眠二
#define FLEX1 20 //活一
#define BLOCK1 5 //眠一
#define NONE 0 //无

class AI
{
public:
	AI();//默认电脑执黑
	AI(Piece _who, Piece _opp);
	~AI();

	//计算空格得分
	void Compute_Score();

	//棋形检测
	void Detect_Shape();

	//获取最优落子位置
	void Get_Best(int &x, int &y);

	//对手落子
	void Opp_Move(int x, int y) { AIBoard->Board_Status[x][y] = opp; };

private:
	Piece who;
	Piece opp;//对手
	ChessBoard *AIBoard;
	int Score[SIZE][SIZE] = {0};
	std::vector<int> shape_score;
};

#endif // !_AI_H_
