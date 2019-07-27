//
// Created by HappyBing on 2020-01-26.
//

//输入一个字符串,按字典序打印出该字符串中字符的所有排列。例如输入字符串abc,则打印出由字符a,b,c所能排列出来的所有字符串abc,acb,bac,bca,cab和cba。
#include <iostream>
#include <vector>

using namespace std;


void swap(char &fir, char &sec) {
    char temp = fir;
    fir = sec;
    sec = temp;
}

void Permutation(string str, vector<string> &result, int begin) {
    if (begin == str.size() - 1) {
        if (find(result.begin(), result.end(), str) == result.end()) {
            // 如果result中不存在str，才添加；避免aa和aa重复添加的情况
            result.push_back(str);
        }
    } else {
        for (int i = begin; i < str.size(); ++i) {
            swap(str[i], str[begin]);
            Permutation(str, result, begin + 1);
            swap(str[i], str[begin]); // 复位，用以恢复之前字符串顺序，达到第一位依次跟其他位交换的目的
        }
    }
}

vector<string> Permutation(string str) {
    vector<string> res;
    if (str.empty()) {
        return res;
    }
    Permutation(str, res, 0);
    sort(res.begin(), res.end());
    return res;
}