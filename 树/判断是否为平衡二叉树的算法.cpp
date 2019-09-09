//
// Created by Newmor on 2019-09-09.
//
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <algorithm>
#include <cmath>

using namespace std;

#define ElemType int

typedef struct BSTNode {
    struct BSTNode *left, *right;
    ElemType data;
} *BiTree;

int getDepth(BiTree tree);

//递归算法：自上而下的算法 增加了许多不必要的开销 需要剪枝
bool judge_AVL(BiTree tree) {
    if (tree == NULL)
        return true;
    return (abs(heightSimple(tree->left) - heightSimple(tree->right)) <= 1)
           && judge_AVL(tree->left) && judge_AVL(tree->right);
}

//剪枝后算法：自下而上而上 发现不是直接终止
bool judge_AVL_Opt(BiTree tree) {
    return getDepth(tree) != -1;
}

//如果子树是平衡二叉树则返回高度 如果不是平衡二叉树则返回-1
int getDepth(BiTree tree) {
    if (tree == NULL)
        return 0;

    int left = getDepth(tree->left);
    if (left == -1)//-1代表不平衡了
        return -1;

    int right = getDepth(tree->right);
    if (right == 1)
        return 1;

    return abs(left - right) > 1 ? -1 : 1 + max(left, right);

}

int BST_insert(BiTree &T, ElemType val) {
    if (T == NULL) {
        T = (BSTNode *) malloc(sizeof(BSTNode));
        T->data = val;
        T->left = NULL;
        T->right = NULL;
        return 1;
    } else if (T->data == val) {
        return -1;//相等报错
    } else if (T->data > val) {//小于根结点则插在左子树
        return BST_insert(T->left, val);
    } else {
        return BST_insert(T->right, val);
    }

}

void Create_BST(BiTree &tree, ElemType *array, int length) {
    tree = NULL;
    for (int i = 0; i < length; ++i) {
        BST_insert(tree, array[i]);
    }
}

int main() {
    int a[10] = {9, 8, 100, 11, 120, 4, 3, 2, 1, -10};
    int length = 6;
    BiTree Tree;
    Create_BST(Tree, a, length);


    printf("是否为平衡二叉树？%d\n", judge_AVL(Tree));
    printf("是否为平衡二叉树？%d\n", judge_AVL_Opt(Tree));
    return 0;
}