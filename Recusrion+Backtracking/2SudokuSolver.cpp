#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isPossible(char num, int row, int col, vector<vector<char>> &board)
    {
        // for a col
        for (int i = 0; i < 9; i++)
        {
            if (board[i][col] == num)
                return false;
        }

        // for a row
        for (int i = 0; i < 9; i++)
        {
            if (board[row][i] == num)
                return false;
        }

        // in 3/3 matrix ,
        for (int i = 0; i < 9; i++)
        {
            if (board[(3 * (row / 3)) + i / 3][(3 * (col / 3)) + i % 3] == num)
                return false;
        }
        return true;
    }

    bool solve(int n, vector<vector<char>> &board)
    {
        for (int i = 0; i < n; i++)
        { // check from starting
            for (int j = 0; j < n; j++)
            {
                // bool gotAns = false;
                if (board[i][j] == '.')
                {
                    for (int k = 1; k <= 9; k++)
                    {
                        if (isPossible(char(k) + '0', i, j, board))
                        {
                            board[i][j] = char(k) + '0';
                            if (solve(n, board))
                                return true; // we got answer for now
                            else
                                board[i][j] = '.';
                        }
                    }
                    return false; // we did not get any answer for this pos
                }
            }
        }
        return true; // we got possible answers for all
    }
    void solveSudoku(vector<vector<char>> &board)
    {
        int n = board.size();
        solve(n, board);
    }
};