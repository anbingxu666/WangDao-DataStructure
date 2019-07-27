//
// Created by newLion on 2020-06-08.
//

#include <vector>

using namespace std;

class Solution {
private:
    const int kmod = 1000000007;
public:
    int InversePairs(vector<int> data) {
        int ret = 0;
        merge_sort__(data, 0, data.size() - 1, ret);
        return ret;
    }


    void merge_sort__(vector<int> &arr, int l, int r, int &ret) {
        if (l >= r) {
            return;
        }

        int mid = l + ((r - l) >> 1);
        merge_sort__(arr, l, mid, ret);
        merge_sort__(arr, mid + 1, r, ret);
        merge__(arr, l, mid, r, ret);
    }

    void merge__(vector<int> &arr, int l, int mid, int r, int &ret) {
        vector<int> tmp(r - l + 1);
        int i = l, j = mid + 1, k = 0;

        while (i <= mid && j <= r) {
            if (arr[i] > arr[j]) {
                tmp[k++] = arr[j++];
                // 奥妙之处
                ret += (mid - i + 1);
                ret %= kmod;
            } else {
                tmp[k++] = arr[i++];
            }
        }

        while (i <= mid) { //左边有剩余的
            tmp[k++] = arr[i++];
        }
        while (j <= r) { //右边有剩余的
            tmp[k++] = arr[j++];
        }

        for (k = 0, i = l; i <= r; ++i, ++k) { //还原
            arr[i] = tmp[k];
        }
    }
};