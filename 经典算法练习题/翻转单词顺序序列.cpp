//
// Created by newLion on 2020-06-10.
//

#include <string>

using namespace std;

string ReverseSentence(string str) {
    if (str.empty())
        return str;
    int i = 0, sz = str.size();
    while (i < sz && str[i] == ' ') ++i;
    if (i == sz)
        return str;


    string ret = ""; //结果数组
    string tmp = ""; //临时结果
    bool hasstr = false;
    for (int i = sz - 1; i >= 0; --i) {
        // 合并一个单词
        if (str[i] != ' ') {
            tmp = str[i] + tmp;;
            hasstr = true;
        }
            // 找到一个单词，将单词合并到结果串中
        else if (str[i] == ' ' && hasstr) {
            ret = ret + tmp + " ";
            tmp = "";
            hasstr = false;
        }
    }
    if (tmp != "")
        ret += tmp;
    return ret;

}