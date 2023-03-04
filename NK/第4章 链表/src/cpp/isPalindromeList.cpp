//
// Created by yjs on 23-3-4.
// 判断一个链表是否为回文结构
//
#include <iostream>
#include <stack>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// need n extra space
bool isPalindrome1(ListNode *head) {
    stack<ListNode *> stack;
    ListNode *cur = head;
    while (cur != nullptr) {
        stack.push(cur);
        cur = cur->next;
    }
    while (head != nullptr) {
        int stackpop = stack.top()->val;
        stack.pop();
        if (head->val != stackpop) {
            return false;
        }
        head = head->next;
    }
    return true;
}

