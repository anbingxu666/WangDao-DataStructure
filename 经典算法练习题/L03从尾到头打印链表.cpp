//
// Created by HappyBing on 2019-12-28.
//

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct ListNode {
    int val;
    struct ListNode *next;

    ListNode(int x) :
            val(x), next(NULL) {
    }
};

vector<int> printListFromTailToHead(ListNode *head) {
    stack<int> s;//创建一个栈
    vector<int> result;
    while (head != nullptr) {
        s.push(head->val);
        head = head->next;
    }
    while (!s.empty()) {
        result.push_back(s.top());
        s.pop();
    }
    return result;
}

//int main() {
//    ListNode *head = new ListNode(1);
//    head->next = new ListNode(2);
//    vector<int> a = printListFromTailToHead(head);
//    for (int x : a) {
//        cout << x << endl;
//    }
//}