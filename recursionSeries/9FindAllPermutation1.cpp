#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // we can use another temp vector or modify same nums

    void solve(int n, int mask[], vector<int> nums, vector<int> temp, vector<vector<int>> &ans)
    {
        if (temp.size() == n)
        {
            ans.push_back(temp);
            return;
        }
        for (int i = 0; i < n; i++)
        {
            if (mask[i] == 0)
            {
                temp.push_back(nums[i]);
                mask[i] = 1;
                solve(n, mask, nums, temp, ans);
                mask[i] = 0;
                temp.pop_back();
            }
        }
    }

    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> ans;
        vector<int> temp;
        int n = nums.size();
        int mask[n];
        for (int i = 0; i < n; i++)
        {
            mask[i] = 0;
        }
        solve(n, mask, nums, temp, ans);
        return ans;
    }
};