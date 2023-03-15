//
// Created by yjs on 23-3-15.
// 将单向链表按某值划分成左边小、中间相等、右边大的形式
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


ListNode *listPartition(ListNode *head, int pivot) {
    ListNode *sH = nullptr;  // small head
    ListNode *sT = nullptr;  // small tail

    ListNode *eH = nullptr; // equal head
    ListNode *eT = nullptr;  // equal tail

    ListNode *bH = nullptr;  // big head
    ListNode *bT = nullptr;  // big tail

    ListNode *newCurNode = nullptr;

    while (head != nullptr) {
        newCurNode = head->next;
        if (head->val < pivot) {
            if (sH == nullptr) {
                sH = head;
                sT = head;
            } else {
                // tail insert
                sT->next = head;
                sT = head;
            }
        } else if (head->val == pivot) {
            if (eH == nullptr) {
                eH = head;
                eT = head;
            } else {
                eT->next = head;
                eT = head;
            }
        } else if (head->val > pivot) {
            if (bH == nullptr) {
                bH = head;
                bT = head;
            } else {
                bT->next = head;
                bT = head;
            }
        }

        head = newCurNode;


    }

    // link

    if (sT != nullptr) {
        sT->next = eH;
        eT = eT == nullptr ? sT : eT;
    }
    if (eT != nullptr) {
        eT->next = bT;
    }

    return sH != nullptr ? sH : eH != nullptr ? eT : bT;


}


int main() {


    return 0;
}