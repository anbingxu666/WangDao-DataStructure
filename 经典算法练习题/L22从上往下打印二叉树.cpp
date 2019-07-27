//
// Created by HappyBing on 2020-01-25.
//


//题目：从上往下打印出二叉树的每个节点，同层节点从左至右打印。
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

//解法：二叉树的层序遍历
vector<int> PrintFromTopToBottom(TreeNode *root) {
    vector<int> res;
    queue<TreeNode *> queue;
    if (root == NULL) {
        return res;
    }
    queue.push(root);//根节点入队列
    while (!queue.empty()) {
        TreeNode *tempNode = queue.front();//弹出一个打印
        queue.pop();
        res.push_back(tempNode->val);
        if (tempNode->left != NULL) {
            queue.push(tempNode->left);
        }
        if (tempNode->right != NULL) {
            queue.push(tempNode->right);
        }
    }
    return res;
}