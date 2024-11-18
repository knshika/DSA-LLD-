#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/permutations/submissions/1294715983/

class Solution
{
public:
    // we can use another temp vector or modify same nums

    void solve(int idx, vector<int> &nums, vector<vector<int>> &ans)
    {
        if (idx == nums.size())
        { // idx is current fixed position
            ans.push_back(nums);
            return;
        }
        for (int i = idx; i < nums.size(); i++)
        {
            swap(nums[i], nums[idx]);  // swapping current position with fix position
            solve(idx + 1, nums, ans); // pasing next fixed position
            swap(nums[i], nums[idx]);
        }
    }

    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> ans;
        solve(0, nums, ans);
        return ans;
    }
};