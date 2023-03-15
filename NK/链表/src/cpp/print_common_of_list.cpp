//
// Created by yjs on 23-3-4.
// 打印两个有序链表的公共部分
//


#include <iostream>
#include <vector>


using namespace std;


struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void printCommonPart(ListNode *head1, ListNode *head2) {
    while (head1 != nullptr && head2 != nullptr) {
        if (head1->val < head2->val) {
            head1 = head1->next;
        } else if (head1->val > head2->val) {
            head2 = head2->next;
        } else {
            // head1->val == head2->val
            cout << head1->val << " ";
            head1 = head1->next;
            head2 = head2->next;
        }
    }
}