//
// Created by yjs on 23-4-12.
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


namespace BST1 {
    bool isValidBST(TreeNode *root);

    bool isValidBST(TreeNode *root, TreeNode *min, TreeNode *max);

    bool isValidBST(TreeNode *root) {
        return isValidBST(root, nullptr, nullptr);
    }


    bool isValidBST(TreeNode *root, TreeNode *min, TreeNode *max) {

        if (root == nullptr) {
            return true;
        }
        // 若 root.val 不符合 max 和 min 的限制，说明不是合法 BST
        if (min != nullptr && root->val <= min->val) return false;
        if (max != nullptr && root->val >= max->val) return false;
        // 限定左子树的最大值是 root.val，右子树的最小值是 root.val
        return isValidBST(root->left, min, root) && isValidBST(root->right, root, max);

    }


}
namespace BST2 {

    int preVal = INT_MIN;

    bool isBst(TreeNode *root) {
        if (root == nullptr) return true;
        bool isLeftBst = isBst(root->left);
        if (!isLeftBst) return false;
        // check right tree
        if (root->val <= preVal) {
            return false;
        } else {
            preVal = root->val;
        }
        return isBst(root->right);
    }


    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> res;
        if (root == nullptr) return res;

        stack<TreeNode *> stk;
        while (!stk.empty() || root != nullptr) {

            while (root != nullptr) {

                stk.push(root);
                root = root->left;
            }

            root = stk.top();
            stk.pop();

            res.push_back(root->val);

            root = root->right;
        }
        return res;
    }


}

