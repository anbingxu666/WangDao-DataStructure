//
// Created by 安炳旭 on 2019-08
//

#include <cstdio>
#include <queue>
#include <algorithm>

#define INF 9999
#define MAX 100
using namespace std;

int graph[MAX][MAX] = {
        //0   1     2   3       4
        {0,   1,    1,  INF,    INF},//0
        {INF, 0,    INF, 1,     INF},//1
        {INF, INF,  0,  INF,    INF},//2
        {INF, INF,  INF, 0,     1},  //3
        {INF, INF,  INF, INF,   0}   //4
};//图是无权图 INF代表不可达

int d[MAX] = {0};//初始化距离数组

//计算无权图的最短距离
void BFSMinDistance(int i, int n) {
    queue<int> myQueue;//初始化队列
    bool isVisited[MAX] = {false};//记录是否被访问的数组
    fill(d, d + MAX, INF);//将距离初始化INF

    myQueue.push(i);//入队列
    d[i] = 0;//距离0
    isVisited[i] = true;//已经被访问
    printf("-->%d\t",i);//打印访问的路径
    while (!myQueue.empty()) {
        int v = myQueue.front();//取出队首
        myQueue.pop();//删除队首
        for (int w = 0; w < n; ++w) {
            if (!isVisited[w] && graph[v][w] != INF) {
                printf("-->%d\t",w);//访问
                d[w] = d[v] + 1;//其实就是在这里多加了一个计算长度的语句
                isVisited[w] = true;
                myQueue.push(w);
            }
        }
    }

}

int main() {
    BFSMinDistance(0, 5);
    printf("\n下面是距离\n");
    for (int i = 0; i < 5; ++i) {
        printf("距离--->%d\t", d[i]);
    }
}