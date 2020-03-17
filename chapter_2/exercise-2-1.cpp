/*
 * @Descripttion: 2-1 水仙花数
 * @Author: Xiaobin Ren
 * @Date: 2020-03-15 15:00:15
 * @LastEditTime: 2020-03-17 20:59:31
 */

#include <bits/stdc++.h>
using namespace std;

int main(){

    for (int i = 100; i <= 999; i++){
        int a = i / 100; //百位
        int b = i % 10; // 个位
        int c = (i - a*100 - b)/10;
        if (i == a*a*a + b*b*b + c*c*c) cout << i << endl;
    }
    return 0;
}
