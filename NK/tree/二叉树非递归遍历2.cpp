//
// Created by yjs on 2022/4/28.
//
#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};



// preorderTraversal is the DFS of the tree
vector<int> preorderTraversal(TreeNode* root) {
    vector<int> res;
    if(root==nullptr) return res;
    stack<TreeNode * > stk;
    stk.push(root);
    while(!stk.empty()){
        root=stk.top();
        stk.pop();
        res.push_back(root->val);
        if(root->right!=nullptr) stk.push(root->right);
        if(root->left!=nullptr) stk.push(root->left);
    }
    return res;
}



vector<int> postorderTraversal(TreeNode* root) {
    vector<int> res;
    if(root==nullptr) return res;
    stack<TreeNode *> stk;
    stk.push(root);


    while(!stk.empty()){
        root=stk.top();
        stk.pop();
        res.insert(res.begin(), root->val);
        if(root-> left !=nullptr ) stk.push(root->left);
        if(root-> right !=nullptr ) stk.push(root->right);

    }

    return res;

}



vector<int> inorderTraversal(TreeNode* root) {
    vector<int>res;
    if(root== nullptr) return res;

    stack<TreeNode* >stk;
    while(!stk.empty() || root !=nullptr){

        while(root!=nullptr){

            stk.push(root);
            root=root->left;
        }

        root=stk.top();
        stk.pop();

        res.push_back(root->val);

        root=root->right;
    }
    return res;
}

