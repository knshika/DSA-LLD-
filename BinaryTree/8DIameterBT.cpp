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
    int findDiameter(TreeNode *node, int &ans)
    {
        if (node == NULL)
            return 0;                            // for leaf node
        int lh = findDiameter(node->left, ans);  // find height from left child
        int rh = findDiameter(node->right, ans); // find height from right child
        ans = max(ans, lh + rh);                 // update ans in case any node have max lh+rh
        return 1 + max(lh, rh);                  // return max height from lh or rh to parent
    }

    int diameterOfBinaryTree(TreeNode *root)
    {
        if (root == NULL)
            return 0;
        int ans = 0; // initialisation is importand in leetcode as it uses same variable
        findDiameter(root, ans);
        return ans;
    }
};