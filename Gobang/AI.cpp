#include "AI.h"
#include <algorithm>

AI::AI()
{
	who = BLACK;
	opp = WHITE;
	AIBoard = new ChessBoard;
}

AI::AI(Piece _who, Piece _opp)
{
	who = _who;
	opp = _opp;
	AIBoard = new ChessBoard;
}

AI::~AI()
{
}

void AI::Compute_Score()
{
	for (int i = 0; i <= SIZE - 1; i++)
	{
		for (int j = 0; j <= SIZE - 1; j++)
		{
			if (AIBoard->Board_Status[i][j] == EMPTY)
			{
				if (who == BLACK && AIBoard->Detect_Prohibit(i, j))//ִ���ҽ���
					Score[i][j] = 0;
				else
				{
					AIBoard->Get_Shape(i, j);
					Detect_Shape();
					std::sort(shape_score.rbegin(), shape_score.rend());
					Score[i][j] = shape_score[0] + shape_score[1];
				}				
			}
			else
				Score[i][j] = 0;
		}
	}
}

void AI::Detect_Shape()
{
	/*��ɫ*/
	std::vector<std::string> chesss_shapes1;
	std::string chesss_shape1 = AIBoard->chessshape[0] + "1" + AIBoard->chessshape[1];//һ��
	std::string chesss_shape2 = AIBoard->chessshape[2] + "1" + AIBoard->chessshape[3];//һ��
	std::string chesss_shape3 = AIBoard->chessshape[4] + "1" + AIBoard->chessshape[5];//���Խ�
	std::string chesss_shape4 = AIBoard->chessshape[6] + "1" + AIBoard->chessshape[7];//���Խ�
	chesss_shapes1.push_back(chesss_shape1);
	chesss_shapes1.push_back(chesss_shape2);
	chesss_shapes1.push_back(chesss_shape3);
	chesss_shapes1.push_back(chesss_shape4);
	//ȫ---(_bΪ��ɫ)
	std::string shape5_b = "11111";//����
	std::string shape41_b = "211112";//����
	std::string shape421_b = "011112";//����
	std::string shape422_b = "211110";//����
	std::string shape423_b = "11121";//����
	std::string shape424_b = "11211";//����
	std::string shape425_b = "12111";//����
	std::string shape311_b = "211122";//����
	std::string shape312_b = "221112";//����
	std::string shape313_b = "211212";//����
	std::string shape314_b = "212112";//����

	//��ȫ(������)
	std::string shape321_b = "01112";//����
	std::string shape322_b = "21110";//����
	std::string shape211_b = "2112";//���
	std::string shape221_b = "0112";//�߶�
	std::string shape222_b = "2110";//�߶�
	std::string shape111_b = "212";//��һ
	std::string shape121_b = "012";//��һ
	std::string shape122_b = "210";//��һ

	
	/*��ɫ*/
	std::vector<std::string> chesss_shapes2;
	std::string chesss_shape5 = AIBoard->chessshape[0] + "0" + AIBoard->chessshape[1];//һ��
	std::string chesss_shape6 = AIBoard->chessshape[2] + "0" + AIBoard->chessshape[3];//һ��
	std::string chesss_shape7 = AIBoard->chessshape[4] + "0" + AIBoard->chessshape[5];//���Խ�
	std::string chesss_shape8 = AIBoard->chessshape[6] + "0" + AIBoard->chessshape[7];//���Խ�
	chesss_shapes2.push_back(chesss_shape5);
	chesss_shapes2.push_back(chesss_shape6);
	chesss_shapes2.push_back(chesss_shape7);
	chesss_shapes2.push_back(chesss_shape8);
	//ȫ---(_wΪ��ɫ)
	std::string shape5_w = "00000";//����
	std::string shape41_w = "200002";//����
	std::string shape421_w = "100002";//����
	std::string shape422_w = "200001";//����
	std::string shape423_w = "00020";//����
	std::string shape424_w = "00200";//����
	std::string shape425_w = "02000";//����
	std::string shape311_w = "200022";//����
	std::string shape312_w = "220002";//����
	std::string shape313_w = "200202";//����
	std::string shape314_w = "202002";//����

	//��ȫ(������)
	std::string shape321_w = "10002";//����
	std::string shape322_w = "20001";//����
	std::string shape211_w = "2002";//���
	std::string shape221_w = "1002";//�߶�
	std::string shape222_w = "2001";//�߶�
	std::string shape111_w = "202";//��һ
	std::string shape121_w = "102";//��һ
	std::string shape122_w = "201";//��һ

	shape_score.clear();
	if (who == BLACK)//����ִ��
	{
		for (int i = 0; i < chesss_shapes1.size(); i++)
		{
			if (chesss_shapes1[i].find(shape5_b) != std::string::npos)
				shape_score.push_back(FIVE);
			else if (chesss_shapes1[i].find(shape41_b) != std::string::npos)
				shape_score.push_back(FLEX4);
			else if (chesss_shapes1[i].find(shape421_b) != std::string::npos)
				shape_score.push_back(BLOCK4);
			else if (chesss_shapes1[i].find(shape422_b) != std::string::npos)
				shape_score.push_back(BLOCK4);
			else if (chesss_shapes1[i].find(shape423_b) != std::string::npos)
				shape_score.push_back(BLOCK4);
			else if (chesss_shapes1[i].find(shape424_b) != std::string::npos)
				shape_score.push_back(BLOCK4);
			else if (chesss_shapes1[i].find(shape425_b) != std::string::npos)
				shape_score.push_back(BLOCK4);
			else if (chesss_shapes1[i].find(shape311_b) != std::string::npos)
				shape_score.push_back(FLEX3);
			else if (chesss_shapes1[i].find(shape312_b) != std::string::npos)
				shape_score.push_back(FLEX3);
			else if (chesss_shapes1[i].find(shape313_b) != std::string::npos)
				shape_score.push_back(FLEX3);
			else if (chesss_shapes1[i].find(shape314_b) != std::string::npos)
				shape_score.push_back(FLEX3);
			else if (chesss_shapes1[i].find(shape321_b) != std::string::npos)
				shape_score.push_back(BLOCK3);
			else if (chesss_shapes1[i].find(shape322_b) != std::string::npos)
				shape_score.push_back(BLOCK3);
			else if (chesss_shapes1[i].find(shape211_b) != std::string::npos)
				shape_score.push_back(FLEX1);
			else if (chesss_shapes1[i].find(shape221_b) != std::string::npos)
				shape_score.push_back(BLOCK2);
			else if (chesss_shapes1[i].find(shape222_b) != std::string::npos)
				shape_score.push_back(BLOCK2);
			else if (chesss_shapes1[i].find(shape111_b) != std::string::npos)
				shape_score.push_back(FLEX1);
			else if (chesss_shapes1[i].find(shape121_b) != std::string::npos)
				shape_score.push_back(BLOCK1);
			else if (chesss_shapes1[i].find(shape122_b) != std::string::npos)
				shape_score.push_back(BLOCK1);
			else
				shape_score.push_back(NONE);
		}

		for (int i = 0; i < chesss_shapes2.size(); i++)
		{
			if (chesss_shapes2[i].find(shape5_w) != std::string::npos)
				shape_score.push_back(FIVE - 1);
			else if (chesss_shapes2[i].find(shape41_w) != std::string::npos)
				shape_score.push_back(FLEX4 - 1);
			else if (chesss_shapes2[i].find(shape421_w) != std::string::npos)
				shape_score.push_back(BLOCK4 - 1);
			else if (chesss_shapes2[i].find(shape422_w) != std::string::npos)
				shape_score.push_back(BLOCK4 - 1);
			else if (chesss_shapes2[i].find(shape423_w) != std::string::npos)
				shape_score.push_back(BLOCK4 - 1);
			else if (chesss_shapes2[i].find(shape424_w) != std::string::npos)
				shape_score.push_back(BLOCK4 - 1);
			else if (chesss_shapes2[i].find(shape425_w) != std::string::npos)
				shape_score.push_back(BLOCK4 - 1);
			else if (chesss_shapes2[i].find(shape311_w) != std::string::npos)
				shape_score.push_back(FLEX3 - 1);
			else if (chesss_shapes2[i].find(shape312_w) != std::string::npos)
				shape_score.push_back(FLEX3 - 1);
			else if (chesss_shapes2[i].find(shape313_w) != std::string::npos)
				shape_score.push_back(FLEX3 - 1);
			else if (chesss_shapes2[i].find(shape314_w) != std::string::npos)
				shape_score.push_back(FLEX3 - 1);
			else if (chesss_shapes2[i].find(shape321_w) != std::string::npos)
				shape_score.push_back(BLOCK3 - 1);
			else if (chesss_shapes2[i].find(shape322_w) != std::string::npos)
				shape_score.push_back(BLOCK3 - 1);
			else if (chesss_shapes2[i].find(shape211_w) != std::string::npos)
				shape_score.push_back(FLEX1 - 1);
			else if (chesss_shapes2[i].find(shape221_w) != std::string::npos)
				shape_score.push_back(BLOCK2 - 1);
			else if (chesss_shapes2[i].find(shape222_w) != std::string::npos)
				shape_score.push_back(BLOCK2 - 1);
			else if (chesss_shapes2[i].find(shape111_w) != std::string::npos)
				shape_score.push_back(FLEX1 - 1);
			else if (chesss_shapes2[i].find(shape121_w) != std::string::npos)
				shape_score.push_back(BLOCK1 - 1);
			else if (chesss_shapes2[i].find(shape122_w) != std::string::npos)
				shape_score.push_back(BLOCK1 - 1);
			else
				shape_score.push_back(NONE - 1);
		}

	}
	else//����ִ��
	{
		for (int i = 0; i < chesss_shapes2.size(); i++)
		{
			if (chesss_shapes2[i].find(shape5_w) != std::string::npos)
				shape_score.push_back(FIVE);
			else if (chesss_shapes2[i].find(shape41_w) != std::string::npos)
				shape_score.push_back(FLEX4);
			else if (chesss_shapes2[i].find(shape421_w) != std::string::npos)
				shape_score.push_back(BLOCK4);
			else if (chesss_shapes2[i].find(shape422_w) != std::string::npos)
				shape_score.push_back(BLOCK4);
			else if (chesss_shapes2[i].find(shape423_w) != std::string::npos)
				shape_score.push_back(BLOCK4);
			else if (chesss_shapes2[i].find(shape424_w) != std::string::npos)
				shape_score.push_back(BLOCK4);
			else if (chesss_shapes2[i].find(shape425_w) != std::string::npos)
				shape_score.push_back(BLOCK4);
			else if (chesss_shapes2[i].find(shape311_w) != std::string::npos)
				shape_score.push_back(FLEX3);
			else if (chesss_shapes2[i].find(shape312_w) != std::string::npos)
				shape_score.push_back(FLEX3);
			else if (chesss_shapes2[i].find(shape313_w) != std::string::npos)
				shape_score.push_back(FLEX3);
			else if (chesss_shapes2[i].find(shape314_w) != std::string::npos)
				shape_score.push_back(FLEX3);
			else if (chesss_shapes2[i].find(shape321_w) != std::string::npos)
				shape_score.push_back(BLOCK3);
			else if (chesss_shapes2[i].find(shape322_w) != std::string::npos)
				shape_score.push_back(BLOCK3);
			else if (chesss_shapes2[i].find(shape211_w) != std::string::npos)
				shape_score.push_back(FLEX1);
			else if (chesss_shapes2[i].find(shape221_w) != std::string::npos)
				shape_score.push_back(BLOCK2);
			else if (chesss_shapes2[i].find(shape222_w) != std::string::npos)
				shape_score.push_back(BLOCK2);
			else if (chesss_shapes2[i].find(shape111_w) != std::string::npos)
				shape_score.push_back(FLEX1);
			else if (chesss_shapes2[i].find(shape121_w) != std::string::npos)
				shape_score.push_back(BLOCK1);
			else if (chesss_shapes2[i].find(shape122_w) != std::string::npos)
				shape_score.push_back(BLOCK1);
			else
				shape_score.push_back(NONE);
		}

		for (int i = 0; i < chesss_shapes1.size(); i++)
		{
			if (chesss_shapes1[i].find(shape5_b) != std::string::npos)
				shape_score.push_back(FIVE - 1);
			else if (chesss_shapes1[i].find(shape41_b) != std::string::npos)
				shape_score.push_back(FLEX4 - 1);
			else if (chesss_shapes1[i].find(shape421_b) != std::string::npos)
				shape_score.push_back(BLOCK4 - 1);
			else if (chesss_shapes1[i].find(shape422_b) != std::string::npos)
				shape_score.push_back(BLOCK4 - 1);
			else if (chesss_shapes1[i].find(shape423_b) != std::string::npos)
				shape_score.push_back(BLOCK4 - 1);
			else if (chesss_shapes1[i].find(shape424_b) != std::string::npos)
				shape_score.push_back(BLOCK4 - 1);
			else if (chesss_shapes1[i].find(shape425_b) != std::string::npos)
				shape_score.push_back(BLOCK4 - 1);
			else if (chesss_shapes1[i].find(shape311_b) != std::string::npos)
				shape_score.push_back(FLEX3 - 1);
			else if (chesss_shapes1[i].find(shape312_b) != std::string::npos)
				shape_score.push_back(FLEX3 - 1);
			else if (chesss_shapes1[i].find(shape313_b) != std::string::npos)
				shape_score.push_back(FLEX3 - 1);
			else if (chesss_shapes1[i].find(shape314_b) != std::string::npos)
				shape_score.push_back(FLEX3 - 1);
			else if (chesss_shapes1[i].find(shape321_b) != std::string::npos)
				shape_score.push_back(BLOCK3 - 1);
			else if (chesss_shapes1[i].find(shape322_b) != std::string::npos)
				shape_score.push_back(BLOCK3 - 1);
			else if (chesss_shapes1[i].find(shape211_b) != std::string::npos)
				shape_score.push_back(FLEX1 - 1);
			else if (chesss_shapes1[i].find(shape221_b) != std::string::npos)
				shape_score.push_back(BLOCK2 - 1);
			else if (chesss_shapes1[i].find(shape222_b) != std::string::npos)
				shape_score.push_back(BLOCK2 - 1);
			else if (chesss_shapes1[i].find(shape111_b) != std::string::npos)
				shape_score.push_back(FLEX1 - 1);
			else if (chesss_shapes1[i].find(shape121_b) != std::string::npos)
				shape_score.push_back(BLOCK1 - 1);
			else if (chesss_shapes1[i].find(shape122_b) != std::string::npos)
				shape_score.push_back(BLOCK1 - 1);
			else
				shape_score.push_back(NONE - 1);
		}
	}
}

void AI::Get_Best(int & x, int & y)
{
	Compute_Score();
	//ȡ��߷�Ϊ����λ�ã�
	//���÷���ͬ����ȡ�������������һ����Ϊ��������
	int top_score = 0;
	for (int i = 0; i <= SIZE - 1; i++)
	{
		for (int j = 0; j <= SIZE - 1; j++)
		{
			if (Score[i][j] > top_score)
			{
				top_score = Score[i][j];
				x = i;
				y = j;
			}
			else if (Score[i][j] == top_score)
			{
				int dis1 = fabs(i - int((SIZE - 1) / 2)) + fabs(j - int((SIZE - 1) / 2));
				int dis2 = fabs(x - int((SIZE - 1) / 2)) + fabs(y - int((SIZE - 1) / 2));
				if (dis1 < dis2)
				{
					x = i;
					y = j;
				}
			}
		}
	}
	AIBoard->Board_Status[x][y] = who;
}
