//
// Created by HappyBing on 2020-01-16.
//
#include <stack>
#include <iostream>

using namespace std;
stack<int> dataS, minS;
int minV = 0x7fffffff;

void push(int value) {
    if (value < minV) {
        minV = value;
    }
    dataS.push(value);
    minS.push(minV);


}

void pop() {
    dataS.pop();
    minS.pop();

}

int top() {
    return dataS.top();
}

int min() {
    return minS.top();
}


//int main() {
//    push(5);
//    push(3);
//    push(11);
//    push(1);
//    while (!dataS.empty()) {
//        printf("-->%d\t", dataS.top());
//        dataS.pop();
//
//    }
//    while (!minS.empty()) {
//        printf("-->%d\t", minS.top());
//        minS.pop();
//    }
//
//}