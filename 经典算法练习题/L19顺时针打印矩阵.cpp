//
// Created by HappyBing on 2020-01-16.
//

#include <vector>
#include <iostream>

using namespace std;

vector<int> printMatrix(vector<vector<int> > matrix) {
    vector<int> res;
    int row = matrix.size();
    int col = matrix[0].size();

    if (row == 0 || col == 0) {
        return res;
    }
    /*
     * left     right
     *
     *  1 2  3  4   top
     *  5 6  7  8   top+1
     *  9 10 11 12  bottom
     *
     *
     *
     * */
    int top = 0,bottom = row - 1,left = 0,right = col-1;
    while(top <= bottom && left<= right){
        for(int i = left ; i <= right ;++i){
            res.push_back(matrix[top][i]);
        }
        for(int i = top + 1;i <= bottom ;++i){
            res.push_back(matrix[i][right]);
        }
        for(int i = right - 1;i >= left && top < bottom ;--i){
            res.push_back(matrix[bottom][i]);
        }
        for(int i = bottom -1;i > top && left < right;--i){
            res.push_back(matrix[i][left]);
        }
        ++top;
        ++left;
        --bottom;
        --right;

    }
    return res;
}