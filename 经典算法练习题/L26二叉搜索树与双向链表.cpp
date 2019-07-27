//
// Created by HappyBing on 2020-01-26.
//


/*输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表。要求不能创建任何新的结点，只能调整树中结点指针的指向。*/

#include <iostream>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;

    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};

TreeNode *head = NULL;
TreeNode *point = NULL;

TreeNode *Convert(TreeNode *pRootOfTree) {
    if (pRootOfTree == NULL) {
        return NULL;
    }
    Convert(pRootOfTree->left);
    if (head == NULL) {//到达最左子树可以确定头结点
        head = pRootOfTree;
        point = pRootOfTree;
    } else {//链接中序列
        point->right = pRootOfTree;
        pRootOfTree->left = point;
        point = point->right;
    }
    Convert(pRootOfTree->right);
    return head;
}