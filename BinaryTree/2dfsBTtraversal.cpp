#include <bits/stdc++.h>
using namespace std;

// Following is Binary Tree Node structure:
class TreeNode
{
public:
    int data;
    TreeNode *left, *right;
    TreeNode() : data(0), left(NULL), right(NULL) {}
    TreeNode(int x) : data(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
};

void solve(TreeNode *root, vector<int> &inorder, vector<int> &preorder, vector<int> &postorder)
{
    if (root == NULL)
        return;
    preorder.push_back(root->data);
    solve(root->left, inorder, preorder, postorder);
    inorder.push_back(root->data);
    solve(root->right, inorder, preorder, postorder);
    postorder.push_back(root->data);
}

vector<vector<int>> getTreeTraversal(TreeNode *root)
{
    // Write your code here.
    // vector<int> preorder, inorder, postorder;
    // stack<TreeNode*,int> st;
    // if(root == null) return;
    // st.push({root,1});
    // while(!st.empty()){
    //     auto itr = st.top();
    //     st.pop();//we used it, we will insert again
    //     if(itr.second == 1){
    //         preorder.push_back(itr.first->val);
    //         st.push({itr.first , 2});
    //         if(itr.first -> left)
    //             st.push({itr.first->left,1});

    //     } else if (itr.second == 2){
    //         inorder.push_back(itr.first->val);
    //         st.push({itr.first , 3});
    //         if(itr.first -> right)
    //             st.push({itr.first->right,1});
    //     }else {
    //         postorder.push_back(itr.first->val);
    //     }
    // }
    vector<int> inorder;
    vector<int> preorder;
    vector<int> postorder;
    solve(root, inorder, preorder, postorder);
    vector<vector<int>> ans;
    ans.push_back(inorder);
    ans.push_back(preorder);
    ans.push_back(postorder);
    return ans;
}