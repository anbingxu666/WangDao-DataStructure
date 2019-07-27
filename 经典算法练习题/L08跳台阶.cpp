//
// Created by HappyBing on 2020-01-06.
//

int jumpFloor(int number) {
    if(number == 1){
        return 1;
    }
    if( number == 2){
        return 2;
    }
    int pre = 1;
    int next = 2;
    int temp = 0;
    for(int i = 0; i < number - 2;i++){
        temp = pre + next;
        pre = next;
        next = temp;
    }
    return temp;
}