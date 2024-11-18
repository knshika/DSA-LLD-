#include <bits/stdc++.h>
using namespace std;

//   Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    int maxDepth(TreeNode *root)
    {
        if (root == NULL)
            return 0;
        // if(root->left) we dont need as we are already chceking in base case
        int left = 1 + maxDepth(root->left);
        // if(root->right)
        int right = 1 + maxDepth(root->right);

        int maxdepth = max(left, right);
        return maxdepth; // cant return value of max,
    }
};