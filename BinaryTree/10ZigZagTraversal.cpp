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
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        vector<vector<int>> ans;
        queue<TreeNode *> que;
        if (root == NULL)
            return ans;
        que.push(root);   // que for level order traversal
        bool flagltr = 1; // flag for ltr and rtl traversal
        while (!que.empty())
        {
            int size = que.size();
            vector<int> temp(size); // temp vector for ltr and rtl element storage
            for (int i = 0; i < size; i++)
            {
                TreeNode *curr = que.front();
                que.pop();
                // we need to push element based on flag
                int idx = (flagltr) ? i : size - i - 1;
                temp[idx] = curr->val;
                if (curr->left)
                    que.push(curr->left);
                if (curr->right)
                    que.push(curr->right);
            }
            ans.push_back(temp);
            flagltr = !flagltr;
        }
        return ans;
    }
};
