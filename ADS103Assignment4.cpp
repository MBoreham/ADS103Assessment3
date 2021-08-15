// ADS103Assignment4.cpp 
// Marcus Boreham

#include <iostream>
#include <vector>
#include <tuple>
#include <string>


using namespace std;



class TicTacToe
{
public:

    string startingBoard[25] = {" 1 ", " | ", " 2 ", " | ", " 3 ",     //  0   2   4
                                "---", " | ", "---", " | ", "---",
                                " 4 ", " | ", " 5 ", " | ", " 6 ",      //  10  12  14
                                "---", " | ", "---", " | ", "---",
                                " 7 ", " | ", " 8 ", " | ", " 9 " };    //  20  22  24


    string displayBoard[25] = { " 1 ", " | ", " 2 ", " | ", " 3 ",      
                                "---", " | ", "---", " | ", "---",
                                " 4 ", " | ", " 5 ", " | ", " 6 ",      
                                "---", " | ", "---", " | ", "---",
                                " 7 ", " | ", " 8 ", " | ", " 9 " };    


              // Numbers     1    2    3    4    5    6    7    8    9
    string gameBoard[9] = { "#", "#", "#", "#", "#", "#", "#", "#", "#"};
                // Index     0    1    2    3    4    5    6    7    8  
              


    string playerMark = "";
    bool isHuman = true;

    TicTacToe()
    {
        displayBoard;
        gameBoard;
        playerMark;
        isHuman;
    }

    // Returns true if the current player has won the game
    bool winner(string board[], string mark)
    {       
        if ((board[0] == mark && board[1] == mark && board[2] == mark) ||
            (board[3] == mark && board[4] == mark && board[5] == mark) ||
            (board[6] == mark && board[7] == mark && board[8] == mark) ||
            (board[0] == mark && board[3] == mark && board[6] == mark) ||
            (board[1] == mark && board[4] == mark && board[7] == mark) ||
            (board[2] == mark && board[5] == mark && board[8] == mark) ||
            (board[0] == mark && board[4] == mark && board[8] == mark) ||
            (board[2] == mark && board[4] == mark && board[6] == mark))
            return true;
        else
            return false;
    }

    // Returns all the possible locations that are 
    // not occupied with either an 'X' or 'O'
    vector<int> actions(string board[])
    {
        vector<int> possibleActions;
     
        for (int i = 0; i < 9; i++)
        {
            if (board[i] == "#")
            {
                possibleActions.push_back(i);
            }
        }
        if (possibleActions.empty())
            possibleActions.push_back(-1); // Full board

        return possibleActions;
    }

    // Returns the current player
    string nextPlayer(string board[])
    {
        int count = 0;

        for (int i = 0; i < 9; i++)
            if (board[i] == "#")
                count += 1;
               
        if (count % 2 == 0)
            return "X";
        else
            return "O";
    }

    int utility(string board[])
    {
        int result = 0;

        if (winner(board, "X"))
            result = 1;
        else if (winner(board, "O"))
            result = -1;

        return result;
    }

    bool terminal(string board[], string mark)
    {
        bool fullBoard = true;

        for (int i = 0; i < 9; i++)
            if (board[i] == "#")
                fullBoard = false;

        return fullBoard || winner(board, mark);
    }

    int minValue(string board[])
    {
        if(terminal(board))
    }

};


int main()
{

    TicTacToe ttt;
    ttt.gameBoard;
    ttt.playerMark = "X";

    // Declares a vector to hold the available moves
    // possible by the current player
    vector<int> actions;
    actions = ttt.actions(ttt.gameBoard);

    int size = actions.size();
    int result = ttt.utility(ttt.gameBoard);

    for (int i = 0; i < size; i++)
        cout << actions[i];

    cout << "\n";

    string cPlayer = ttt.nextPlayer(ttt.gameBoard);
    cout << "current player returns: " << cPlayer << endl;

    bool yeahOrNay = ttt.winner(ttt.gameBoard, ttt.nextPlayer(ttt.gameBoard));

    if (yeahOrNay)
        cout << "Win is true";
    else
        cout << "Win is false";

    cout << "\nUtility: " << result << endl;
    
    bool isTerminal = ttt.terminal(ttt.gameBoard, ttt.nextPlayer(ttt.gameBoard));

    if (isTerminal)
        cout << "Terminal is true";
    else
        cout << "Terminal is false";
        
    cout << "\n\n\n\n\n\n";
}

