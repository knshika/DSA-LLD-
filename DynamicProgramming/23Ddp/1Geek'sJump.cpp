//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    int maximumPoints(vector<vector<int>> &arr, int n)
    {
        // Code here
        // if(n == 1) return max(arr[0], max(arr[1], arr[2]));
        // vector<vector<int>> dp(n+1, (vector<int>(3,-1)));
        int prev[3], curr[3];

        prev[0] = max(arr[0][1], arr[0][2]);
        prev[1] = max(arr[0][0], arr[0][2]);
        prev[2] = max(arr[0][0], arr[0][1]);

        for (int i = 1; i < n; i++)
        {
            for (int last = 0; last < 3; last++)
            {
                int maxm = 0;
                for (int j = 0; j < 3; j++)
                {
                    if (j != last)
                    {
                        maxm = max(maxm, arr[i][j] + prev[j]);
                    }
                }
                curr[last] = maxm;
            }
            prev[0] = curr[0];
            prev[1] = curr[1];
            prev[2] = curr[2];
        }

        return max(prev[0], max(prev[1], prev[2]));
    }

    //     // Function to find the maximum points for ninja training
    // int ninjaTraining(int n, vector<vector<int>>& points) {
    //   // Initialize a vector to store the maximum points for the previous day's activities
    //   vector<int> prev(4, 0);

    //   // Initialize the DP table for the first day (day 0)
    //   prev[0] = max(points[0][1], points[0][2]);
    //   prev[1] = max(points[0][0], points[0][2]);
    //   prev[2] = max(points[0][0], points[0][1]);
    //   prev[3] = max(points[0][0], max(points[0][1], points[0][2]));

    //   // Iterate through the days starting from day 1
    //   for (int day = 1; day < n; day++) {
    //     // Create a temporary vector to store the maximum points for the current day's activities
    //     vector<int> temp(4, 0);
    //     for (int last = 0; last < 4; last++) {
    //       temp[last] = 0;
    //       // Iterate through the tasks for the current day
    //       for (int task = 0; task <= 2; task++) {
    //         if (task != last) {
    //           // Calculate the points for the current activity and add it to the
    //           // maximum points obtained on the previous day (stored in prev)
    //           temp[last] = max(temp[last], points[day][task] + prev[task]);
    //         }
    //       }
    //     }
    //     // Update prev with the maximum points for the current day
    //     prev = temp;
    //   }

    //   // The maximum points for the last day with any activity can be found in prev[3]
    //   return prev[3];
    // }

    // int maximumPoints(vector<vector<int>>& arr, int n) {
    //     // Code here
    //     // if(n == 1) return max(arr[0], max(arr[1], arr[2]));
    //     vector<vector<int>> dp(n+1, (vector<int>(3,-1)));

    //     dp[0][0] = max(arr[0][1], arr[0][2]);
    //     dp[0][1] = max(arr[0][0], arr[0][2]);
    //     dp[0][2] = max(arr[0][0], arr[0][1]);

    //     for(int i=1; i<n; i++){
    //         for(int last=0; last <3; last++) {
    //             int maxm = 0;
    //             for(int j = 0; j<3; j++) {
    //                 if(j!=last){
    //                     maxm = max(maxm, arr[i][j] + dp[i-1][j]);
    //                 }
    //             }
    //             dp[i][last] = maxm;
    //         }
    //     }

    //     return max(dp[n-1][0], max(dp[n-1][1], dp[n-1][2]));
    // }

    // int solve(vector<vector<int>>&arr, vector<vector<int>>&dp, int i, int last){
    //     if(dp[i][last] != -1) return dp[i][last];
    //     if(i==0) {
    //         int maxm = 0;
    //         for(int j=0; j<=2; j++){
    //             if(j!=last){
    //                 maxm = max(maxm, arr[i][j]);
    //             }
    //         }
    //         // cout<<"==i "<<i<<"last "<<last<<"maxm "<<maxm<<endl;
    //         return maxm;
    //     }
    //     int maxm = 0;
    //     for(int j=0; j<=2; j++){
    //         if(j!=last){
    //             maxm = max(maxm, arr[i][j] + solve(arr, dp, i-1, j));
    //         }
    //     }
    //     dp[i][last] = maxm;
    //     // cout<<"==i "<<i<<"last "<<last<<"maxm "<<maxm<<endl;
    //     return maxm;
    // }

    // int maximumPoints(vector<vector<int>>& arr, int n) {
    //     // Code here
    //     // if(n == 1) return max(arr[0], max(arr[1], arr[2]));

    //     // vector<vector<int>> dp(n+1, (vector<int>(3,-1)));

    //     // int max0 = solve(arr, dp, n-1, 0);
    //     // int max1 = solve(arr, dp, n-1, 1);
    //     // int max2 = solve(arr, dp, n-1, 2);

    //     // return max(max0, max(max1, max2));

    //     vector<vector<int>> dp(n+1, (vector<int>(4,-1)));
    //     return solve(arr, dp, n-1, 3);
    // }

    // 1 2 5
    // 3 1 1
    // 3 3 3

    //
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
        vector<vector<int>> arr;
        for (int i = 0; i < n; ++i)
        {
            vector<int> temp;
            for (int j = 0; j < 3; ++j)
            {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            arr.push_back(temp);
        }

        Solution obj;
        cout << obj.maximumPoints(arr, n) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends