//
// Created by HappyBing on 2020-01-13.
//

#include <cstdio>

struct ListNode {
    int val;
    struct ListNode *next;

    ListNode(int x) :
            val(x), next(NULL) {
    }
};


ListNode *FindKthToTail(ListNode *pListHead, unsigned int k) {
    if (pListHead == NULL || k <= 0) {
        return NULL;
    }
    if (pListHead->next == NULL) {
        return pListHead;
    }
    //双指针法
    ListNode *p1, *p2;
    p1 = pListHead;
    p2 = pListHead;
    //将第一个指针移动k-1次
    for (int i = 1; i < k; ++i) {
        if (p1->next != NULL) {
            p1 = p1->next;
        } else {
            return NULL;
        }
    }
    //移动第二个指针 直到第一个指针指向最后一个元素（即next == NULL）
    while (p1->next != NULL) {
        p2 = p2->next;
        p1 = p1->next;
    }
    return p2;
}