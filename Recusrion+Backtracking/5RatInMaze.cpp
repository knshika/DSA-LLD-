//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution
{
public:
    /// SOLUTION ONE

    /// SOLUTION TWO

    bool isSafe(int i, int j, int n, vector<vector<int>> &maze, vector<vector<int>> &vis)
    {
        return (i >= 0 && i < n && j >= 0 && j < n && maze[i][j] == 1 && vis[i][j] == 0);
    }

    void solve(int i, int j, string str, int n, vector<vector<int>> &maze, vector<vector<int>> &vis, vector<string> &ans, int diri[], int dirj[])
    {
        if (i == n - 1 && j == n - 1)
        {
            ans.push_back(str);
            return;
        }
        string dir = "DLRU";

        for (int k = 0; k < 4; k++)
        {
            int nexti = i + diri[k];
            int nextj = j + dirj[k];
            if (isSafe(nexti, nextj, n, maze, vis))
            {
                vis[i][j] = 1;                                                    // we will make current node as vis not next
                solve(nexti, nextj, str + dir[k], n, maze, vis, ans, diri, dirj); // we are checking for next node in if condition to call recursion again
                vis[i][j] = 0;
            }
        }
    }

    vector<string> findPath(vector<vector<int>> &m, int n)
    {
        // Your code goes here
        vector<string> ans;
        vector<vector<int>> vis(n, vector<int>(n, 0));
        int diri[] = {1, 0, 0, -1};
        int dirj[] = {0, -1, 1, 0};
        if (m[0][0])
            solve(0, 0, "", n, m, vis, ans, diri, dirj);
        return ans;
    }

    // void solve(int i, int j,string str, int n, vector<vector<int>> &maze,vector<vector<int>> &vis, vector<string> &ans) {
    // if(i == n-1 && j == n-1){
    //     ans.push_back(str);
    //     return;
    // }

    // //down
    // if(isSafe(i+1, j,n,maze,vis)){
    // // if(i+1>n && maze[i+1][j]==1 && vis[i+1][j]==0)
    //     vis[i][j] = 1; //we will make current node as vis not next
    //     solve(i+1,j,str+"D",n, maze,vis,ans); //we are checking for next node in if condition to call recursion again
    //     vis[i][j] = 0;
    // }
    // //left
    // if(isSafe(i, j-1,n,maze,vis)){
    // // if(j-1>=0 && maze[i][j-1]==1 && vis[i][j-1]==0){
    //     vis[i][j] = 1;
    //     solve(i,j-1,str+"L",n, maze,vis,ans);
    //     vis[i][j] = 0;
    // }
    // //right
    // if(isSafe(i, j+1,n,maze,vis)){
    // // if(j+1>n && maze[i][j+1]==1 && vis[i][j+1]==0){
    //     vis[i][j] = 1;
    //     solve(i,j+1,str+"R",n, maze,vis,ans);
    //     vis[i][j] = 0;
    // }
    // //up
    // if(isSafe(i-1, j,n,maze,vis)){
    // // if(i-1>=0 && maze[i-1][j]==1 && vis[i-1][j]==0){
    //     vis[i][j] = 1;
    //     solve(i-1,j,str+"U",n, maze,vis,ans);
    //     vis[i][j] = 0;
    // }

    // }

    // vector<string> findPath(vector<vector<int>> &m, int n) {
    //     // Your code goes here
    //     vector<string> ans;
    //     vector<vector<int>> vis(n,vector<int>(n,0));
    //     if(m[0][0]) solve(0,0,"",n,m,vis,ans);
    //     return ans;
    // }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++)
                cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends