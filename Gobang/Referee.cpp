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
	std::cout << "请选择模式，1-人人对战模式；2-人机对战模式：";
	scanf("%d", &mode);  //获得对战模式
	getchar();

	if (mode == 1)//人人模式
	{
		_game_type = Man2Man;
	}

	if (mode == 2)//人机模式
	{
		_game_type = Man2AI;

		int b_w = -1;
		std::cout << "请选择执黑or执白（黑先，白后），1-执黑；2-执白：";
		scanf("%d", &b_w);  //获得对战模式
		getchar();

		if (b_w == 1)//玩家执黑(先手)，电脑执白(后手)
		{
			who = WHITE;
			opp = BLACK;
		}
		else if(b_w == 2)//玩家执白(后手)，电脑执黑(先手)
		{
			who = BLACK;
			opp = WHITE;
		}
		else
			std::cout << "选择错误!!!";
	}
}

void Referee::start()
{
	_chessboard.InitBoardArray();//棋盘初始化
	_chessboard.DisplayBoard();//显示棋盘
	//人人对战
	if (_game_type == Man2Man)
	{
		while (1)
		{
			//
			std::cout << "请玩家一(执黑)输入下棋坐标(如H8):";
			player1->play();
			while (_chessboard.judge_overlap(player1->y, player1->x))
			{
				std::cout << "下棋位置已经存在棋子，请玩家一(执黑)重新输入下棋坐标(如H8):";
				player1->play();
			}
			if (_chessboard.Detect_Prohibit(SIZE - player1->x, player1->y - 'A'))//禁手
			{
				std::cout << "玩家一(执黑)禁手！！！" << std::endl;
				std::cout << "玩家二(执白)赢得游戏！！！" << std::endl;
				std::cout << "游戏结束！！！" << std::endl;
				break;
			}
			_chessboard.ChangeStatus(player1->_chessType, player1->y, player1->x, player1->last_y, player1->last_x);
			_chessboard.DisplayBoard();
			if (victory())
			{
				std::cout << "恭喜玩家一(执黑)赢得游戏！！！" << std::endl;
				std::cout << "游戏结束！！！" << std::endl;
				break;
			}

			std::cout << "请玩家二(执白)输入下棋坐标(如H8):";
			player2->play();
			while (_chessboard.judge_overlap(player2->y, player2->x))
			{
				std::cout << "下棋位置已经存在棋子，请玩家二(执白)重新输入下棋坐标(如H8):";
				player2->play();
			}
			_chessboard.ChangeStatus(player2->_chessType, player2->y, player2->x, player2->last_y, player2->last_x);
			_chessboard.DisplayBoard();
			if (victory())
			{
				std::cout << "恭喜玩家二(执白)赢得游戏！！！" << std::endl;
				std::cout << "游戏结束！！！" << std::endl;
				break;
			}
		}
	}
	else
	{
		int AI_X = -1, AI_Y = -1;
		int Last_AI_X = -1, Last_AI_Y = -1;

		if (who == BLACK)//电脑执黑
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
					std::cout << "电脑(执黑)赢得游戏！！！" << std::endl;
					std::cout << "游戏结束！！！" << std::endl;
					break;
				}
				std::cout << "电脑(执黑)下棋坐标：" << AI_Y << " " << AI_X << std::endl;

				std::cout << "请玩家(执白)输入下棋坐标(如H8):";
				player2->play();
				while (_chessboard.judge_overlap(player2->y, player2->x))
				{
					std::cout << "下棋位置已经存在棋子，请玩家(执白)重新输入下棋坐标(如H8):";
					player2->play();
				}
				wind->Opp_Move(player2->y - 'A', SIZE - player2->x);//记下棋手下棋位置
				_chessboard.ChangeStatus(player2->_chessType, player2->y, player2->x, player2->last_y, player2->last_x);
				_chessboard.DisplayBoard();
				if (victory())
				{
					std::cout << "恭喜玩家(执白)赢得游戏！！！" << std::endl;
					std::cout << "游戏结束！！！" << std::endl;
					break;
				}				
			}
		}

		else//电脑执白
		{
			while (1)
			{
				//
				std::cout << "请玩家(执黑)输入下棋坐标(如H8):";
				player1->play();
				while (_chessboard.judge_overlap(player2->y, player2->x))
				{
					std::cout << "下棋位置已经存在棋子，请玩家(执黑)重新输入下棋坐标(如H8):";
					player2->play();
				}
				if (_chessboard.Detect_Prohibit(SIZE - player1->x, player1->y - 'A'))//禁手
				{
					std::cout << "玩家(执黑)禁手！！！" << std::endl;
					std::cout << "电脑(执白)赢得游戏！！！" << std::endl;
					std::cout << "游戏结束！！！" << std::endl;
					break;
				}
				wind->Opp_Move(player1->y - 'A', SIZE - player1->x);//记下棋手下棋位置
				_chessboard.ChangeStatus(player1->_chessType, player1->y, player1->x, player1->last_y, player1->last_x);
				_chessboard.DisplayBoard();
				if (victory())
				{
					std::cout << "恭喜玩家(执黑)赢得游戏！！！" << std::endl;
					std::cout << "游戏结束！！！" << std::endl;
					break;
				}

				Last_AI_X = AI_X; Last_AI_Y = AI_Y;
				wind->Get_Best(AI_X, AI_Y);
				_chessboard.ChangeStatus(white, 'A' + AI_X, SIZE - AI_Y, 'A' + Last_AI_X, SIZE - Last_AI_Y);
				_chessboard.DisplayBoard();
				if (victory())
				{
					std::cout << "电脑(执白)赢得游戏！！！" << std::endl;
					std::cout << "游戏结束！！！" << std::endl;
					break;
				}
				std::cout << "电脑(执白)下棋坐标：" << AI_Y << " " << AI_X << std::endl;
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

	//左上到右下
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
	//左下到右上
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
