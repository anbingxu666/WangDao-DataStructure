//
// Created by HappyBing on 2020-01-05.
//

#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


TreeNode *reConstructBinaryTree(vector<int> pre, vector<int> vin) {

    //围绕中序遍历序列展开代码
    int vinLen = vin.size();
    if (vinLen == 0) {
        return nullptr;
    }

    //在中序序列中找到根节点
    int rootIndex = 0;
    for (int i = 0; i < vinLen; ++i) {
        if (vin[i] == pre[0]) {
            rootIndex = i;
            break;
        }
    }
    //创建根节点
    TreeNode *root = new TreeNode(pre[0]);

    vector<int> left_p, right_p, left_i, right_i;

    //左子树数组
    for (int i = 0; i < rootIndex; ++i) {
        left_p.push_back(pre[i + 1]);
        left_i.push_back(vin[i]);

    }
    //右子树数组
    for (int j = rootIndex + 1; j < vinLen; ++j) {
        right_p.push_back(pre[j]);
        right_i.push_back(vin[j]);
    }
    //递归左右子树
    root->left = reConstructBinaryTree(left_p, left_i);
    root->right = reConstructBinaryTree(right_p, right_i);

    return root;
}

void inOrderTraverse(TreeNode *root) {
    if (root != nullptr) {
        inOrderTraverse(root->left);
        cout << root->val << endl;
        inOrderTraverse(root->right);
    }
}

//int main() {
//    vector<int> pre;
//    vector<int> vin;
//    pre = {1, 2, 4, 7, 3, 5, 6, 8};
//    vin = {4, 7, 2, 1, 5, 3, 8, 6};
//
//    TreeNode *root = reConstructBinaryTree(pre, vin);
//    inOrderTraverse(root);
//}