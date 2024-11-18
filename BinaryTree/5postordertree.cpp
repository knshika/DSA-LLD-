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
    void solve(TreeNode *root, vector<int> &ans)
    {
        if (root == NULL)
            return;
        solve(root->left, ans);
        solve(root->right, ans);
        ans.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode *root)
    {
        vector<int> ans;
        //         if(root == NULL) return ans;
        // stack<TreeNode*> st;
        // TreeNode* lastVis = nullptr;
        // TreeNode* temp;
        // TreeNode* cur  = root;

        // //st.push(root);
        // while(cur != NULL || !st.empty()) {
        //     // goo all left
        //     if(cur) { // if left available
        //         st.push(cur);
        //         cur = cur -> left;
        //     }else{
        //         temp = st.top(); //goo all right
        //         if(temp->right && temp->right != lastVis){
        //             cur = temp->right;
        //         }else{
        //             st.pop();
        //             ans.push_back(temp->val);
        //             lastVis = temp;
        //         }
        solve(root, ans);
        return ans;
    }
};