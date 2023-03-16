//
// Created by yjs on 23-3-15.
// 将单向链表按某值划分成左边小、中间相等、右边大的形式
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
        head->next= nullptr;
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
        eT->next = bH;
    }

    return sH != nullptr ? sH : eH != nullptr ? eH : bH;


}


class BuildList {
private:


    vector<int> nums;

private:


    bool InsertNextNode(ListNode *p, const int &e) {

        if (p == nullptr) {
            return false;
        }
        ListNode *s = new ListNode(e);
        s->next = p->next;
        p->next = s;
        return true;
    }

    ListNode *head = new ListNode(-1);


public:

    BuildList(const vector<int> &nums) : nums(nums) {
        ListNode *cur = this->head;

        ListTailInsert(cur, nums);


    }

    ListNode *ListTailInsert(ListNode *head, const vector<int> &nums) {
        ListNode *pos1 = head;
        for (const int &num: nums) {
            InsertNextNode(pos1, num);
            pos1 = pos1->next;
        }
        return head;
    }


    static void PrintLinkList(ListNode *head, const string &content) {
        cout << content << "  ";
        ListNode *cur = head->next;
        while (cur) {
            cout << cur->val << " ";
            cur = cur->next;


        }
        cout << endl;

    }


    static void PrintLinkListWithPointer(ListNode *head, const string &content) {
        cout << content << "  ";
        ListNode *cur = head->next;
        while (cur) {
            cout << cur << " ";
            cur = cur->next;


        }
        cout << endl;

    }


    ListNode *getHead() {

        return this->head;

    }


};


int main() {
    vector<int> nums{1, 25,12,11,2, 26, 23, 11,17,11,25,36,6,4};
    BuildList buildList(nums);

    ListNode * res=listPartition(buildList.getHead(), 11);
    BuildList::PrintLinkList(res, "list is : ");


}
