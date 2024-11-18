#include <iostream>
#include <vector>
using namespace std;

int subsetSum(int i, int arr[], vector<int> &out, int length, int sum, int k)
{
    if (i >= length)
    {
        if (sum == 0)
        {
            return 1;
        }
        return 0;
    }

    out.push_back(arr[i]);
    int left = subsetSum(i + 1, arr, out, length, sum - arr[i], k); // Move to the next index
    out.pop_back();
    int right = subsetSum(i + 1, arr, out, length, sum, k); // Move to the next index
    return left + right;
}

int main()
{
    int arr[] = {5, 12, 3, 17, 1, 18, 15, 3, 17};
    int length = 9;
    int k = 6;
    vector<int> output;
    cout << subsetSum(0, arr, output, length, k, k);
    return 0;
}
