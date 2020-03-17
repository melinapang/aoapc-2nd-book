/*
 * @Descripttion: 习题2-3 倒三角形
 * @Author: Xiaobin Ren
 * @Date: 2020-03-15 15:07:15
 * @LastEditTime: 2020-03-17 21:00:40
 */


#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int k = 0;
    int j;
    while (n > 0){
        for (int i = 0; i < k; i++){
            cout << " ";
        }
        k++;
        for ( j = 2 * n - 1; j > 0; j--) cout << "#";
        j = j - 2;
        for (int i = 0; i < k; i++){
            cout << " ";
        }
        cout << endl;
        n = n - 1;
    }

    return 0;
}
