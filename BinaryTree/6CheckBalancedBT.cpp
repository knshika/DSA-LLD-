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
    // int findHeight(TreeNode *node)
    // {
    //     if (node == NULL)
    //         return 0;
    //     int left = findHeight(node->left);
    //     int right = findHeight(node->right);
    //     return 1 + max(left, right);
    // }

    // bool isBalanced(TreeNode *root)
    // {
    //     if (root == NULL)
    //         return true;

    //     int left = findHeight(root->left);
    //     int right = findHeight(root->right);

    //     if (abs(left - right) > 1)
    //         return false;
    //     // case -> height from left and right of root node is same but still its not balanced [1,2,2,3,null,null,3,4,null,null,4]

    //     bool isLeft = isBalanced(root->left); // extra complexity , use only findHeight
    //     bool isRight = isBalanced(root->right);

    //     if (!isLeft || !isRight)
    //         return false; // its false if any of node is not balanced
    //     return true;
    // }

    int findHeight(TreeNode *node)
    {
        if (node == NULL)
            return 0;
        int lh = findHeight(node->left);
        int rh = findHeight(node->right);
        if (lh == -1 || rh == -1)
            return -1;
        if (abs(lh - rh) > 1)
            return -1;
        return 1 + max(lh, rh);
    }

    bool isBalanced(TreeNode *root)
    {
        if (root == NULL)
            return true;
        int ans = findHeight(root);
        if (ans == -1)
            return false;
        else
            return true;
    }
};