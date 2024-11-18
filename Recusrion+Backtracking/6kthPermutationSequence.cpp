#include <iostream>
#include <string>

using namespace std;

class Solution
{
public:
    string getPermutation(int n, int k)
    {
        int fac = 1;
        string str = "";
        string ans = "";

        // Calculate factorial of (n-1) and initialize the string
        for (int i = 1; i <= n; ++i)
        {
            fac *= i;
            str += to_string(i);
        }
        // str += to_string(n); // Add the nth element

        // Convert k to zero-based index
        k -= 1;

        while (n > 0)
        {
            fac /= n; // Update fac for current n
            int idx = k / fac;
            ans += str[idx];
            str.erase(str.begin() + idx);

            k %= fac;
            n--;
        }

        return ans;
    }
};

int main()
{
    Solution sol;
    cout << sol.getPermutation(4, 17) << endl; // Output: "3412"
    return 0;
}
