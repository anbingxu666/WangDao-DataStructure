//
// Created by 安炳旭 on 2019-08-07.
//

#include <cstdio>
#include <cstdlib>

#define ElemType int

//定义树的链式存储结构
typedef struct BiTNode {
    struct BiTNode *lchild;
    struct BiTNode *rchild;
    ElemType data;

} BiTNode, *BiTree;

//用于初始化一棵树的算法
void initTree(BiTree *T) {
    *T = (BiTNode *) malloc(sizeof(BiTNode));
    (*T)->data = 1;
    (*T)->lchild = (BiTNode *) malloc(sizeof(BiTNode));
    (*T)->rchild = (BiTNode *) malloc(sizeof(BiTNode));
    (*T)->lchild->data = 2;
    (*T)->lchild->lchild = (BiTNode *) malloc(sizeof(BiTNode));
    (*T)->lchild->rchild = (BiTNode *) malloc(sizeof(BiTNode));
    (*T)->lchild->rchild->data = 5;
    (*T)->lchild->rchild->lchild = NULL;
    (*T)->lchild->rchild->rchild = NULL;
    (*T)->rchild->data = 3;
    (*T)->rchild->lchild = (BiTNode *) malloc(sizeof(BiTNode));
    (*T)->rchild->lchild->data = 6;
    (*T)->rchild->lchild->lchild = NULL;
    (*T)->rchild->lchild->rchild = NULL;
    (*T)->rchild->rchild = (BiTNode *) malloc(sizeof(BiTNode));
    (*T)->rchild->rchild->data = 7;
    (*T)->rchild->rchild->lchild = NULL;
    (*T)->rchild->rchild->rchild = NULL;
    (*T)->lchild->lchild->data = 4;
    (*T)->lchild->lchild->lchild = NULL;
    (*T)->lchild->lchild->rchild = NULL;
}

//访问函数 用于输出结点的数据
void visit(BiTNode *node) {
    printf("-->%d\t", node->data);
}

//中序遍历递归版本
void inOrderTraverse(BiTree Tree) {
    if (Tree) {
        inOrderTraverse(Tree->lchild);
        visit(Tree);
        inOrderTraverse(Tree->rchild);
    }
}

//中序遍历非递归版本
void inOrderTraverseNonrecursion(BiTree Tree) {
    BiTNode *stack[100];//初始化一个数组栈
    int top = -1;//栈顶指针指向-1
    BiTNode *p = Tree;//辅助指针p 指向当前要操作的结点 初始为root
    while (p != nullptr || top != -1) {
        if (p) {
            stack[++top] = p;
            p = p->lchild;
        } else {
            p = stack[top--];//出栈
            visit(p);//访问
            p = p->rchild;
        }
    }
}

int main() {
    BiTree tree;
    initTree(&tree);

    inOrderTraverse(tree);
    printf("\n-----中序递归/非递归------\n");
    inOrderTraverseNonrecursion(tree);
    return 0;
}