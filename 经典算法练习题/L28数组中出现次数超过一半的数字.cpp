//
// Created by HappyBing on 2020-01-26.
//
#include <vector>
#include <iostream>
#include <map>

using namespace std;

int MoreThanHalfNum_Solution(vector<int> numbers) {


    int size = numbers.size() / 2;
    sort(numbers.begin(), numbers.end());//排序
    for (int i = 0; i + size < numbers.size(); i++) {
        if (numbers[i] == numbers[i + size])
            return numbers[i];
    }
    return 0;
}


//或者使用map



int MoreThanHalfNum_Solution2(vector<int> numbers) {
    map<int,int> numbersMap;
    for(int i=0;i<numbers.size();i++){
        numbersMap[numbers[i]]+=1;

    }
    int max =numbers.size()/2;
    int number=0;
    for (map<int, int>::iterator it = numbersMap.begin(); it != numbersMap.end(); it++) {
        if(max<(it->second)){
            number=it->first;
        }
    }
    return number;
}