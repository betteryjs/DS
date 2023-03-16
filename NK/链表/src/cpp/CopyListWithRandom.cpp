//
// Created by yjs on 23-3-15.
// 复制含有随机指针节点的链表
//

#include <iostream>
#include <unordered_map>
#include <vector>


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
    // map[old node] = new node
    ListNode *cur = head;
    while (cur != nullptr) {
        ListNodeMap.emplace(cur, new ListNode(cur->val));
        cur = cur->next;
    }
    cur = head;
    // map[cur] 新节点  map[cur->next] 老节点的next指针对应的新节点的next指针
    // .at() 返回容器中存储的键 key 对应的值，如果 key 不存在，则会抛出 out_of_range 异常。
    while (cur != nullptr) {
        ListNodeMap[cur]->next = ListNodeMap[cur->next];
        ListNodeMap[cur]->rand = ListNodeMap[cur->rand];
        cur = cur->next;
    }
    return ListNodeMap[head];
}


ListNode *copyListWithRand(ListNode *head) {
    if (head == nullptr) {
        return nullptr;
    }
    ListNode *cur = head;
    ListNode *nextNode = nullptr;

    while (cur != nullptr) {
        nextNode = cur->next;

        cur->next = new ListNode(cur->val);
        cur->next->next = nextNode;

        cur = nextNode;
    }

    // 1  - 1'  - 2  - 2' - 3  - 3'
    cur = head;
    ListNode *copyHead = head->next;
    ListNode *copyCur = nullptr;

    // set copy node rand
    // 1 -  1' -  2 - 2' - 3  - 3'
    while (cur != nullptr) {
        nextNode = cur->next->next;

        copyCur = cur->next;
        cur->next = nextNode;
        copyCur->next = nextNode == nullptr ? nullptr : nextNode->next;

        cur = nextNode;
    }

    return copyHead;


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
    vector<int> nums{1, 25, 26, 23, 17};
    BuildList buildList(nums);
    BuildList::PrintLinkList(buildList.getHead(), "old list is :");
    BuildList::PrintLinkListWithPointer(buildList.getHead(), "old list pointer is :");


    ListNode *resNode = copyListWithRand(buildList.getHead());

    BuildList::PrintLinkList(resNode, "new list is : ");
    BuildList::PrintLinkListWithPointer(resNode, "new list pointer is :");


}


