//
// Created by newLion on 2020-06-07.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

string PrintMinNumber(vector<int> nums) {
    vector<string> str;
    for (int val : nums)
        str.push_back(to_string(val));
    sort(str.begin(), str.end(), [](string a, string b) {
        return a + b < b + a;
    });
    string ret = "";
    for (string s : str) ret += s;
    return ret;
}