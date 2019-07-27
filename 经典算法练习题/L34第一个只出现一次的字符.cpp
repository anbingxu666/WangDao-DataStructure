//
// Created by HappyBing on 2020-05-30.
//

#include <iostream>
#include <map>
using namespace std;



int FirstNotRepeatingChar(string str) {
    map<char, int> mp;
    for(int i = 0; i < str.size(); ++i)
        mp[str[i]]++;
    for(int i = 0; i < str.size(); ++i){
        if(mp[str[i]]==1)
            return i;
    }
    return -1;
}