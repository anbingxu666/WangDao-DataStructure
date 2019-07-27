//
// Created by HappyBing on 2020-01-26.
//

/*输入一个复杂链表（每个节点中有节点值，以及两个指针，一个指向下一个节点，另一个特殊指针指向任意一个节点），返回结果为复制后复杂链表的head。（注意，输出结果中请不要返回参数中的节点引用，否则判题程序会直接返回空）*/

#include <iostream>

using namespace std;

struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;

    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};

RandomListNode *Clone(RandomListNode *pHead) {
    if (pHead == NULL) {
        return NULL;
    }
    //第一步： 在当前链表中复制每一个结点（仅复制值 不复制random指针）
    RandomListNode *cp = pHead;//临时指针
    while (cp) {
        RandomListNode *newNode = new RandomListNode(cp->label);//复制一个当前结点
        //链接到当前结点的后面
        newNode->next = cp->next;
        cp->next = newNode;

        cp = newNode->next;//移动到下一个要复制的结点
    }
    //第二步 ：为新加入的结点的random指针复制
    cp = pHead;
    while (cp) {
        RandomListNode *copyNodePoint = cp->next;
        if (cp->random) {
            copyNodePoint->random = cp->random->next;//加next的目的是让复制的结点random指向复制的结点而不是原来的结点

        }
        cp = copyNodePoint->next;//移动到下一个要复制的结点
    }
    //第三步： 拆分成两个链表
    RandomListNode *pCloneHead = pHead->next;//保存表头
    RandomListNode *tmp;
    cp = pHead;
    while (cp->next) {
        tmp = cp->next;
        cp->next = tmp->next;
        cp = tmp;//移动到下一个结点
    }
    return pCloneHead;
}