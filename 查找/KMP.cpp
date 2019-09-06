//
// Created by Newmor on 2019-07-19.
//

#include <cstdio>
#include <string>
#include <iostream>

using namespace std;

void get_next(string s, int next[]) {
    int i = 0, j = 0;
    next[0] = 0;
    while (i < s.length() - 1) {
        if (j == 0 || s[i] == s[j]) {
            i++;
            j++;
            next[i] = j;
        } else {
            j = next[j];
        }
    }
}

int Index_KMP(string s, string t, int next[], int pos) {
    int i = pos, j = 1;
    while (i <= s.length() && j <= t.length()) {
        if (j == 0 || s[i] == t[j]) {//j == 0 是kmp算法设计的巧妙之处
            ++i;
            ++j;
        } else {
            j = next[j];
        }


    }
    if (j > t.length()) {
        return i - t.length();//返回位主串的起点下标
    } else {
        return 0;
    }

}

int main() {


    int next[100] = {0};
    string s = "aaacaaaba";
    string t = "aaaab";
    cout << t.length() << endl;

    get_next(t, next);
    for (int i = 0; i <= 10; ++i) {
        printf("%d\t", next[i]);
    }
    printf("\n");


    int i = Index_KMP(s, t, next, 1);
    printf("%d\n", i);


}