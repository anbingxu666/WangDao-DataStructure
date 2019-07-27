//
// Created by Newmor on 2019-11-27.
//

#include <cstdio>

int f(int height){
    if(height == 0){
        return 0;
    }
    if(height == 1){
        return 1;
    }
    if(height==2){
        return 2;
    }
    return f(height-1)+f(height-2)+1;
}
int main(){
    printf("-->%d\n",f(6));
}