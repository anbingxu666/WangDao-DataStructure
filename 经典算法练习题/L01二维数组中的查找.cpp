//
// Created by HappyBing on 2019-12-28.
//

#include <iostream>
#include <vector>

using namespace std;

bool Find(int target, vector<vector<int>> array) {
    int i = array.size();//i为行数
    int j = array[0].size();//j为列数
    int startI = i - 1;
    int startJ = 0;
    while (startI >= 0 && startJ >= 0 && startJ <= j) {
        if (target > array[startI][startJ]) {
            startJ++;
        } else if (target < array[startI][startJ]) {
            startI--;
        } else {
            return true;
        }
    }
    return false;


}

