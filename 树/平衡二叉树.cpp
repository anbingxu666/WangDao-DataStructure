//
// Created by Newmor on 2019-09-06.
//



#include <cstdio>
#include <cstdlib>
#include <queue>

using namespace std;

#define ElemType int
typedef struct BSTNode {
    struct BSTNode *left, *right;
    ElemType data;
} *BiTree;


BSTNode *BST_search(BiTree T, ElemType val, BSTNode *&p) {
    while (T != NULL && T->data != val) {
        p = T;
        if (val < T->data) {
            T = T->left;
        } else {
            T = T->right;
        }
    }
    return T;
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

void inOrderTraverseNonRecur(BiTree tree) {
    if (tree == NULL) {
        return;
    }
    inOrderTraverseNonRecur(tree->left);
    printf("->%d\n", tree->data);
    inOrderTraverseNonRecur(tree->right);
}

void layerTraverse(BiTree tree) {
    if (tree == nullptr) {
        return;
    }
    queue < BSTNode * > q;
    q.push(tree);
    while (!q.empty()) {
        BSTNode *p = q.front();
        q.pop();
        printf("->%d\n", p->data);
        if (p->left != nullptr) {
            q.push(p->left);
        }
        if (p->right != nullptr) {
            q.push(p->right);
        }
    }

}

int main() {
    int a[10] = {9, 8, 7, 6, 5, 4, 3, 2, 1, -10};
    int length = 10;
    BiTree Tree;
    Create_BST(Tree, a, length);
    printf("中序遍历\n");
    inOrderTraverseNonRecur(Tree);
    printf("层序遍历\n");
    layerTraverse(Tree);
    return 0;
}