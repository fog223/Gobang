#include "Referee.h"

Referee::Referee()
{
	who = WHITE;
	opp = BLACK;
	Set_gametype();
	wind = new AI(who, opp);
	player1 = new Player(black);
	player2 = new Player(white);
}

Referee::~Referee()
{
}

void Referee::Set_gametype()
{
	std::cout << "��ѡ��ģʽ��1-���˶�սģʽ��2-�˻���սģʽ��";
	scanf("%d", &mode);  //��ö�սģʽ
	getchar();

	if (mode == 1)//����ģʽ
	{
		_game_type = Man2Man;
	}

	if (mode == 2)//�˻�ģʽ
	{
		_game_type = Man2AI;

		int b_w = -1;
		std::cout << "��ѡ��ִ��orִ�ף����ȣ��׺󣩣�1-ִ�ڣ�2-ִ�ף�";
		scanf("%d", &b_w);  //��ö�սģʽ
		getchar();

		if (b_w == 1)//���ִ��(����)������ִ��(����)
		{
			who = WHITE;
			opp = BLACK;
		}
		else if(b_w == 2)//���ִ��(����)������ִ��(����)
		{
			who = BLACK;
			opp = WHITE;
		}
		else
			std::cout << "ѡ�����!!!";
	}
}

void Referee::start()
{
	_chessboard.InitBoardArray();//���̳�ʼ��
	_chessboard.DisplayBoard();//��ʾ����
	//���˶�ս
	if (_game_type == Man2Man)
	{
		while (1)
		{
			//
			std::cout << "�����һ(ִ��)������������(��H8):";
			player1->play();
			while (_chessboard.judge_overlap(player1->y, player1->x))
			{
				std::cout << "����λ���Ѿ��������ӣ������һ(ִ��)����������������(��H8):";
				player1->play();
			}
			if (_chessboard.Detect_Prohibit(SIZE - player1->x, player1->y - 'A'))//����
			{
				std::cout << "���һ(ִ��)���֣�����" << std::endl;
				std::cout << "��Ҷ�(ִ��)Ӯ����Ϸ������" << std::endl;
				std::cout << "��Ϸ����������" << std::endl;
				break;
			}
			_chessboard.ChangeStatus(player1->_chessType, player1->y, player1->x, player1->last_y, player1->last_x);
			_chessboard.DisplayBoard();
			if (victory())
			{
				std::cout << "��ϲ���һ(ִ��)Ӯ����Ϸ������" << std::endl;
				std::cout << "��Ϸ����������" << std::endl;
				break;
			}

			std::cout << "����Ҷ�(ִ��)������������(��H8):";
			player2->play();
			while (_chessboard.judge_overlap(player2->y, player2->x))
			{
				std::cout << "����λ���Ѿ��������ӣ�����Ҷ�(ִ��)����������������(��H8):";
				player2->play();
			}
			_chessboard.ChangeStatus(player2->_chessType, player2->y, player2->x, player2->last_y, player2->last_x);
			_chessboard.DisplayBoard();
			if (victory())
			{
				std::cout << "��ϲ��Ҷ�(ִ��)Ӯ����Ϸ������" << std::endl;
				std::cout << "��Ϸ����������" << std::endl;
				break;
			}
		}
	}
	else
	{
		int AI_X = -1, AI_Y = -1;
		int Last_AI_X = -1, Last_AI_Y = -1;

		if (who == BLACK)//����ִ��
		{
			while (1)
			{
				//
				Last_AI_X = AI_X; Last_AI_Y = AI_Y;
				wind->Get_Best(AI_X, AI_Y);
				_chessboard.ChangeStatus(black, 'A' + AI_X, SIZE - AI_Y, 'A' + Last_AI_X, SIZE - Last_AI_Y);
				_chessboard.DisplayBoard();
				if (victory())
				{
					std::cout << "����(ִ��)Ӯ����Ϸ������" << std::endl;
					std::cout << "��Ϸ����������" << std::endl;
					break;
				}
				std::cout << "����(ִ��)�������꣺" << AI_Y << " " << AI_X << std::endl;

				std::cout << "�����(ִ��)������������(��H8):";
				player2->play();
				while (_chessboard.judge_overlap(player2->y, player2->x))
				{
					std::cout << "����λ���Ѿ��������ӣ������(ִ��)����������������(��H8):";
					player2->play();
				}
				wind->Opp_Move(player2->y - 'A', SIZE - player2->x);//������������λ��
				_chessboard.ChangeStatus(player2->_chessType, player2->y, player2->x, player2->last_y, player2->last_x);
				_chessboard.DisplayBoard();
				if (victory())
				{
					std::cout << "��ϲ���(ִ��)Ӯ����Ϸ������" << std::endl;
					std::cout << "��Ϸ����������" << std::endl;
					break;
				}				
			}
		}

		else//����ִ��
		{
			while (1)
			{
				//
				std::cout << "�����(ִ��)������������(��H8):";
				player1->play();
				while (_chessboard.judge_overlap(player2->y, player2->x))
				{
					std::cout << "����λ���Ѿ��������ӣ������(ִ��)����������������(��H8):";
					player2->play();
				}
				if (_chessboard.Detect_Prohibit(SIZE - player1->x, player1->y - 'A'))//����
				{
					std::cout << "���(ִ��)���֣�����" << std::endl;
					std::cout << "����(ִ��)Ӯ����Ϸ������" << std::endl;
					std::cout << "��Ϸ����������" << std::endl;
					break;
				}
				wind->Opp_Move(player1->y - 'A', SIZE - player1->x);//������������λ��
				_chessboard.ChangeStatus(player1->_chessType, player1->y, player1->x, player1->last_y, player1->last_x);
				_chessboard.DisplayBoard();
				if (victory())
				{
					std::cout << "��ϲ���(ִ��)Ӯ����Ϸ������" << std::endl;
					std::cout << "��Ϸ����������" << std::endl;
					break;
				}

				Last_AI_X = AI_X; Last_AI_Y = AI_Y;
				wind->Get_Best(AI_X, AI_Y);
				_chessboard.ChangeStatus(white, 'A' + AI_X, SIZE - AI_Y, 'A' + Last_AI_X, SIZE - Last_AI_Y);
				_chessboard.DisplayBoard();
				if (victory())
				{
					std::cout << "����(ִ��)Ӯ����Ϸ������" << std::endl;
					std::cout << "��Ϸ����������" << std::endl;
					break;
				}
				std::cout << "����(ִ��)�������꣺" << AI_Y << " " << AI_X << std::endl;
			}
		}
		
	}
}

bool Referee::victory()
{
	for (int i = 2; i <= SIZE - 3; i++)
	{
		for (int j = 2; j <= SIZE - 3; j++)
		{
			if (row(i, j) || col(i, j) || oblique(i, j))
				return true;
		}
	}
	return false;
}

bool Referee::row(int x, int y)
{
	int score = 0;
	for (int j = -2; j <= 2; j++)
	{
		int status = _chessboard.GetStatus(x, y + j);
		if (status == BLACKtem || status == BLACKChess)
			score++;
		else if (status == WHITEtem || status == WHITEChess)
			score--;
	}

	if (score == 5 || score == -5)
		return true;
	else
		return false;
}

bool Referee::col(int x, int y)
{
	int score = 0;
	for (int i = -2; i <= 2; i++)
	{
		int status = _chessboard.GetStatus(x + i, y);
		if (status == BLACKtem || status == BLACKChess)
			score++;
		else if (status == WHITEtem || status == WHITEChess)
			score--;
	}

	if (score == 5 || score == -5)
		return true;
	else
		return false;
}

bool Referee::oblique(int x, int y)
{
	int score = 0;

	//���ϵ�����
	for (int i = -2; i <= 2; i++)
	{
		int status = _chessboard.GetStatus(x + i, y + i);
		if (status == BLACKtem || status == BLACKChess)
			score++;
		else if (status == WHITEtem || status == WHITEChess)
			score--;
	}

	if (score == 5 || score == -5)
		return true;

	score = 0;
	if (x == 7 && y == 7)
		score = 0;
	//���µ�����
	for (int i = -2; i <= 2; i++)
	{
		int status = _chessboard.GetStatus(x + i, y - i);
		if (status == BLACKtem || status == BLACKChess)
			score++;
		else if (status == WHITEtem || status == WHITEChess)
			score--;
	}

	if (score == 5 || score == -5)
		return true;
	else
		return false;
}
