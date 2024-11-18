#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isPossible(int row, int col, int n, vector<vector<int>> &ds)
    {
        // top diagonal
        int drow = row;
        int dcol = col;
        while (drow >= 0 && dcol >= 0)
        {
            if (ds[drow][dcol] == 1)
                return false;
            drow--;
            dcol--;
        }

        // left row
        drow = row;
        dcol = col;
        while (dcol >= 0)
        {
            if (ds[drow][dcol] == 1)
                return false;
            dcol--;
        }

        // bottom diagonal
        drow = row;
        dcol = col;
        while (drow < n && dcol >= 0)
        {
            if (ds[drow][dcol] == 1)
                return false;
            drow++;
            dcol--;
        }
        return true;
    }

    void solve(int col, int n, vector<vector<string>> &ans,
               vector<vector<int>> &ds)
    {
        if (col == n)
        {
            vector<string> temp;
            // vector<string> temp(n, string(n, '.'));
            string str;
            for (int i = 0; i < n; i++)
            {
                str = "";
                for (int j = 0; j < n; j++)
                {
                    if (ds[i][j] == 1)
                        str += 'Q';
                    else
                        str += '.';
                }
                temp.push_back(str);
            }
            ans.push_back(temp);
            return;
        }
        for (int row = 0; row < n; row++)
        {
            if (isPossible(row, col, n, ds))
            {
                ds[row][col] = 1;
                solve(col + 1, n, ans, ds);
                ds[row][col] = 0;
            }
        }
    }

    vector<vector<string>> solveNQueens(int n)
    {
        vector<vector<string>> ans;
        vector<vector<int>> ds(n, vector<int>(n, 0));
        solve(0, n, ans, ds);
        return ans;
    }
};