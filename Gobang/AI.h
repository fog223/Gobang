#ifndef _AI_H_
#define _AI_H_

#include <vector>
#include <string>
#include "ChessBoard.h"

#define FIVE 50000 //����
#define FLEX4 20000 //����
#define BLOCK4 5000 //����
#define FLEX3 2000 //����
#define BLOCK3 500 //����
#define FLEX2 200 //���
#define BLOCK2 50 //�߶�
#define FLEX1 20 //��һ
#define BLOCK1 5 //��һ
#define NONE 0 //��

class AI
{
public:
	AI();//Ĭ�ϵ���ִ��
	AI(Piece _who, Piece _opp);
	~AI();

	//����ո�÷�
	void Compute_Score();

	//���μ��
	void Detect_Shape();

	//��ȡ��������λ��
	void Get_Best(int &x, int &y);

	//��������
	void Opp_Move(int x, int y) { AIBoard->Board_Status[x][y] = opp; };

private:
	Piece who;
	Piece opp;//����
	ChessBoard *AIBoard;
	int Score[SIZE][SIZE] = {0};
	std::vector<int> shape_score;
};

#endif // !_AI_H_
