//
// Created by yjs on 23-3-28.
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


class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        unsigned long long res = 1;
        vector<pair<TreeNode * , unsigned long long>> ans;
        ans.emplace_back(root,1L);
        while(!ans.empty()){

            vector<pair<TreeNode * , unsigned long long>> tmp;
            for(auto &[node, count] : ans){
                if(node->left!=nullptr){
                    tmp.emplace_back(node->left, 2*count);
                }
                if(node->right!=nullptr){

                    tmp.emplace_back(node->right, 2*count+1);
                }
            }
            res=max(res,ans.back().second-ans[0].second+1);
            ans=move(tmp);
        }
        return res;
    }
};



int widthOfBinaryTree(TreeNode * root){
    if(root== nullptr) return  0;

    queue<TreeNode * >queue1;
    queue1.push(root);
    unordered_map<TreeNode * ,int> levelMap;
    levelMap[root]=1;
    int curLevel=1;      // 当前所在的层数
    int curLevelNodes=0; // 当前level 发现了几个节点
    int curLevelMax=-1;


    while(!queue1.empty()){
        TreeNode * node=queue1.front();
        queue1.pop();

        int curNodeLevel=levelMap[node]; // 当前节点所在层
        if(curNodeLevel==curLevel){
            curLevelNodes++;
        }else{

            curLevelMax=max(curLevelMax,curLevelNodes);
            curLevel++;
            curLevelNodes=1;
        }


        // print

        if(node->left!= nullptr){

            levelMap[node->left]=curNodeLevel+1;
            queue1.push(node->left);
        }
        if(node->right!= nullptr) {
            levelMap[node->right]=curNodeLevel+1;

            queue1.push(node->right);
        }




    }
    return  curLevelMax;




}
