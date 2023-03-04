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

// need n/2 extra space
bool isPalindrome2(ListNode *head) {
    if (head == nullptr || head->next == nullptr) {
        return true;
    }

    // find mid of the list
    ListNode *fast = head->next;
    ListNode *slow = head;
    while (fast != nullptr && slow->next != nullptr) {
        fast = fast->next->next;
        slow = slow->next;
    }

    // slow is the mid of the list


    stack <ListNode * > stackLists;
    // slow 后面的节点入stack
    while (slow != nullptr) {
        stackLists.push(slow);
        slow=slow->next;
    }
    while (!stackLists.empty()) {
        int stackTop =stackLists.top()->val;
        stackLists.pop();
        if (head->val != stackTop) {
            return false;
        }
        head = head->next;
    }
    return true;
}
