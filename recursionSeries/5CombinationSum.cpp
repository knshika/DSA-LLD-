// find all unique combinations in arr[] where the sum is equal to x. The same repeated number may be chosen from arr[] an unlimited number of times.
// Input: arr[] = 2, 4, 6, 8, x = 8
// Output:
// [2, 2, 2, 2]
// [2, 2, 4]
// [2, 6]
// [4, 4]
// [8]

// leetcode

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void findCombSum(int i, int target, vector<int> &arr, vector<int> temp, vector<vector<int>> &res)
    {
        if (i == arr.size())
        {
            if (target == 0)
            {
                res.push_back(temp);
            }
            return;
        }
        if (target >= arr[i])
        {
            temp.push_back(arr[i]);
            findCombSum(i, target - arr[i], arr, temp, res);
            temp.pop_back();
        }
        findCombSum(i + 1, target, arr, temp, res);
    }

    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<vector<int>> res;
        vector<int> temp;
        findCombSum(0, target, candidates, temp, res);
        return res;
    }
};