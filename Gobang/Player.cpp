#include "Player.h"

Player::Player()
{
	y = last_y = '-1';
	x = last_x = -1;
}

Player::Player(chessType chessType)
{
	y = last_y = '-1';
	x = last_x = -1;
	_chessType = chessType;
}

Player::~Player()
{
}

void Player::play()
{
	last_y = y;
	last_x = x;

	//��������ϵͳ����
	int a, b;
	std::cin >> a >> b;
	y = 'A' + b;
	x = SIZE - a;

	//scanf("%c%d", &y, &x);  //�����Ļ���������
	//getchar();
}
