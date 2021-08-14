// ADS103Assignment4.cpp 
// Marcus Boreham

#include <iostream>
#include <vector>
#include <tuple>


using namespace std;



class Player
{
public:

    string playerMark = "";

    Player()
    {
        playerMark;
    }
};

class Board
{
public:

    string displayBoard[5][5] = { {" X ", " | ", " X ", " | ", " X "},      // (0,0) (0,2) (0,4)
                                  {"---", " | ", "---", " | ", "---"},
                                  {" 4 ", " | ", " 5 ", " | ", " 6 "},      // (2,0) (2,2) (2,4)
                                  {"---", " | ", "---", " | ", "---"},
                                  {" 7 ", " | ", " 8 ", " | ", " 9 "} };    // (4,0) (4,2) (4,4)
    
    string gameBoard[3][3] = { {"X","2","3"},       // 00 01 02
                               {"4","5","6"},       // 10 11 12
                               {"7","8","9"} };     // 20 21 22

    Board()
    {
        displayBoard;
        gameBoard;

    }

    bool winner(Board b, Player x)
    {
        bool playerX = true;
        string p = x.playerMark;
        cout <<"player mark = " << p << endl;
        if(p == "O")
            bool playerX = false;
        

        if (playerX)
            p = "X";
        else
            p = "O";
        if ((b.gameBoard[0][0] == p && b.gameBoard[0][1] == p && b.gameBoard[0][2] == p) ||
            (b.gameBoard[1][0] == p && b.gameBoard[1][1] == p && b.gameBoard[1][2] == p) ||
            (b.gameBoard[2][0] == p && b.gameBoard[2][1] == p && b.gameBoard[2][2] == p) ||
            (b.gameBoard[0][0] == p && b.gameBoard[1][0] == p && b.gameBoard[2][0] == p) ||
            (b.gameBoard[0][1] == p && b.gameBoard[1][1] == p && b.gameBoard[2][1] == p) ||
            (b.gameBoard[0][2] == p && b.gameBoard[1][2] == p && b.gameBoard[2][2] == p) ||
            (b.gameBoard[0][0] == p && b.gameBoard[1][1] == p && b.gameBoard[2][2] == p) ||
            (b.gameBoard[0][2] == p && b.gameBoard[1][1] == p && b.gameBoard[2][0] == p))
            return true;
        else
            return false;
    }
    
    vector<tuple<int, int>> actions(Board b, Player p)
    {
        vector<tuple<int, int>> possibleActions;
        tuple <int, int> temp;

        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
                if (b.gameBoard[i][j] != "X" && b.gameBoard[i][j] != "O")
                {
                    temp = make_tuple(i, j);
                    possibleActions.push_back(temp);
                }
        }
        return possibleActions;
    }
        
};







int main()
{
    Player p;
    p.playerMark = "X";
    Board b;

    vector<tuple<int, int>> pActions;

    pActions = b.actions(b, p);

    for (int i = 0; i < 5; i++)
    {
        cout << "\n";
        for (int j = 0; j < 5; j++)
            cout << b.displayBoard[i][j];
    }
        
 
    cout << "\n" << b.gameBoard[0][0] << b.gameBoard[0][1] << b.gameBoard[0][2] << endl;
    
    cout << "\n\n\n\n\n";
        
    bool yeah = b.winner(b, p);

    if(yeah)
        cout << "true";
    if (!yeah)
        cout << "false";

    cout << "\n" << b.displayBoard[4][4];

    int size = pActions.size();

   

    
}

