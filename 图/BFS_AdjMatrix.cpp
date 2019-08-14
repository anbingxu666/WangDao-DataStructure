//
// Created by 安炳旭 on 2019-07-27.
// BFS邻接矩阵版本
//


#include <cstdio>
#include <queue>

#define MAX_V 100 //邻接矩阵中的最大顶点书目
#define INF 99999 //INF代表顶点不可达
using namespace std;
int n, G[MAX_V][MAX_V] = {
        {0, INF, 1},
        {INF, 0, 3},
        {INF, 1, 0},

}; //n代表当前图的顶点数目 。G为图的邻接矩阵,最大顶点数100
int isVisited[100] = {0};//记录顶点是否被访问过 1代表是

//访问
void visit(int i) {
    printf("i=%d\n", i);

}

void BFS(int u) {//遍历u所在的连通块
    queue<int> q;//定义一个辅助的队列
    q.push(u);
    visit(u);
    isVisited[u] = 1;//将u设置为已经访问
    while (!q.empty()) {//如果队列非空
        int u = q.front();//取出队首元素
        q.pop();//将队首元素出队
        for (int i = 0; i < n; ++i) {//遍历u的邻接点i
            if (isVisited[i] == 0 && G[u][i] != INF) {
                q.push(i);
                visit(i);
                isVisited[i] = true;//设置为已经访问
            }

        }

    }

}

void BFSTrave() {
    for (int u = 0; u < n; ++u) {//枚举所有顶点
        if (isVisited[u] != 1) {//顶点未访问过
            BFS(u);//以BFS方式访问
        }
    }
}

int main() {
    n = 3;
    BFSTrave();
}