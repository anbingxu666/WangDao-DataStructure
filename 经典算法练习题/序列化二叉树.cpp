//
// Created by newLion on 2020-06-10.
//
#include <cstdio>
#include <string>

using namespace std;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;

    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};

// 基于先序遍历
char *Serialize(TreeNode *root) {
    if (!root) {
        return "#";
    }
    string res = to_string(root->val); //根结点添加到结果中
    res.push_back(','); // 添加分隔符
    char *left = Serialize(root->left); //递归左子树
    char *right = Serialize(root->right);//递归右子树
    // 拼接结果
    char *ret = new char[strlen(left) + strlen(right) + res.size()];
    strcpy(ret, res.c_str());
    strcat(ret, left);
    strcat(ret, right);
    return ret;

}

// 参数使用引用&， 以实现全局变量的目的
TreeNode* deseri(char *&s) {
    if (*s == '#') {
        ++s;
        return nullptr;
    }

    // 构造根节点值
    int num = 0;
    while (*s != ',') { //字符串转为数字
        num = num * 10 + (*s - '0');
        ++s;
    }
    ++s;
    // 递归构造树
    TreeNode *root = new TreeNode(num);
    root->left = deseri(s);
    root->right = deseri(s);

    return root;
}

TreeNode* Deserialize(char *str) {
    return deseri(str);
}
