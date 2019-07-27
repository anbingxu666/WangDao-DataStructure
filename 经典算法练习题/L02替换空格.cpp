//
// Created by HappyBing on 2019-12-28.
//

#include <string>
#include <iostream>

using namespace std;

void replaceSpace(char *str, int length) {
    string s(str);//char数组转为字符串
    int i = 0;
    //查找空格并且替换
    while ((i = s.find(' ', i)) > -1) {
        s.erase(i, 1);
        s.insert(i, "%20");
    }
    //将string转会char数组
    auto ret = s.c_str();
    strcpy(str, ret);
}