//
// Created by HappyBing on 2019-07-31.
//
// DFS临界矩阵版本



#include <cstdio>

#define MAX_V 100 //邻接矩阵中的最大顶点书目
#define INF 99999 //INF代表顶点不可达
int n, G[MAX_V][MAX_V] = {
        {0,   1,   INF, 1},
        {INF, 0,   1, INF},
        {INF, INF, 0, INF},
        {INF, INF, INF, 0},
};
int isVisited[100] = {0};

int DFS(int u, int deep) {//deep代表深度 此代码中无实际意义
    isVisited[u] = 1;
    printf("--->%d\t", u); //打印访问的结点
    for (int i = 0; i < n; ++i) {
        if (G[u][i] != INF && isVisited[i] == 0) {
            DFS(i, deep + 1);//递归
        }
    }
}

void DFSTraverse() {
    //保证非连通的点也被访问到
    for (int u = 0; u < n; ++u) {
        if (isVisited[u] == 0) {
            DFS(u, 1);

        }

    }
}

int main() {
    n = 4;
    DFSTraverse();
}