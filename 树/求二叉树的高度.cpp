//
// Created by Newmor on 2019-09-09.
//


#include <cstdio>
#include <queue>

#define ElemType int

using namespace std;

typedef struct BTNode {
    struct BTNode *lchild, *rchild;
    ElemType data;
} BTNode, *BiTree;


//非递归算法求树的高度
int height(BiTree tree) {
    if (tree == nullptr) {
        return 0;
    }
    int high = 0;
    queue < BTNode * > q;
    q.push(tree);

    while (!q.empty()) {
        int size = q.size();
        high++;
        //和层序遍历的不同之处 需要将队列中的所有本层元素处理完在处理下一层的
        for (int i = 0; i < size; ++i) {
            BTNode *p = q.front();
            q.pop();
            if (p->lchild != nullptr) {
                q.push(p->lchild);
            }
            if (p->rchild != nullptr) {
                q.push(p->rchild);
            }
        }


    }
    return high;

}

//递归版求树的高度
int heightRecur(BiTree tree) {
    if (tree == NULL)
        return 0;
    int lheight = height(tree->lchild);
    int rheight = height(tree->rchild);
    return lheight > rheight ? lheight + 1 : rheight + 1;

}

//超级精简 一行代码
int heightSimple(BiTree tree) {
    return tree == NULL ? 0 : (max(heightSimple(tree->lchild), heightSimple(tree->rchild)) + 1);
}

int main() {
    return 0;
}
