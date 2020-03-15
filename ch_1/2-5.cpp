//
// Created by Xiaobin Ren on 20/3/15.
//

#include <iostream>
using namespace std;
int n, m[110];
int main(){
    int a, b, c, k = 0;
    while (cin >> a >> b >> c && (a || b || c)){
        k++;
        n = a/b;
        a = a % b;
        m[0] = 0;
        for (int i = 1; i <= c; i++){
            m[i] = a * 10 / b;
            a = a * 10 % b;
        }
        if (a * 10 / b >= 5){
            for (int i = c; i >= 0; i--){
                m[i] = m[i] + 1;
            }
        }
    }

}

