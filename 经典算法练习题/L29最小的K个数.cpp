////
//// Created by HappyBing on 2020-01-26.
////
//
////输入n个整数，找出其中最小的K个数。例如输入4,5,1,6,2,7,3,8这8个数字，则最小的4个数字是1,2,3,4,。
//
//
//#include <vector>
//#include <iostream>
//#include <algorithm>
//#include <queue>
//
//using namespace std;
//
//
//vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
//    priority_queue<int> Q;//当成堆来用
//    vector<int> res;
//    if (input.size() < k || k <= 0) {//特殊情况
//        return res;
//    }
//
//    for (int i = 0; i < input.size(); ++i) {
//        //将最小堆k个元素进入堆
//        if (Q.size() < k) {
//            Q.push(input[i]);
//        } else if (input[i] < Q.top()) {
//            Q.pop();
//            Q.push(input[i]);
//        }
//    }
//    while (!Q.empty()) {
//        res.push_back(Q.top());
//        Q.pop();
//    }
//    return res;
//
//}
//
//int main() {
//    vector<int> input = {4, 5, 1, 6, 2, 7, 3, 8};
//    for (int x : input) {
//        cout << x << endl;
//    }
//    return 0;
//}