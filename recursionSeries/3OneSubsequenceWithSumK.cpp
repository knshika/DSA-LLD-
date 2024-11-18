#include <iostream>
#include <vector>
using namespace std;

void printOut(const vector<int> &out)
{
    for (auto i : out)
    {
        cout << i << " ";
    }
    cout << endl;
}

bool subsetSum(int i, int arr[], vector<int> &out, int length, int sum, int k)
{
    if (i >= length)
    {
        if (sum == 0)
        {
            printOut(out);
            return true;
        }
        return false;
    }

    out.push_back(arr[i]);
    if (subsetSum(i + 1, arr, out, length, sum - arr[i], k))
        return true; // Move to the next index
    out.pop_back();
    if (subsetSum(i + 1, arr, out, length, sum, k))
        return true; // Move to the next index
    return false;
}

int main()
{
    int arr[] = {5, 12, 3, 17, 1, 18, 15, 3, 17};
    int length = 9;
    int k = 6;
    vector<int> output;
    subsetSum(0, arr, output, length, k, k);
    return 0;
}
