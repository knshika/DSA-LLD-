// Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.
// Each number in candidates may only be used once in the combination.
// Note: The solution set must not contain duplicate combinations.

// Input: candidates = [10,1,2,7,6,1,5], target = 8
// Output: [[1,1,6],[1,2,5],[1,7],[2,6]]

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void findComb(int idx, int n, vector<int> arr, int k, vector<vector<int>> &ans, vector<int> comb)
    {
        // if(idx==n){ // below iteration
        if (k == 0)
        {
            ans.push_back(comb);
            return;
        }
        //}
        for (int i = idx; i < n; i++)
        {
            if (i > idx && arr[i] == arr[i - 1])
                continue;
            if (arr[i] > k)
                break; // sorted
            comb.push_back(arr[i]);
            findComb(i + 1, n, arr, k - arr[i], ans, comb);
            comb.pop_back();

            // findComb(i+1, n, arr, k, ans, comb);
        }
    }

    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        vector<vector<int>> out;
        vector<int> comb;
        int n = candidates.size();
        sort(candidates.begin(), candidates.end());
        findComb(0, n, candidates, target, out, comb);
        return out;
    }
};