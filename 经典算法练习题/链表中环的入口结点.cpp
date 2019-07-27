//
// Created by HappyBing on 2020-05-19.
//

#include <iostream>
#include <set>
using namespace std;
struct ListNode {
    int val;
    struct ListNode *next;

    ListNode(int x) :
            val(x), next(NULL) {
    }
};

// 快慢指针 时间复杂度O（n） 空间复杂度O（1）
ListNode *EntryNodeOfLoop(ListNode *pHead) {
    if (pHead == nullptr)
        return nullptr;
    ListNode *slow = pHead;
    ListNode *fast = pHead;
    // 判断快指针是否能走两步 ，若不能走两步则一定无环，同时快的能走两步慢的一定可以走一步
    while(fast != nullptr && fast->next != nullptr){
        fast = fast->next->next;
        slow = slow->next;
        // 定理：快慢相等了 则一定存在环
        if(fast == slow){
            fast = pHead; // 将随便一个指针重置到头结点
            while(fast != slow){// 每次走一步 只要相等了那么此处就是交汇点
                fast = fast->next;
                slow = slow->next;
            }
            return fast;
        }
    }
    return nullptr;
}

// 利用set的特性～时间复杂度O（nlogn） 空间复杂度O（n）
ListNode *EntryNodeOfLoop1(ListNode *pHead) {
    set < ListNode * > s;
    ListNode *node = pHead;
    while (node != NULL) {
        if (s.insert(node).second)
            node = node->next;
        else
            return node;
    }
    return node;

}