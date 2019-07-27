//
// Created by Newmor on 2020-01-25.
//

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

vector<vector<int>> res;
vector<int> path;

//表面是find 其实是DFS
void find(TreeNode *root, int sum) {
    if (root == NULL) {//递归出口
        return;
    }

    path.push_back(root->val);//根节点 入 集合

    if (!root->left && !root->right && sum == root->val) {//仅有根节点且根结点等于和的特殊情况or到达叶子节点
        res.push_back(path);

    } else {
        if (root->left) {
            //看左子树的是否可以凑成 sum - 根结点的值
            find(root->left, sum - root->val);
        }
        if (root->right) {
            //看右子树的是否可以凑成 sum - 根结点的值
            find(root->right, sum - root->val);
        }
    }
    path.pop_back();//若上述都不满足则回溯到上一个结点
}

vector<vector<int>> FindPath(TreeNode *root, int expectNumber) {
    find(root, expectNumber);
    return res;
}