//
// Created by HappyBing on 2020-06-02.
//

// 请实现一个函数用来找出字符流中第一个只出现一次的字符。例如，当从字符流中只读出前两个字符"go"时，第一个只出现一次的字符是"g"。当从该字符流中读出前六个字符“google"时，第一个只出现一次的字符是"l"。
#include <cstdio>
#include <cmath>
#include <string>

using namespace std;


class Solution {
public:
    //Insert one char from stringstream
    string s;
    char hash[256] = {0};

    void Insert(char ch) {
        s += ch;
        hash[ch]++;
    }

    //return the first appearence once char in current stringstream
    char FirstAppearingOnce() {

        int size = s.size();
        for (int i = 0; i < size; ++i) {
            if (hash[s[i]] == 1)
                return s[i];
        }
        return '#';
    }

};