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
    if(head== nullptr){
        return nullptr;
    }
    ListNode * cur=head;
    ListNode * nextNode= nullptr;

    while (cur!= nullptr){
        nextNode=cur->next;
        cur->next=new ListNode(cur->val);
        cur->next->next=nextNode;
        cur=nextNode;
    }
    // 1  - 1'  - 2  - 2' - 3  - 3'
    cur=head;
    ListNode  * copyHead= head->next;

    // set copy node rand
    // 1 -  1' -  2 - 2' - 3  - 3'
    while (cur!= nullptr){
        nextNode=cur->next->next;
        copyHead=cur->next;
        cur->next=nextNode;
        copyHead->next= nextNode== nullptr ? nullptr:nextNode->next;
        cur=nextNode;
    }

    return copyHead;














}