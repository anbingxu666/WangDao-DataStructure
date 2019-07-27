//
// Created by HappyBing on 2020-05-19.
//

/*
 *
 * 给定一个二叉树和其中的一个结点，请找出中序遍历顺序的下一个结点并且返回。注意，树中的结点不仅包含左右子结点，同时包含指向父结点的指针。
 * */
#include <iostream>
#include <vector>

using namespace std;

struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;

    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {

    }
};

TreeLinkNode *firstInRightTree(TreeLinkNode *p) {
    // 找到某棵树最左孩子的办法
    TreeLinkNode *temp = p->right;
    while (temp->left != nullptr)
        temp = temp->left;
    return temp;

}

TreeLinkNode *GetNext(TreeLinkNode *pNode) {
    if (pNode == nullptr)
        return nullptr;
    if (pNode->right != nullptr) {
        return firstInRightTree(pNode);
    } else {
        // 若某结点为根的某棵子树的左孩子是pNode那么该结点就是pNode的下一个结点(即pNode->next)。
        while (pNode->next != nullptr && pNode->next->left != pNode) {
            pNode = pNode->next;
        }
        return pNode->next;
    }
}

