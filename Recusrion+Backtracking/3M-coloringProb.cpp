//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    bool isPossible(int i, int color[], int k, int n, bool graph[101][101])
    {
        for (int j = 0; j < n; j++)
        {
            if (i != j && graph[i][j] == 1 && color[j] == k)
                return false; // color[i] !=k bcz we are checking if k is possible, by default color[i]=0
        }
        return true;
    }

    bool solve(int i, int color[], int m, int n, bool graph[101][101])
    {
        if (i == n)
            return true; // base condition

        for (int k = 1; k <= m; k++)
        { // need to start with 1 as it is 0 bydeafult
            if (isPossible(i, color, k, n, graph))
            {
                color[i] = k;
                if (solve(i + 1, color, m, n, graph))
                    return true; // if return is true
                color[i] = 0;
            }
        }
        return false; // means no possible found
    }
    // Function to determine if graph can be coloured with at most M colours such
    // that no two adjacent vertices of graph are coloured with same colour.
    bool graphColoring(bool graph[101][101], int m, int n)
    {
        // your code here
        int color[n] = {0};
        return solve(0, color, m, n, graph);
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++)
        {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++)
        {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        Solution ob;
        cout << ob.graphColoring(graph, m, n) << endl;
    }
    return 0;
}

// } Driver Code Ends