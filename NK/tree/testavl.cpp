//
// Created by yjs on 2022/10/29.
//

#include <iostream>
#include <queue>


using namespace std;


struct node {
    int data;
    int height;
    node *left;
    node *right;

    node(int data) {
        this->data = data;
        this->height = 0;
        this->left = nullptr;
        this->right = nullptr;
    }
};

int height(node *root) {
    if (root == nullptr) {
        return 0;
    }
    return 1 + max(height(root->left), height(root->right));
}

int balance(node *root) {

    return height(root->left) - height(root->right);
}

// RR
node *leftRotate(node *root) {
    node *t = root->right;
    node *u = t->left;
    t->left = root;
    root->right = u;
    return t;
}


node *rightRotate(node *root) {
    node *t = root->left;
    node *u = t->right;
    t->right = root;
    root->left = u;
    return t;
}


node * insert(node *root,int data) {
    node *nn = new node(data);
    if (root == nullptr) return nn;
    if (data < root->data)
        root->left = insert(root->left, data);
    else
        root->right = insert(root->right, data);
    // data== root->data
    int b = balance(root);
    if (b > 1) {
        // L
        if (balance(root->left) < 0)
            // LR
            root->left = leftRotate(root->left);
        // LL
        return rightRotate(root);
    } else if (b < -1) {
        // R
        if (balance(root->right) > 0)
            // RL
            root->right = rightRotate(root->right);
        // RR
        return leftRotate(root);


    }
    return root;
}


node *getminNode(node *root) {
    while (root->left != nullptr)
        root = root->left;
    return root;
}


node *deleteNode(node *root, int key) {
    if (root == nullptr) {
        return root;
    } else if (key < root->data) {

        root->left = deleteNode(root->left, key);


    } else if (key > root->data) {

        root->right = deleteNode(root->right, key);
    } else {
        // delete node

        if (root->left == nullptr) {
            node *tmp = root->right;
            delete (root);
            root = nullptr;
            return tmp;
        } else if (root->right == nullptr) {
            node *tmp = root->left;
            delete (root);
            root = nullptr;
            return tmp;
        }

        node *tmp = getminNode(root->right);

        root->data=tmp->data;
        root->right= deleteNode(root->right,tmp->data);
    }
    return root;
}


void levelOrder(node *root) {
    std::queue<node *> q;
    q.push(root);
    while (!q.empty()) {
        root = q.front();
        std::cout << root->data << " ";
        q.pop();
        if (root->left)
            q.push(root->left);
        if (root->right)
            q.push(root->right);
    }
}


int main() {
    // Testing AVL Tree
    node *root = NULL;
    int i;
    for (i = 1; i <= 7; i++) root = insert(root, i);
    std::cout << "LevelOrder: ";
    levelOrder(root);
    root = deleteNode(root, 1);  // Deleting key with value 1
    std::cout << "\nLevelOrder: ";
    levelOrder(root);
    root = deleteNode(root, 4);  // Deletin key with value 4
    std::cout << "\nLevelOrder: ";
    levelOrder(root);
    return 0;
}

//LevelOrder: 4 2 6 1 3 5 7
//LevelOrder: 4 2 6 3 5 7
//LevelOrder: 5 2 6 3 7
//进程已结束,退出代码0


