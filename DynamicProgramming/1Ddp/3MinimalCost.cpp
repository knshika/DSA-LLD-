//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // int solve(int i, int k, vector<int>& arr, vector<int> &dp) {
    //     if(i<=0) return 0;
    //     if(dp[i] != -1) return dp[i];
    //     int minHt = INT_MAX;
    //     int curr;
    //     for(int j=1; j<=k; j++){
    //     // If i<j means index is -ive and arr[-ive] will give wrong answer so keep ans as max by default
    //         int curr = (i<j) ? INT_MAX : (solve(i-j, k, arr, dp) + abs(arr[i] - arr[i-j]));
    //         minHt = min(minHt, curr);
    //     }
    //     dp[i] = minHt;
    //     return dp[i];
    // }

    // int minimizeCost(int k, vector<int>& arr) {
    //     // Code here
    //     int n = arr.size();
    //     if(n <= 1) return 0;
    //     vector<int> dp(n+1, -1);
    //     solve(n-1, k, arr, dp);
    //     return dp[n-1];
    // }

    int minimizeCost(int k, vector<int> &arr)
    {
        // Code here
        int n = arr.size();
        if (n <= 1)
            return 0;
        vector<int> dp(n + 1, -1);
        dp[0] = 0;
        for (int i = 1; i < n; i++)
        {
            int minHt = INT_MAX;
            for (int j = 1; j <= k; j++)
            {
                int curr = (i < j) ? INT_MAX : (abs(arr[i] - arr[i - j]) + dp[i - j]);
                minHt = min(minHt, curr);
            }
            dp[i] = minHt;
        }
        return dp[n - 1];
    }

    // 10 30 40 50 20
    //     1  1  1  1
    //     1     2   1
    //     1         3
    //     1   1     2
    //         2     2
    //         2   1  1
    //             3   1
};

//{ Driver Code Starts.

int main()
{
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--)
    {
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number)
        {
            arr.push_back(number);
        }
        Solution obj;
        int res = obj.minimizeCost(k, arr);
        cout << res << endl;
        cout << "~" << endl;
        // string tl;
        // getline(cin, tl);
    }
    return 0;
}

// } Driver Code Ends