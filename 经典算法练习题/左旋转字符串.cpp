//
// Created by HappyBing on 2020-05-30.
//

#include <cstdio>
#include <string>

using namespace std;

string LeftRotateString(string str, int n) {
    reverse(str.begin(), str.end()); // 1 2 3 a b c      c b a 3 2 1
    reverse(str.begin(), str.begin() + str.size() - n); // abc321
    reverse(str.begin() + str.size() - n, str.end());// abc123
    return str;
}