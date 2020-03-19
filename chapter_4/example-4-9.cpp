/*
 * @Descripttion:  程序4-9 计算左闭右开区间内的元素和（两种写法）
 * @Author: Xiaobin Ren
 * @Date: 2020-03-19 09:22:49
 * @LastEditTime: 2020-03-19 09:29:46
 */


#include <iostream>

using namespace std;

//method1:
int sum1(int *begin, int *end){
    int n = end - begin;
    int ans = 0;
    for (int i = 0; i < n; i++){
        ans += begin[i];
    }
    return ans;
}

int sum2(int *begin, int *end){
    int ans = 0;
    for (int *p = begin; p != end; p++){
        ans += *p;
    }
    return ans;
}

//test
int main(){
    int a[] = {2,3,4,1};
    cout << sum1(a+1, a+4) << endl;
    cout << sum2(a+1, a+4) << endl;

    return 0;
}