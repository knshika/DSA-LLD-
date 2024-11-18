#include <bits/stdc++.h>
using namespace std;

void createsubsets(int i, string str, string &s)
{
    if (i >= s.length())
    {
        cout << str << " ";
        cout << endl;
        return;
    }

    str += s[i];
    createsubsets(i + 1, str, s);
    str = str.erase(str.size() - 1);
    createsubsets(i + 1, str, s);
}

int main()
{
    string s = "abc";
    // vector of strings to store all sub-sequences
    createsubsets(0, "", s);
    return 0;
}

// https://www.geeksforgeeks.org/print-subsequences-string/