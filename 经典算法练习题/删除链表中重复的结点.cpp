//
// Created by newLion on 2020-06-06.
//

#include <iostream>

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
            val(x), next(NULL) {
    }
};
ListNode *deleteDuplication(ListNode *pHead) {
    ListNode *vhead = new ListNode(-1); // 新建头结点（为了方便得到新的链表头结点
    vhead->next = pHead;
    ListNode *pre = vhead, *cur = pHead;
    while (cur) {
        if (cur->next && cur->val == cur->next->val) {
//            cur = cur->next;
            while (cur->next && cur->val == cur->next->val) {
                cur = cur->next;
            }
            cur = cur->next; // 重复的一个都不保留
            pre->next = cur;
        } else {
            pre = cur;
            cur = cur->next;
        }
    }
    return vhead->next;
}