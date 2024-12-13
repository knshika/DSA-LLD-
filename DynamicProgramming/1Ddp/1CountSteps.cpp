#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TABULAR without dp array

    int climbStairs(int n)
    {
        int prev2 = 1; // dp[0]
        int prev1 = 1; // dp[1]
        for (int i = 2; i <= n; i++)
        {
            int cur = prev1 + prev2;
            prev2 = prev1;
            prev1 = cur;
        }
        return prev1;
    }

    // TABULAR

    // int climbStairs(int n) {
    //     if(n==1) return 1;
    //     vector<int>dp (n+1, -1);
    //     dp[0] = 1;
    //     dp[1] = 1;
    //     for (int i = 2; i <= n; i++) {
    //         dp[i] = dp[i-1] + dp[i-2];
    //     }
    //     return dp[n];
    // }

    // MEMOISATION

    // int solve(int n, vector<int> &dp) {
    //     if(n<0) return 0;
    //     if(n<=1) return 1;
    //     if(dp[n] != -1) return dp[n];
    //     dp[n] = solve(n-1, dp) + solve(n-2, dp);
    //     return dp[n];
    // }

    // int climbStairs(int n) {
    //     if(n<=1) return 1;
    //     vector<int> dp(n+1, -1);
    //     return solve(n, dp);
    // }

    // RECURSION

    // int climbStairs(int n) {
    //     if(n<=0) return 0;
    //     if(n<=2) return 1;
    //     return climbStairs(n -1) + climbStairs(n-2)

    // }
};

int main()
{
    int n;
    cin >> n;
    Solution sol;
    cout << sol.climbStairs(n);
    return 0;
}