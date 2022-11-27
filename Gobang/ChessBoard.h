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

//ö��(��������)
enum chessType { black, white };
enum Piece { EMPTY = 2, WHITE = 0, BLACK = 1, OUTSIDE = 3 };

class ChessBoard
{
public:
	ChessBoard();
	~ChessBoard();
	void InitBoardArray();  //��ʼ��������
	void DisplayBoard();	//��ʾ����
	void ChangeStatus(chessType _chessType, char _y, int _x, char _last_y, int _last_x);   //�ı�����״̬
	int GetStatus(int x, int y) { return Board[x][y]; };//��������������x,y����״̬��Ϣ
	bool judge_overlap(char _y, int _x);//�ж���������Ƿ񸲸��Ѿ����ڵ�����

	//��ȡ�����Ͽո�İ˸����������������ת�ַ���
	void Get_Shape(int x, int y);
	//���ּ��
	bool Detect_Prohibit(int x, int y);

public:
	int Board[SIZE][SIZE];//������ʾ
	int Board_Status[SIZE][SIZE];//����״̬(Piece)
	std::vector<std::string> chessshape;//�˸���������
};

#endif // !_ChessBoard_H_
