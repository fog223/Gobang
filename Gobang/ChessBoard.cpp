#include "ChessBoard.h"

ChessBoard::ChessBoard()
{
	for (int i = 0; i <= SIZE - 1; i++)
		for (int j = 0; j <= SIZE - 1; j++)
			Board_Status[i][j] = EMPTY;
}

ChessBoard::~ChessBoard()
{
}

void ChessBoard::InitBoardArray()
{
	int j, i;

	Board[0][0] = 1;
	Board[0][SIZE - 1] = 2;
	Board[SIZE - 1][SIZE - 1] = 3;
	Board[SIZE - 1][0] = 4;

	for (j = 1; j <= SIZE - 2; j++)
	{
		Board[j][0] = 5;
	}

	for (i = 1; i <= SIZE - 2; i++)
	{
		Board[0][i] = 6;
	}

	for (j = 1; j <= SIZE - 2; j++)
	{
		Board[j][SIZE - 1] = 7;
	}

	for (i = 1; i <= SIZE - 2; i++)
	{
		Board[SIZE - 1][i] = 8;
	}

	for (j = 1; j <= SIZE - 2; j++)
	{
		for (i = 1; i <= SIZE - 2; i++)
		{
			Board[j][i] = 9;
		}
	}
}

void ChessBoard::DisplayBoard()
{
	int i, j;
	char line;
	char ary;

	system("cls");   //清屏

	for (j = 0, line = 15; j <= SIZE - 1; j++)
	{
		printf("%2d", line);
		line -= 1;
		for (i = 0; i <= SIZE - 1; i++)
		{
			switch (Board[j][i])
			{
			case 1:
				printf("┏ ");
				break;

			case 2:
				printf("┓");
				break;

			case 3:
				printf("┛");
				break;

			case 4:
				printf("┗ ");
				break;

			case 5:
				printf("┠ ");
				break;

			case 6:
				printf("┯ ");
				break;

			case 7:
				printf("┨");
				break;

			case 8:
				printf("┷ ");
				break;

			case 9:
				printf("┼ ");
				break;

			case BLACKtem:      // 黑子上一步
				printf("△");
				break;

			case WHITEtem:      //白子上一步
				printf("▲");
				break;

			case BLACKChess:      //黑子通常
				printf("○");
				break;

			case WHITEChess:
				printf("●");  //白子通常
				break;
			}
			if (i == SIZE - 1)
			{
				printf("\n");
			}

		}
	}

	printf("  ");
	for (ary = 'A'; ary < 'A' + SIZE; ary++)
		printf("%c ", ary);

	printf("\n");
}

void ChessBoard::ChangeStatus(chessType _chessType, char _y, int _x, char _last_y, int _last_x)
{
	if (_chessType == black)
	{
		Board_Status[SIZE - _x][_y - 'A'] = BLACK;
		if ((_last_y >= 'A'&&_last_y <= 'O') || (_last_x >= 1 && _last_x <= SIZE))
		{
			Board[SIZE - _last_x][_last_y - 'A'] = BLACKtem;
			Board[SIZE - _x][_y - 'A'] = BLACKChess;
		}
		else
			Board[SIZE - _x][_y - 'A'] = BLACKChess;
	}
	else
	{
		Board_Status[SIZE - _x][_y - 'A'] = WHITE;
		if ((_last_y >= 'A'&&_last_y <= 'O') || (_last_x >= 1 && _last_x <= SIZE))
		{
			Board[SIZE - _last_x][_last_y - 'A'] = WHITEtem;
			Board[SIZE - _x][_y - 'A'] = WHITEChess;
		}	
		else
			Board[SIZE - _x][_y - 'A'] = WHITEChess;
	}
}

bool ChessBoard::judge_overlap(char _y, int _x)
{
	if(Board[SIZE - _x][_y - 'A'] == WHITEtem|| 
		Board[SIZE - _x][_y - 'A'] == WHITEChess||
		Board[SIZE - _x][_y - 'A'] == BLACKtem ||
		Board[SIZE - _x][_y - 'A'] == BLACKChess)
		return true;
	else
		return false;
}

void ChessBoard::Get_Shape(int x, int y)
{
	chessshape.clear();

	//上
	std::string shape1;
	for (int i = 4; i >= 1; i--)
		if ((x - i) >= 0 && (x - i) <= (SIZE - 1))
			shape1 += std::to_string(Board_Status[x - i][y]);

	//下
	std::string shape2;
	for (int i = 1; i <= 4; i++)
		if ((x + i) >= 0 && (x + i) <= (SIZE - 1))
			shape2 += std::to_string(Board_Status[x + i][y]);

	//左
	std::string shape3;
	for (int i = 4; i >= 1; i--)
		if ((y - i) >= 0 && (y - i) <= (SIZE - 1))
			shape3 += std::to_string(Board_Status[x][y - i]);

	//右
	std::string shape4;
	for (int i = 1; i <= 4; i++)
		if ((y + i) >= 0 && (y + i) <= (SIZE - 1))
			shape4 += std::to_string(Board_Status[x][y + i]);

	//左上
	std::string shape5;
	for (int i = 4; i >= 1; i--)
		if ((x - i) >= 0 && (y - i) >= 0)
			if ((x - i) <= (SIZE - 1) && (y - i) <= (SIZE - 1))
				shape5 += std::to_string(Board_Status[x - i][y - i]);

	//右下
	std::string shape6;
	for (int i = 1; i <= 4; i++)
		if ((x + i) >= 0 && (y + i) >= 0)
			if ((x + i) <= (SIZE - 1) && (y + i) <= (SIZE - 1))
				shape6 += std::to_string(Board_Status[x + i][y + i]);

	//左下
	std::string shape7;
	for (int i = 4; i >= 1; i--)
		if ((x + i) >= 0 && (y - i) >= 0)
			if ((x + i) <= (SIZE - 1) && (y - i) <= (SIZE - 1))
				shape7 += std::to_string(Board_Status[x + i][y - i]);

	//右上
	std::string shape8;
	for (int i = 1; i <= 4; i++)
		if ((x - i) >= 0 && (y + i) >= 0)
			if ((x - i) <= (SIZE - 1) && (y + i) <= (SIZE - 1))
				shape8 += std::to_string(Board_Status[x - i][y + i]);

	chessshape.push_back(shape1);
	chessshape.push_back(shape2);
	chessshape.push_back(shape3);
	chessshape.push_back(shape4);
	chessshape.push_back(shape5);
	chessshape.push_back(shape6);
	chessshape.push_back(shape7);
	chessshape.push_back(shape8);
}

//一子落下，如果黑棋同时形成两个或两个以上的活三、活四、冲四，或者一子落下超过五连的，这个落子位置叫做禁手
bool ChessBoard::Detect_Prohibit(int x, int y)
{
	Get_Shape(x, y);//获取下棋点棋形

	int Four_count = 0;//‘四’个数
	int Three_count = 0;//‘活三’个数

	std::vector<std::string> chesss_shapes;
	std::string chesss_shape1 = chessshape[0] + "1" + chessshape[1];//一竖
	std::string chesss_shape2 = chessshape[2] + "1" + chessshape[3];//一横
	std::string chesss_shape3 = chessshape[4] + "1" + chessshape[5];//主对角
	std::string chesss_shape4 = chessshape[6] + "1" + chessshape[7];//副对角
	chesss_shapes.push_back(chesss_shape1);
	chesss_shapes.push_back(chesss_shape2);
	chesss_shapes.push_back(chesss_shape3);
	chesss_shapes.push_back(chesss_shape4);

	std::string shape1 = "111111";//六长连禁手
	std::string shape2 = "1111111";//七长连禁手
	std::string shape3 = "11111111";//八长连禁手
	std::string shape4 = "111111111";//九长连禁手

	std::string shape5 = "11211211";//四四禁手
	std::string shape6 = "1211121";//四四禁手

	std::string shape7 = "211112";//活四
	std::string shape8 = "011112";//冲四
	std::string shape9 = "211110";//冲四
	std::string shape10 = "11121";//冲四
	std::string shape11 = "11211";//冲四
	std::string shape12 = "12111";//冲四
	std::string shape13 = "211122";//活三
	std::string shape14 = "221112";//活三
	std::string shape15 = "211212";//活三
	std::string shape16 = "212112";//活三

	for (int i = 0; i < chesss_shapes.size(); i++)
	{
		if (chesss_shapes[i].find(shape1) != std::string::npos)
		{
			std::cout << "六长连禁手" << std::endl;
			return true;
		}
		else if (chesss_shapes[i].find(shape2) != std::string::npos)
		{
			std::cout << "七长连禁手" << std::endl;
			return true;
		}
		else if (chesss_shapes[i].find(shape3) != std::string::npos)
		{
			std::cout << "八长连禁手" << std::endl;
			return true;
		}
		else if (chesss_shapes[i].find(shape4) != std::string::npos)
		{
			std::cout << "九长连禁手" << std::endl;
			return true;
		}
		else if (chesss_shapes[i].find(shape5) != std::string::npos)
		{
			std::cout << "四四禁手" << std::endl;
			return true;
		}
		else if (chesss_shapes[i].find(shape6) != std::string::npos)
		{
			std::cout << "四四禁手" << std::endl;
			return true;
		}
		else if (chesss_shapes[i].find(shape7) != std::string::npos)
			Four_count++;
		else if (chesss_shapes[i].find(shape8) != std::string::npos)
			Four_count++;
		else if (chesss_shapes[i].find(shape9) != std::string::npos)
			Four_count++;
		else if (chesss_shapes[i].find(shape10) != std::string::npos)
			Four_count++;
		else if (chesss_shapes[i].find(shape11) != std::string::npos)
			Four_count++;
		else if (chesss_shapes[i].find(shape12) != std::string::npos)
			Four_count++;
		else if (chesss_shapes[i].find(shape13) != std::string::npos)
			Three_count++;
		else if (chesss_shapes[i].find(shape14) != std::string::npos)
			Three_count++;
		else if (chesss_shapes[i].find(shape15) != std::string::npos)
			Three_count++;
		else if (chesss_shapes[i].find(shape16) != std::string::npos)
			Three_count++;
	}
	if (Four_count >= 2)
	{
		std::cout << "四四禁手" << std::endl;
		return true;
	}
	else if(Three_count >= 2)
	{
		std::cout << "三三禁手" << std::endl;
		return true;
	}
	else
		return false;
}
