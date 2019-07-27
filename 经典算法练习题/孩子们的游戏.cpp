//
// Created by newLion on 2020-06-09.
//
#include <vector>
#include <list>

using namespace std;

class Solution {
public:
    int LastRemaining_Solution(int n, int m) {
        if (n <= 0) return -1;
        list<int> kids;
        for (int i = 0; i < n; ++i) {
            kids.push_back(i);
        }
        int index = -1; //初始化为-1
        while (kids.size() > 1) {
            int count = 0;
            while (count < m) {
                count++; //数数 从0开始数到m-1
                index++; //记录当前数到的位置
                if (index == kids.size()) {
                    index = 0; //已经数完一圈重新开始
                }
            }
            auto it = kids.begin();
            std::advance(it, index); // 让it向后移动index个位置
            kids.erase(it);
            index--;
        }
        return kids.back();
    }

    // 递归
    int LastRemaining_Solution2(int n, int m) {

        {
            if (n == 0)
                return -1;
            if (n == 1)
                return 0;
            else
                return (LastRemaining_Solution(n - 1, m) + m) % n;
        }
    }

    // 迭代
    int LastRemaining_Solution3(int n, int m) {
        if (n <= 0) return -1;
        int index = 0;
        for (int i = 2; i <= n; ++i) {
            index = (index + m) % i;
        }
        return index;
    }
};
