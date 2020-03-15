//2-2韩信点兵
#include <bits/stdc++.h>
using namespace std;
//没有多组数据 
int main(){
    int a, b, c, kase = 1;
    cin >> a >> b >> c;
    for (int i = 10; i <= 100; i++){
        if (i % 3==a && i % 5 == b && i % 7 ==c){
            cout <<"Case " << kase++ << ":" << i << " ";
            cout << endl;
            break;
        }
    }
    if (i > 100) cout << "No answer" << endl;
    return 0;
}
