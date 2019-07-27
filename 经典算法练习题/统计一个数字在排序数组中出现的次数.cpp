//
// Created by HappyBing on 2020-05-20.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// 时间复杂度O（n）
int GetNumberOfK(vector<int> data, int k) {
    int num = 0;
    for (int i = 0; i < data.size(); ++i) {
        if (data[i] == k)
            num++;
        if (data[i] > k)
            break;
    }
    return num;
}
// 时间复杂度O（logn）
int GetNumberOfK1(vector<int> data, int k) {

    auto l = lower_bound(data.begin(), data.end(), k);
    auto r = upper_bound(data.begin(), data.end(), k);
    return r - l;
}