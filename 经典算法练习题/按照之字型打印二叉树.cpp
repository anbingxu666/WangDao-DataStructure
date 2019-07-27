//
// Created by HappyBing on 2020-05-28.
//
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
    int flag = 1;
    q.push(pRoot);
    while (!q.empty()) {
        unsigned long sizeOfQueue = q.size();
        vector<int> layer;
        for (int i = 0; i < sizeOfQueue; ++i) {
            TreeNode *temp = q.front();
            q.pop();
            layer.push_back(temp->val);
            if (temp->left) {
                q.push(temp->left);
            }
            if (temp->right) {
                q.push(temp->right);
            }
        }
        if (flag == 1) {
            res.push_back(layer);
            flag = 0;
        } else {
            reverse(layer.begin(),layer.end());
            res.push_back(layer);
            flag = 1;
        }
    }
    return res;
}