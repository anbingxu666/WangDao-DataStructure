//
// Created by HappyBing on 2020-01-13.
//

#include <iostream>

struct ListNode {
    int val;
    struct ListNode *next;

    ListNode(int x) :
            val(x), next(NULL) {
    }
};

ListNode *ReverseList(ListNode *pHead) {
    ListNode *pre = NULL, *next = NULL;
    if (pHead == NULL) {
        return NULL;
    }
    while (pHead->next != NULL) {
        next = pHead->next;
        pHead->next = pre;
        pre = pHead;
        pHead = next;
    }
    return pre;
}


ListNode *ReverseList2(ListNode *pHead) {
    if (pHead == NULL) {
        return NULL;
    }
    if (pHead->next == NULL) {
        return pHead;
    }
    //递归到最后一个结点  同时保存前一个结点的信息
    ListNode *p = ReverseList2(pHead->next);
    //反转
    pHead->next->next = pHead;
    pHead->next = NULL;
    return p;
}
