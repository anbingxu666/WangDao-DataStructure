//
// Created by HappyBing on 2020-06-02.
//

#include <vector>
using namespace std;
class Solution {
public:
    vector<int> multiply(const vector<int>& A) {
        vector<int> B(A.size(), 1);
        for (int i=1; i<A.size(); ++i) {// 下三角
            B[i] = B[i-1] * A[i-1]; // left[i]用B[i]代替
        }
        int tmp = 1;
        for (int j=A.size()-2; j>=0; --j) {// 上三角
            tmp *= A[j+1]; // right[i]用tmp代替
            B[j] *= tmp;
        }
        return B;
    }
};