//
// Created by newLion on 2020-06-05.
//

#include <vector>
#include <queue>
#include <vector>

using namespace std;


priority_queue<int, vector<int>, less<int> > p; //大顶堆
priority_queue<int, vector<int>, greater<int> > q; //小顶堆

void Insert(int num) {
    //每次插入小顶堆的是当前大顶堆中最大的数
    //每次插入大顶堆的是当前小顶堆中最小的数
    //这样保证小顶堆中的数永远大于等于大顶堆中的数
    //中位数就可以方便地从两者的根结点中获取了

    if (p.empty() || num <= p.top())
        p.push(num);
    else
        q.push(num);
    if (p.size() == q.size() + 2) {
        q.push(p.top());
        p.pop();
    }

    if (p.size() + 1 == q.size()) {
        p.push(q.top());
        q.pop();
    }

}

double GetMedian() {
    //当前为偶数个，则取小顶堆和大顶堆的堆顶元素求平均 当前为奇数个，则直接从小顶堆中取元素即可
    return p.size() == q.size() ? (p.top() + q.top()) / 2.0 : p.top();
}