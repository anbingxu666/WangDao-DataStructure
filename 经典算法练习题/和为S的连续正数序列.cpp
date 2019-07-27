//
// Created by HappyBing on 2020-06-01.
//
#include <cstdio>
#include <vector>

using namespace std;

vector<vector<int> > FindContinuousSequence(int sum) {
    int first = 1;
    int second = 2;
    vector<vector<int> > allRes;
    while (first < second) {
        int currSum = (first + second) * (second - first + 1) / 2;
        if (currSum < sum) {
            ++second;
        } else if (currSum > sum)
        {
            ++first;
        } else{
            vector<int> oneRes;
            for(int i = first;i<=second;++i){
                oneRes.push_back(i);
            }
            ++first;

            allRes.push_back(oneRes);
        }
    }
    return allRes;


}