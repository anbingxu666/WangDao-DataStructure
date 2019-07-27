//
// Created by HappyBing on 2020-05-17.
//

#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};

vector<vector<int> > Print(TreeNode *pRoot) {
    vector<vector<int> > res;
    if (pRoot == nullptr)
        return res;
    queue<TreeNode *> q;
    q.push(pRoot);
    while (!q.empty()) {
        long len = q.size();
        vector<int> lay;
        // 将每层的打印出来
        for (long i = 0; i < len; ++i) {
            // 弹出结点并打印
            TreeNode *pNode = q.front();
            q.pop();
            lay.push_back(pNode->val);
            //将后续的加进去
            if (pNode->left != nullptr)
                q.push(pNode->left);
            if (pNode->right != nullptr)
                q.push(pNode->right);
        }
        res.push_back(lay);
    }
    return res;

}