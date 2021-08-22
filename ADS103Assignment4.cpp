#include <iostream>
#include <vector>
#include <tuple>
#include <string>
#include <limits>
#include <algorithm>
#include <cctype>
#include <map>

using namespace std;


//						   '#','#','#',

class TicTacToe
{
public:

	char X = 'X';
	char O = 'O';

	vector<char> logicBoard = { '#','#','#',
								'#','#','#',
								'#','#','#' };

	vector<char> letters = { 'A','B','C','D','E','F','G','H','I' };
	vector<char> gameBoard = { 'A','B','C','D','E','F','G','H','I' };

	TicTacToe()
	{
		X;
		O;
		gameBoard;
		letters;
	}

	char player(vector<char> board)
	{
		int count = 0;

		for (int i = 0; i < 9; i++)
			if (board[i] == '#')
				count += 1;

		if (count % 2 == 0)
			return 'O';
		else
			return 'X';
	}

	vector<int> actions(vector<char> board)
	{
		vector<int> temp;

		for (int i = 0; i < 9; i++)
			if (board[i] == '#')
				temp.push_back(i);

		return temp;
	}

	vector<char> result(vector<char> board, int action)
	{
		vector<char> tempBoard;

		copy(board.begin(), board.end(), back_inserter(tempBoard));

		tempBoard[action] = player(tempBoard);

		return tempBoard;
	}

	char winner(vector<char> board)
	{
		bool swap = false;
		char mark = ' ';

		for (int i = 0; i < 2; i++)
		{
			if (!swap)
				mark = 'X';
			else
				mark = 'O';

			if ((board[0] == mark && board[1] == mark && board[2] == mark) ||
				(board[3] == mark && board[4] == mark && board[5] == mark) ||
				(board[6] == mark && board[7] == mark && board[8] == mark) ||
				(board[0] == mark && board[3] == mark && board[6] == mark) ||
				(board[1] == mark && board[4] == mark && board[7] == mark) ||
				(board[2] == mark && board[5] == mark && board[8] == mark) ||
				(board[0] == mark && board[4] == mark && board[8] == mark) ||
				(board[2] == mark && board[4] == mark && board[6] == mark))
				return mark;

			swap = true;
		}
		return '#';
	}

	bool terminal(vector<char> board)
	{
		bool noSpace = true;

		for (int i = 0; i < 9; i++)
			if (board[i] == '#')
				noSpace = false;

		return noSpace || winner(board) == X || winner(board) == O;
	}

	int utility(vector<char> board)
	{
		int result = 0;

		if (winner(board) == X)
			result = 1;
		else if (winner(board) == O)
			result = -1;

		return result;
	}

	bool validInput(vector<char> board, char input)
	{
		bool valid = false;
		char move = (char)toupper(input);

		for (int i = 0; i < 9; i++)
		{
			if (move == letters[i])
				valid = true;
		}


		return valid;
	}

	int minValue(vector<char> board)
	{
		if (terminal(board))
			return utility(board);

		int value = 1000;

		for (auto& action : actions(board))
			value = min(value, maxValue(result(board, action)));

		return value;
	}

	int maxValue(vector<char> board)
	{
		if (terminal(board))
			return utility(board);

		int value = -1000;

		for (auto& action : actions(board))
			value = max(value, minValue(result(board, action)));

		return value;
	}

	int Minimax(vector<char> board)
	{
		int optimal = -3;
		int value = -4;

		if (player(board) == X)
		{
			value = -1000;

			for (auto& action : actions(board))
			{
				int newValue = minValue(result(board, action));

				if (newValue > value)
				{
					value = newValue;
					optimal = action;
				}
			}
		}
		else if (player(board) == O)
		{
			value = 1000;

			for (auto& action : actions(board))
			{
				int newValue = maxValue(result(board, action));
				if (newValue < value)
				{
					value = newValue;
					optimal = action;
				}
			}
		}

		return optimal;
	}

	void displayBoard(vector<char> board)
	{
		for (int i = 0; i < 9; i++)
		{
			if (board[i] == 'X')
				letters[i] = 'X';
			else if (board[i] == 'O')
				letters[i] = 'O';
		}

		for (int i = 0; i < 9; i++)
		{
			if (i % 3 == 0)
				cout << "\n\t";
			cout << letters[i];
		}
		cout << endl;
	}

	int menu()
	{
		int selection;
		cout << "\n\t\tWelcome to Tic Tac Toe\n\n\tPlease make a selection: " << endl;
		cout << "\n\t1. Play: \n\t2. Exit: ";
		cin >> selection;

		return selection;
	}



	void playGame(vector<char> board)
	{
		bool continuePlaying = true;
		char player = X;
		char input;
		int bestMove;

		int choice = menu();

		if (choice == 2)
			continuePlaying = false;

		while (continuePlaying)
		{

			if (terminal(board))
			{
				if (utility(board) == 0)
				{
					cout << "\nit's a tie!" << endl;
					continuePlaying = false;
				}
				else
				{
					cout << "\nThe winner is " << winner(board) << endl;
					continuePlaying = false;
				}
			}
			else
			{
				if (player == X)
				{

					char input = ' ';
					bool valid = false;
					displayBoard(board);
					cout << "\n\tYou are player X..." << endl;
					cout << "\n\tEnter the letter corresponding to where you wish to move: ";
					cin >> input;

					valid = validInput(board, input);

					while (!valid)
					{
						cout << "\n\tYou are player X..." << endl;
						cout << "\n\tEnter the letter corresponding to where you wish to move: ";
						cin >> input;
						valid = validInput(board, input);
					}

					input = (char)toupper(input);

					//displayBoard(board);
					for (int i = 0; i < 9; i++)
					{
						if (input == letters[i])
							board[i] = X;
					}
					displayBoard(board);
					player = O;

				}
				else
				{
					cout << "\n\tComputers move..." << endl;
					bestMove = Minimax(board);
					board[bestMove] = O;
					//displayBoard(board);
					player = X;
				}
			}
		}
	}
};

int main()
{

	TicTacToe ttt;
	vector<char> board = ttt.logicBoard;
	//vector<char> newBoard = ttt.result(board, 1);
	//int size = newBoard.size();

	char win = ttt.winner(board);

	//int bestMove = ttt.Minimax(board);

	//cout << bestMove;

	bool gameOver = ttt.terminal(board);
	char player = 'X';



	ttt.playGame(board);

}