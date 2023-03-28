//
// Created by yjs on 23-3-25.
// 给定两个可能有环也可能无环的单链表，头节点head1和head2。请实
//现一个函数，如果两个链表相交，请返回相交的 第一个节点。如果不相交，返
//回null
//
//



#include <iostream>

using namespace std;

#include <vector>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

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


ListNode * getCommonNode(ListNode * head1,ListNode * head2){
    if(head1== nullptr || head2== nullptr){
        return nullptr;
    }
    ListNode * cur1=head1;
    ListNode * cur2=head2;
    int n=0;
    while (cur1->next!= nullptr){
        n++;
        cur1=cur1->next;
    }
    while (cur2->next!= nullptr){
        n--;
        cur2=cur2->next;
    }
    // n 为差值 链表1长度减链表2长度
    // cur1 和 cur2 都已经走到最末尾了
    // 如果末尾不相交 那么之前的节点一定不相交
    // 如果末尾相交 之前一定有节点相交
    if(cur1!=cur2){
        return nullptr;
    }
    cur1=n > 0 ? head1 : head2; //
    cur2=cur1==head1 ? head2:head1;
    // cur1 存储 长度长的链表 cur2 存储长度短的链表
    n=abs(n);
    //  链表1 先走长度的差值
    while (n!=0){
        n--;
        cur1=cur1->next;
    }
    // 然后链表1 链表2 一起走直到 两个链表相交
    while (cur1!=cur2){
        cur1=cur1->next;
        cur2=cur2->next;
    }
    return cur1;

}

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    ListNode *A = headA, *B = headB;
    while (A != B) {
        A = A != nullptr ? A->next : headB;
        B = B != nullptr ? B->next : headA;
    }
    return A;
}





ListNode * bothLoop(ListNode * head1,ListNode * loop1 , ListNode * head2,ListNode * loop2){
    ListNode * cur1,*cur2;
    if(loop1==loop2){
        // 第二种情况 无环链表相交问题
        cur1 = head1;
        cur2 = head2;
        int n = 0;
        while (cur1 != loop1) {
            n++;
            cur1 = cur1->next;
        }
        while (cur2 != loop2) {
            n--;
            cur2 = cur2->next;
        }
        cur1 = n > 0 ? head1 : head2;
        cur2 = cur1 == head1 ? head2 : head1;
        n =abs(n);
        while (n != 0) {
            n--;
            cur1 = cur1.next;
        }
        while (cur1 != cur2) {
            cur1 = cur1.next;
            cur2 = cur2.next;
        }
        return cur1;
    }else{
        cur1=loop1->next;
        while (cur1!=loop1){
            if(cur1==loop2){
                // 情况3
                return loop1;
            }


            cur1=cur1->next;
        }
        // 情况1 相交节点为空
        return nullptr;



    }



}

ListNode * getIntersectNode(ListNode * head1,ListNode * head2){

    if (head1 == nullptr || head2 == nullptr) {
        return nullptr;
    }
    ListNode *  loop1 = detectCycle(head1);
    ListNode *  loop2 = detectCycle(head2);
    // list1 和 list2 都没有环路
    if (loop1 == nullptr && loop2 == nullptr) {
        return getCommonNode(head1, head2);
    }
    if(loop1!= nullptr && loop2!= nullptr){
        return bothLoop(head1,loop1,head2,loop2);
    }
    // 一个链表有环另外一个无环 一定不相交

    return nullptr;


}

int main(){


    return 0;
}