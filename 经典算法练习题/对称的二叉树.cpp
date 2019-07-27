//
// Created by HappyBing on 2020-05-15.
//
#include <cstdio>
#include <iostream>
#include <queue>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;

    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};

/*
 *
 * 递归算法，不是很完美
 *
 *
 * */
//bool isSame(TreeNode *left, TreeNode *right);
//bool isSymmetrical(TreeNode *pRoot) {
//    if (pRoot == nullptr)
//        return true;
//
//    return isSame(pRoot->left, pRoot->right);
//}
//
//bool isSame(TreeNode *p1, TreeNode *p2) {
//    if (p1 == nullptr && p2 == nullptr) {
//        return true;
//    }
//    if (p1 == nullptr || p2 == nullptr) {
//        return false;
//    }
//    if(p1->val != p2->val)
//        return false;
//    return  isSame(p1->left, p2->right) &&
//            isSame(p2->left, p1->right);
//
//
//}

/*
 *
 * DFS 和 BFS遍历树
 * 栈  和 队列
 *
 *
 */
bool isSymmetrical(TreeNode *pRoot) {
    if (pRoot == nullptr)
        return true;
    queue<TreeNode *> q;
    q.push(pRoot->left);
    q.push(pRoot->right);
    while (!q.empty()) {
        TreeNode *p1 = q.front();
        q.pop();
        TreeNode *p2 = q.front();
        q.pop();
        if (p1 == nullptr && p2 == nullptr) {
            continue;
        }
        if (p1 == nullptr || p2 == nullptr) {
            return false;
        }
        if (p1->val != p2->val) {
            return false;
        }
        q.push(p1->left);
        q.push(p2->right);
        q.push(p1->right);
        q.push(p2->left);
    }
    return true;


}
// DFS仅仅是把队列换成了栈
bool isSymmetrical2(TreeNode *pRoot) {
    if (pRoot == nullptr)
        return true;
    stack<TreeNode *> q;
    q.push(pRoot->left);
    q.push(pRoot->right);
    while (!q.empty()) {
        TreeNode *p1 = q.top();
        q.pop();
        TreeNode *p2 = q.top();
        q.pop();
        if (p1 == nullptr && p2 == nullptr) {
            continue;
        }
        if (p1 == nullptr || p2 == nullptr) {
            return false;
        }
        if (p1->val != p2->val) {
            return false;
        }
        q.push(p1->left);
        q.push(p2->right);
        q.push(p1->right);
        q.push(p2->left);
    }
    return true;


}