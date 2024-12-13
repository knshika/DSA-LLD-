//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    //   int solve(int i, vector<int> &height) {
    //     if(i<=0) return 0;
    //     int step1 = abs(height[i] - height[i-1]) + solve(i-1, height);
    //     int step2 = INT_MAX;
    //     if(i>1)
    //         step2 = abs(height[i] - height[i-2]) + solve(i-2, height);
    //     return min(step1, step2);
    // }

    int minimumEnergy(vector<int> &height, int n)
    {
        // Code here
        vector<int> dp(n + 1, -1);
        dp[0] = 0;
        for (int i = 1; i < n; i++)
        {
            int step1 = dp[i - 1] + abs(height[i] - height[i - 1]);
            int step2 = INT_MAX;
            if (i > 1)
                step2 = dp[i - 2] + abs(height[i] - height[i - 2]);
            dp[i] = min(step1, step2);
        }
        return dp[n - 1];
    }

    // int solve(int i, vector<int> &height, vector<int> &dp) {
    //     if(i<=0) return 0;
    //     if(dp[i] != -1) return dp[i];
    //     int step1 = abs(height[i] - height[i-1]) + dp[i-1];
    //     int step2 = INT_MAX;
    //     if(i>1)
    //         step2 = abs(height[i] - height[i-2]) + dp[i-2];
    //     dp[i] = min(step1, step2);
    //     return dp[i];
    // }

    // int minimumEnergy(vector<int>& height, int n) {
    //     // Code here
    //     if(n==1) return 0;
    //     vector<int> dp(n+1, -1);
    //     int minEnergy = 0;
    //     int curEnergy = 0;
    //     return solve(n-1, height);
    // }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++)
        {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minimumEnergy(arr, N) << "\n";

        cout << "~" << "\n";
    }
    return 0;
}
// } Driver Code Ends