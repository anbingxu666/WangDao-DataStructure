//
// Created by HappyBing on 2020-01-14.
//

/*
 *操作给定的二叉树，将其变换为源二叉树的镜像。
 * */

#include <cstdio>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;

    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};

void Mirror(TreeNode *pRoot) {
    if (pRoot == NULL) {
        return;
    }
    TreeNode *temp = NULL;
    temp = pRoot->left;
    pRoot->left = pRoot->right;
    pRoot->right = temp;
    Mirror(pRoot->left);
    Mirror(pRoot->right);
}