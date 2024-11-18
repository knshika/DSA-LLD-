#include <bits/stdc++.h>
using namespace std;

//  Definition for a binary tree node.
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
    void solve(TreeNode *root, vector<int> &ans)
    {
        if (root == NULL)
            return;
        solve(root->left, ans);
        ans.push_back(root->val);
        solve(root->right, ans);
    }

    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> ans;
        solve(root, ans);
        return ans;
    }

    //     //reverse of level order
    // vector<int> postorderTraversal(TreeNode* root) {
    //     vector<int> ans;
    //     if(root == NULL) return ans;
    //     // solve(root, ans);
    //     stack<TreeNode*> q, st; //remeber stack LIFO
    //     q.push(root);
    //     while(!q.empty()){
    //         TreeNode * curr = q.top();
    //         q.pop();
    //         st.push(curr);
    //         if(curr->left){
    //             q.push(curr->left);
    //         }
    //         if(curr->right){
    //             q.push(curr->right);
    //         }
    //     }
    //     while(!st.empty()){
    //         ans.push_back(st.top()->val);
    //         st.pop();
    //     }
    //     return ans;
    // }
};