/*
 * @Descripttion:程序4-6 用函数交换变量（正确） 
 * @Author: Xiaobin Ren
 * @Date: 2020-03-19 08:45:24
 * @LastEditTime: 2020-03-19 08:49:41
 */

#include <iostream>

using namespace std;

void swap(int *a, int *b){
    int t = *a;
    *a = *b;
    *b = t;
}

int main(){
    int a = 3, b = 4;
    swap(&a, &b);
    cout << a << " " << b << endl;

    return 0;
}