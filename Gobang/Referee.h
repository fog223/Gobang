#ifndef _Referee_H_
#define _Referee_H_

#include <iostream>
#include "ChessBoard.h"
#include "Player.h"
#include "AI.h"

//ö��(��Ϸ����)
enum GAME_TYPE { Man2Man, Man2AI };
//����
class Referee
{
public:
	Referee();
	~Referee();
	void Set_gametype();
	void start();//������ʼ

private:
	Piece who, opp;//��սģʽ��1-ִ�ڣ�2-ִ�ף�
	int mode;//��սģʽ��1-���ˣ�2-�˻���
	GAME_TYPE _game_type;
	ChessBoard _chessboard;
	Player *player1;
	Player *player2;
	AI *wind;

private:
	bool victory();//�ж��Ƿ���һ��ʤ��
	bool row(int x, int y);//�жϺ����Ƿ������
	bool col(int x, int y);//�ж������Ƿ������
	bool oblique(int x, int y);//�ж�б���Ƿ������
};

#endif // !_Referee_H_
