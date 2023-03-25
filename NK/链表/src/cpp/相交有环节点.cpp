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
    if(cur1!=cur2){
        return nullptr;
    }
    cur1=n > 0 ? head1 : head2; //
    cur2=cur1==head1 ? head2:head1;
    n=abs(n);
    while ( n!=0){
        n--;
        cur1=cur1->next;
    }
    while (cur1!=cur2){
        cur1=cur1->next;
        cur2=cur2->next;

    }
    return cur1;












}
