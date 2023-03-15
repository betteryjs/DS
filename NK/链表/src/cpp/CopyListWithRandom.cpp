//
// Created by yjs on 23-3-15.
// 复制含有随机指针节点的链表
//
#include <iostream>
#include <unordered_map>


using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode *rand;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


ListNode *copyListWithRandMap(ListNode *head) {
    unordered_map < ListNode * , ListNode * > ListNodeMap;
    ListNode *cur = head;
    while (cur != nullptr) {
        ListNodeMap.emplace({cur, new ListNode(cur->val)});
        cur = cur->next;
    }
    cur = head;
    while (cur != nullptr) {
        ListNodeMap.at(cur)->next = ListNodeMap.at(cur->next);
        ListNodeMap.at(cur)->rand = ListNodeMap.at(cur->rand);
        cur = cur->next;
    }
    return ListNodeMap.at(head);
}


ListNode *copyListWithRand(ListNode *head) {






}