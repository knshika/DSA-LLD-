#include <bits/stdc++.h>
using namespace std;

// int solve(int i, bool tookLast, vector<int>&nums, vector<int> &dp) {
// 		if(i==0) return ((tookLast) ? 0 : nums[0]);
// 		if(i<0) return 0;
// 		if(dp[i] != -1) return dp[i];

// 		int pick = nums[i] + solve(i-2, tookLast, nums, dp);
// 		int notPick = 0 + solve(i-1, tookLast, nums, dp);

// 		dp[i] = max(pick, notPick);
// 		return dp[i];
// 	}

// 	int rob(vector<int>& nums) {
//         int n = nums.size();
// 		if(n==1) return nums[0];
// 		vector<int> dp1(n+1, -1);
// 		int ans1 = solve(n-2, false, nums, dp1);
//         vector<int> dp2(n+1, -1);
//         int ans2 = solve(n-1, true, nums, dp2);
// 		return max(ans1, ans2);
//     }

// int solve(int start, int end, vector<int> &nums, vector<int> &dp) {
//     int pick =0, notPick =0;
//     for(int i=start; i<=end; i++) {
//         pick = (i<2) ? nums[i] : (nums[i] + dp[i-2]);
//         notPick = (i<1) ? 0: (0 + dp[i-1]);
//         // cout<<"i "<<i<<" pick "<<pick<<" notPick "<<notPick<<endl;
//         dp[i] = max(pick, notPick);
//     }
//     return dp[end];
// }

// int rob(vector<int>& nums) {
//     int n = nums.size();
// 	if(n==1) return nums[0];
//     vector<int> dp1(n+1, -1);
//     dp1[0] = nums[0];
// 	int ans1 = solve(0, n-2, nums, dp1);
//     vector<int> dp2(n+1, -1);
//     dp2[0] = 0;
//     int ans2 = solve(1, n-1, nums, dp2);
// 	return max(ans1, ans2);
// }

int solve(int start, int end, vector<int> &nums)
{
    int prev2 = 0, prev1 = 0;
    for (int i = start; i <= end; i++)
    {
        int pick = nums[i] + prev2;
        int notPick = 0 + prev1;
        // cout<<"i "<<i<<" pick "<<pick<<" notPick "<<notPick<<endl;
        int curr = max(pick, notPick);
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}

int rob(vector<int> &nums)
{
    int n = nums.size();
    if (n == 1)
        return nums[0];

    int ans1 = solve(0, n - 2, nums);
    int ans2 = solve(1, n - 1, nums);

    return max(ans1, ans2);
}

void main()
{
    vector<int> nums = {2, 4, 9, 1, 2};
    cout << rob(nums);
    return;
}