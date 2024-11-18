// Input: array[] = [1,2,2]
// Output: [ [ ],[1],[1,2],[1,2,2],[2],[2,2] ]

// Explanation: We can have subsets ranging from  length 0 to 3. which are listed above. Also the subset [1,2] appears twice
// but is printed only once as we require only unique subsets

#include <bits/stdc++.h>
using namespace std;

// Prints sums of all subsets of array
void subset(int i, int arr[], int n, vector<vector<int>> &ans, vector<int> temp)
{
    if (i == n)
    {
        ans.push_back(temp);
        return;
    }
    temp.push_back(arr[i]);
    subset(i + 1, arr, n, ans, temp);
    temp.pop_back();
    subset(i + 1, arr, n, ans, temp);
}

// Driver code
int main()
{
    int arr[] = {1, 2, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    vector<vector<int>> ans;
    vector<int> temp;
    subset(0, arr, n, ans, temp);
    for (auto i : ans)
    {
        cout << "[";
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << "]";
    }

    return 0;
}