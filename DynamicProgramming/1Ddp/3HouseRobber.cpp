#include <bits/stdc++.h>
using namespace std;

// int solve(int i, vector<int> &nums, vector<int> &dp) {
//     if(i < 0) return 0;
//     if(dp[i] != -1) return dp[i];
//     int pick = nums[i] + solve(i-2, nums, dp);
//     int notPick = 0 + solve(i-1, nums, dp);
//     dp[i] = max(pick, notPick);
//     return dp[i];
// }

// int rob(vector<int>& nums) {
//     int n = nums.size();
//     if(n==1) return nums[0];
//     vector<int>dp(n+1, -1);
//     solve(n-1, nums, dp);
//     return dp[n-1];
// }
//  2 7 9 3 1

int rob(vector<int> &nums)
{
    int n = nums.size();
    if (n == 1)
        return nums[0];
    // vector<int>dp(n+1, -1);
    // dp[0] = nums[0];
    // for(int i=1; i<n; i++){
    //     int pick = (i<=1) ? nums[i] : (nums[i] + dp[i-2]);
    //     int notPick = 0 + dp[i-1];
    //     dp[i] = max(pick, notPick);
    // }
    // return dp[n-1];
    int prev2 = 0;       //-1
    int prev1 = nums[0]; // 0
    for (int i = 1; i < n; i++)
    {
        int pick = nums[i] + prev2;
        int notPick = 0 + prev1;
        int cur = max(pick, notPick);
        prev2 = prev1;
        prev1 = cur;
    }
    return prev1;
}

void main()
{
    vector<int> nums = {2, 4, 9, 1, 2};
    cout << rob(nums);
    return;
}