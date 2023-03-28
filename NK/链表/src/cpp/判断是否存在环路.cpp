//
// Created by yjs on 2022/5/14.
//

#include <iostream>

using namespace std;

#include <vector>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// @solution-sync:begin
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head== nullptr || head->next== nullptr || head->next->next== nullptr) {
            return nullptr;
        }
        ListNode* slow=head->next;
        ListNode* fast=head->next->next;
        // 判断是否存在环路
        while (slow!=fast){
            if(fast->next== nullptr || fast->next->next== nullptr){
                // 没有环路
                return nullptr;

            }
            fast=fast->next->next;
            slow=slow->next;
        }
        // fast 记录fast=slow时的node节点
        // 如果存在，查找环路节点
        fast=head;
        while (fast!=slow) {
            slow = slow->next;
            fast = fast->next;
        }
        return fast;
    }
};







