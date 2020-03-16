/*
习题2-4 子序列的和
注意乘法溢出
多组数据要每次把sum归零
*/

#include <bits/stdc++.h>
using namespace std;

int main(){

    int n, m, kase = 0;
    while (cin >> n >> m){
        double s = 0;
        if (n == 0 && m == 0) break;
        for (int i = n; i <= m; i++){
            s += (1.0/i) * (1.0/i);
        }
        kase++;
        cout << "Case " << kase << ":" ;
        printf("%.5f\n", s);
    }

    return 0;
}
