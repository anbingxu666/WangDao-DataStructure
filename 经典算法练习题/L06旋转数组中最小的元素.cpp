//
// Created by HappyBing on 2020-01-05.
//

#include <iostream>
#include <vector>

using namespace std;
int minNumberInRotateArray(vector<int> rotateArray) {
    if(rotateArray.size()==0){
        return 0;
    }
    int i = 0;
    int j = (i+1)%rotateArray.size();
    int count = 0;
    while(rotateArray[j]>=rotateArray[i]&&count<rotateArray.size()){
        i++;
        j = (i+1)%rotateArray.size();
        count++;
    }
    return rotateArray[(i+1)%rotateArray.size()];
}
//
//int main(){
//    vector<int> a = {1,0,1,1,1};
//    cout<<minNumberInRotateArray(a);
//}