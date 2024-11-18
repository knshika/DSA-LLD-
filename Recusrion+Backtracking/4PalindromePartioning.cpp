#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isPalindrome(string &str, int start, int end)
    {
        // int start = 0, end = str.size()-1;
        while (start <= end)
        {
            if (str[start++] != str[end--])
                return false; // it was giving wrong answer when start and end was not changed
        }
        return true;
    }

    void solve(int idx, string &s, vector<string> &temp, vector<vector<string>> &ans)
    {
        if (idx == s.size())
        {
            ans.push_back(temp);
            return;
        }
        for (int i = idx; i < s.size(); i++)
        {
            if (isPalindrome(s, idx, i))
            {                                               // (index, no of letters)
                temp.push_back(s.substr(idx, i - idx + 1)); // push substring
                solve(i + 1, s, temp, ans);
                temp.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s)
    {
        vector<vector<string>> ans;
        vector<string> temp;
        int n = s.size();
        solve(0, s, temp, ans);
        return ans;
    }
};