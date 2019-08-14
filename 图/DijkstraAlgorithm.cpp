//
// Created by 安炳旭 on 2019-08-14.
//
#include <cstdio>
#include <iostream>

#define MAX 1000
#define INF 999999
using namespace std;

int n = 5, G[MAX][MAX] = {
        //0   1     2   3       4
        {0,   1,   6,   INF, 5},//0
        {INF, 0,   INF, 3,   2},//1
        {INF, INF, 0,   INF, INF},//2
        {INF, INF, INF, 0,   4},  //3
        {INF, INF, INF, INF, 0}   //4
};
int d[MAX];
bool isVisited[MAX] = {false};

void dijkstra(int s) {
    fill(d, d + MAX, INF);//初始距离为INF
    d[s] = 0;//s到自身到距离为0
    for (int i = 0; i < n; i++) {
        int u = -1, MIN = INF;//u用来记录最小值到下标

        //找到距离当前顶点最小距离到顶点 并记录下标和距离
        for (int j = 0; j < n; ++j) {
            if (!isVisited[j] && d[j] < MIN) {
                u = j;
                MIN = d[j];
            }
        }
        if (u == -1) return;//说明不连通
        isVisited[u] = true;
        for (int v = 0; v < n; v++) {
            if (!isVisited[v] && G[u][v] != INF && d[u] + G[u][v] < d[v]) {
                d[v] = d[u] + G[u][v];//松弛操作
            }
        }

    }
}

int main() {
    dijkstra(0);
    for (int i = 0; i < n; ++i) {
        printf("距离->%d\t",d[i]);
    }
    return 0;
}