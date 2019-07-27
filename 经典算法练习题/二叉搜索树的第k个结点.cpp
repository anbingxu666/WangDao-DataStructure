//
// Created by HappyBing on 2020-06-01.
//

#include <cstdio>
#include <vector>
using namespace std;
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
void Inorder(TreeNode *pRoot, vector<TreeNode *> &vec);

TreeNode *KthNode(TreeNode *pRoot, unsigned int k) {
    if (pRoot == NULL || k <= 0) return NULL;
    vector < TreeNode * > vec;
    Inorder(pRoot, vec);
    if (k > vec.size())
        return NULL;
    return vec[k - 1];
}

//中序遍历，将节点依次压入vector中
void Inorder(TreeNode *pRoot, vector<TreeNode *> &vec) {
    if (pRoot == NULL) return;
    Inorder(pRoot->left, vec);
    vec.push_back(pRoot);
    Inorder(pRoot->right, vec);
}