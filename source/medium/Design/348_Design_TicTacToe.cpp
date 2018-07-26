#include <vector>
using namespace std;
class TicTacToe {
public:
    /** Initialize your data structure here. */
    TicTacToe(int n) {
        CountPerRow = vector<vector<int>>(n, vector<int>(2, 0));
        CountPerCol = vector<vector<int>>(n, vector<int>(2, 0));
        diagCount1 = vector<int>(2, 0);
        diagCount2 = vector<int>(2, 0);
        size = n;
    }
    
    /** Player {player} makes a move at ({row}, {col}).
        @param row The row of the board.
        @param col The column of the board.
        @param player The player, can be either 1 or 2.
        @return The current winning condition, can be either:
                0: No one wins.
                1: Player 1 wins.
                2: Player 2 wins. */
    int move(int row, int col, int player) {
        CountPerRow[row][player - 1] ++;
        CountPerCol[col][player - 1] ++;
        if (row == col) diagCount1[player - 1] ++;
        if (row + col == size - 1) diagCount2[player - 1] ++;
        if (CountPerRow[row][player - 1] == size || CountPerCol[col][player - 1] == size 
            || diagCount1[player - 1] == size || diagCount2[player - 1] == size)
            return player;
        return 0;
    }

    int size;
    vector<vector<int>> CountPerRow;
    vector<vector<int>> CountPerCol;
    vector<int> diagCount1;
    vector<int> diagCount2;
};
