//
// Created by yjs on 23-3-4.
//
#include <iostream>


using namespace std;


struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


struct DoubleNode {
    int value;
    DoubleNode *last;
    DoubleNode *next;

    DoubleNode(int data) : value(data) {}
};

ListNode *reverseList(ListNode *head) {
    ListNode *pre = nullptr;
    ListNode *cur = head;
    while (cur != nullptr) {
        ListNode *nextCur = cur->next;
        cur->next = pre;
        pre = cur;
        cur = nextCur;
    }
    return pre;
}


ListNode *reverseListAtoB(ListNode *head, ListNode *end) {
    ListNode *pre = nullptr;
    ListNode *cur = head;
    while (cur != end) {
        ListNode *nextCur = cur->next;
        cur->next = pre;
        pre = cur;
        cur = nextCur;
    }
    return pre;
}




DoubleNode * reverseDoubleList(DoubleNode*  head) {
    DoubleNode*  pre = nullptr;
    DoubleNode* nextCur = nullptr;
    DoubleNode * cur=head;
    while (cur != nullptr) {
        nextCur = cur->next;
        cur->next = pre;
        cur->last = nextCur;
        pre = cur;
        cur = nextCur;
    }
    return pre;
}





