//
// Created by HappyBing on 2020-01-14.
//
#include <cstdio>

struct ListNode {
    int val;
    struct ListNode *next;

    ListNode(int x) :
            val(x), next(NULL) {
    }
};

ListNode *Merge(ListNode *pHead1, ListNode *pHead2) {
    if (pHead1 == NULL) {
        return pHead2;
    }
    if (pHead2 == NULL) {
        return pHead1;
    }
    //新建头结点 一定要新建头结点 保证接下来的循环两个链表地位是平等的 否则需要挑选较小的结点作为头结点
    ListNode *head = new ListNode(-1);
    ListNode *tempP = head;
    while (pHead1 != NULL && pHead2 != NULL) {
        if (pHead1->val < pHead2->val) {
            tempP->next = pHead1;
            pHead1 = pHead1->next;
        } else {
            tempP->next = pHead2;
            pHead2 = pHead2->next;
        }
        tempP = tempP->next;

    }
    if (pHead1 != NULL) {
        tempP->next = pHead1;
    }
    if (pHead2 != NULL) {
        tempP->next = pHead2;
    }
    return head->next;

}