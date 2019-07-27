//
// Created by HappyBing on 2020-01-14.
//
#include <cstdio>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;

    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};

bool isSubtree(TreeNode *pRoot1, TreeNode *pRoot2) {
    //用于判断两棵树是否从根结点开始就长得一样
    if (pRoot2 == NULL) {
        return true;
    }
    if (pRoot1 == NULL) {
        return false;
    }
    if (pRoot1->val == pRoot2->val) {
        //判断子树的值是否相等
        return isSubtree(pRoot1->left, pRoot2->left) &&
               isSubtree(pRoot1->right, pRoot2->right);
    } else {
        return false;
    }
}

bool HasSubtree(TreeNode *pRoot1, TreeNode *pRoot2) {
    //递归出口1 即某一个子树的根结点为空的时候
    if (pRoot1 == NULL || pRoot2 == NULL) {
        return false;
    }
    //一共右三种 B是A的子树的情况 1.根结点开始相同 2.左子树开始相同 3.右子树开始相同
    return isSubtree(pRoot1, pRoot2) ||
           HasSubtree(pRoot1->left, pRoot2) ||
           HasSubtree(pRoot1->right, pRoot2);

}