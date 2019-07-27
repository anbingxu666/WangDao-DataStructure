//
// Created by HappyBing on 2019-11-03.
//

#include <cstdio>
#include <cstdlib>
#include <queue>

using namespace std;
typedef struct TreeNode {
    struct TreeNode *left, *right;
    int weight;
} *Tree;


//王道上给的答案繁琐至极 考试中估计肯定写不出来
//提高一种利用递归计算wpl的算法，十分好理解，并且好写
int WPL(Tree tree, int depth) {
    if (tree == NULL) {
        return 0;
    }
    if (tree->left == NULL && tree->right == NULL) {
        return (tree->weight * depth);//已经到叶子结点了：返回本层的wpl
    } else {
        return (tree->weight * depth) +
               (WPL(tree->left, depth + 1) + WPL(tree->right, depth + 1));//返回本层wpl+左右子树的wpl
    }
}






int main() {
    //暴力建立一棵简单的🌲 （一般闲的蛋疼才这样建树

    Tree tree;
    tree = (TreeNode *) malloc(sizeof(TreeNode));
    TreeNode *t1 = (Tree) malloc(sizeof(TreeNode));
    TreeNode *t2 = (Tree) malloc(sizeof(TreeNode));
    TreeNode *t3 = (Tree) malloc(sizeof(TreeNode));
    tree->weight = 1;
    t1->weight = 2;
    t2->weight = 3;
    t3->weight = 4;
    tree->left = t1;
    tree->right = t2;
    t1->left = t3;
    t1->right = NULL;
    t2->left = NULL;
    t2->right = NULL;
    t3->left = NULL;
    t3->right = NULL;



    /*
     *
     *
     * 树涨这样
     *   1
     *  2  3
     * 4
     *
     *
     * */

    //计算WPL的算法
    printf("\nWPL:%d\n", WPL(tree, 1));
    return 0;
}