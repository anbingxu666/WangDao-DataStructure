//
// Created by HappyBing on 2020-06-01.
//

#include <cstdio>
#include <vector>

using namespace std;

// 输入一个递增排序的数组和一个数字S，在数组中查找两个数，使得他们的和正好是S，如果有多对数字的和等于S，输出两个数的乘积最小的。
vector<int> FindNumbersWithSum(vector<int> array, int sum) {
    vector<int> res;
    if (array.size() == 0)
        return res;
    int left = 0;
    int right = array.size() - 1;
    while (left < right) {
        if (array[left] + array[right] == sum) {
            res.push_back(array[left]);
            res.push_back(array[right]);
            break;
        } else if (array[left] + array[right] < sum) {
            left++;
        } else {
            right--;
        }
    }
    return res;
}