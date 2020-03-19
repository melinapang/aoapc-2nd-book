/*
 * @Descripttion: 程序4-8 计算数组的元素和（正确） 
 * @Author: Xiaobin Ren
 * @Date: 2020-03-19 09:19:25
 * @LastEditTime: 2020-03-19 09:22:08
 */

#include <iostream>

using namespace std;

int sum(int *a, int n){
    int ans = 0;
    for (int i = 0; i < n; i++){
        ans += a[i];
    }
    return ans;
}

//test
int main(){
    int a[] = {1,2,1,1,1};
    cout << sum(a, 4) << endl;

    return 0;
}