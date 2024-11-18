// Iterative C++ program to print sums of all
// Given an array of integers, print sums of all subsets in it.
// possible subsets.
#include <bits/stdc++.h>
using namespace std;

// Prints sums of all subsets of array
void subsetSums(int i, int arr[], int n, vector<int> &ans, int sum)
{
    if (i == n)
    {
        ans.push_back(sum);
        return;
    }
    subsetSums(i + 1, arr, n, ans, sum + arr[i]);
    subsetSums(i + 1, arr, n, ans, sum);
}

// Driver code
int main()
{
    int arr[] = {5, 4, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    vector<int> ans;
    vector<int> temp;
    subsetSums(0, arr, n, ans, 0);
    sort(ans.begin(), ans.end());
    for (auto i : ans)
        cout << i << " ";
    return 0;
}
