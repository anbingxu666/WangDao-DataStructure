//
// Created by newLion on 2020-06-08.
//

#include <vector>
#include <unordered_map>
using namespace std;

void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
    unordered_map<int, int> mp;
    for (const int k : data)
        ++mp[k];
    vector<int> ret;
    for (const int k : data) {
        if (mp[k] == 1) {
            ret.push_back(k);
        }
    }
    *num1 = ret[0];
    *num2 = ret[1];
}