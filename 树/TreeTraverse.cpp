//
// Created by Newmor on 2019-08-07.
//

#include <cstdio>
#include <cstdlib>
#include <queue>

#define ElemType int

using namespace std;
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

//先序遍历递归版本
void preOrderTraverse(BiTree Tree) {
    if (Tree) {
        visit(Tree);
        preOrderTraverse(Tree->lchild);
        preOrderTraverse(Tree->rchild);
    }
}

//先序遍历非递归版本
void preOrderTraverseNonrecursion(BiTree Tree) {
    if(Tree == nullptr){
        return;
    }
    if (Tree) {
        BiTNode *stack[100];
        int top = -1;
        BiTNode *p = Tree;
        stack[++top] = p;//根结点入栈
        while (top != -1) {
            p = stack[top--];//出栈访问
            visit(p);

            //!!!先右后左 因为后入栈的先出栈 而先序遍历 通常先访问左孩子
            if (p->rchild) {
                stack[++top] = p->rchild;
            }

            if (p->lchild) {
                stack[++top] = p->lchild;
            }

        }
    }
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
    if(Tree == nullptr){
        return;
    }
    BiTNode *stack[100];//初始化一个数组栈
    int top = -1;//栈顶指针指向-1
    BiTNode *p = Tree;//辅助指针p 指向当前要操作的结点 初始为root
    while (p != nullptr || top != -1) {
        if (p) {
            stack[++top] = p;//入栈
            p = p->lchild;//指向其左孩子
        } else {
            p = stack[top--];//出栈
            visit(p);//访问
            p = p->rchild;//指向其右孩子
        }
    }
}

//后序遍历递归算法
void postOrderTraverse(BiTree Tree) {
    if (Tree) {
        postOrderTraverse(Tree->lchild);
        postOrderTraverse(Tree->rchild);
        visit(Tree);
    }
}

//后序遍历的递归算法
void postOrderTraverseNonrecursion(BiTree Tree) {
    if(Tree == nullptr){
        return;
    }
    BiTNode *stack1[100];
    BiTNode *stack2[100];//后序遍历的非递归算法 通常需要双栈 ，但是也有单栈的算法.
    //栈一用来辅助遍历，栈二存放遍历的顺序。
    int top1 = -1, top2 = -1;
    BiTNode *p = Tree;
    stack1[++top1] = p;//先将根结点入栈1
    while (top1 != -1) {
        p = stack1[top1--];//出栈1
        stack2[top2++] = p;//进入栈2 ，栈二是为了保存每遍历顺序的逆序的栈

        //先左后右的目的是 右先弹出栈1 然后先进栈2 后出栈2 所以是左 右 根的顺序
        if (p->lchild) {//先入左
            stack1[++top1] = p->lchild;
        }
        if (p->rchild) {//后入右
            stack1[++top1] = p->rchild;
        }
    }
    //遍历栈二 即访问顺序
    while (top2 != -1) {
        p = stack2[--top2];
        visit(p);
    }
}

//层序遍历算法 借助c++ stl的queue实现
void LevelOrderTraverse(BiTree Tree) {
    queue<BiTNode *> myQueue;
    if (Tree) {
        myQueue.push(Tree);//根结点入队列
    }
    while (!myQueue.empty()) {
        BiTNode *pNode = myQueue.front();//取得队首
        myQueue.pop();//删除队列首个元素
        visit(pNode);
        if (pNode->lchild) {//左孩子入队列
            myQueue.push(pNode->lchild);

        }
        if (pNode->rchild) {//右孩子入队列
            myQueue.push(pNode->rchild);

        }
    }
}

int main() {
    BiTree tree;
    initTree(&tree);

    preOrderTraverse(tree);
    printf("\n-----先序递归/非递归------\n");
    preOrderTraverseNonrecursion(tree);

    printf("\n");
    printf("\n-------------------------------------------\n");
    printf("\n");

    inOrderTraverse(tree);
    printf("\n-----中序递归/非递归------\n");
    inOrderTraverseNonrecursion(tree);


    printf("\n");
    printf("\n-------------------------------------------\n");
    printf("\n");

    postOrderTraverse(tree);
    printf("\n-----后序递归/非递归------\n");
    postOrderTraverseNonrecursion(tree);

    printf("\n");
    printf("\n-------------------------------------------\n");
    printf("\n");

    printf("层序遍历\n");
    LevelOrderTraverse(tree);

    return 0;
}