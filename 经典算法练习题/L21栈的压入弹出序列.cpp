//
// Created by HappyBing on 2020-01-16.
//
/*输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否可能为该栈的弹出顺序。假设压入栈的所有数字均不相等。例如序列1,2,3,4,5是某栈的压入顺序，序列4,5,3,2,1是该压栈序列对应的一个弹出序列，但4,3,5,1,2就不可能是该压栈序列的弹出序列。（注意：这两个序列的长度是相等的）*/
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

bool IsPopOrder(vector<int> pushV, vector<int> popV) {
    if (popV.size() == 0 || popV.size() == 0 || popV.size() != pushV.size()) {
        return false;
    }
    stack<int> s;//用一个栈模拟入栈过程
    int j = 0;//记录模拟入栈过程中popV中的元素的下标
    for (int i = 0; i < pushV.size(); ++i) {
        s.push(pushV[i]);//将入栈序列的元素入栈
        while (!s.empty() && s.top() == popV[j]) {
            s.pop();
            j++;
        }
    }
    return s.empty();
}

//int main(){
//    vector<int> push = {1,2,3,4,5};
//    vector<int> pop = {4,5,3,2,1};
//    cout << IsPopOrder(push,pop)<< endl;
//
//}

