//
// Created by HappyBing on 2020-01-06.
//

#include <iostream>
#include <vector>

using namespace std;
//
//int Fibonacci(int n) {
//    if(n == 0){
//        return 0;
//    }
//    if(n == 1){
//        return 1;
//    }
//    return Fibonacci(n-1) + Fibonacci(n-2);
//}


int Fibonacci(int n) {
    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }
    int ii = 0;
    int jj = 1;
    int res = 0;
    for (int i = 0; i < n - 1; ++i) {
        res = ii + jj;
        ii = jj;
        jj = res;
    }
    return res;
}

//int main() {
//    cout << Fibonacci(6);
//}