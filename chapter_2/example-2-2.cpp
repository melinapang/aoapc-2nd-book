//完全平方数 7744问题
//对x的四舍五入技巧： floor（x + 0.5）

//方法1：
#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;

int main(){
    for (int i = 1;  i <= 9; i++){
        for (int j = 0; j <= 9; j++){
            int m = i * 1100 + j * 11;
            int n = floor(sqrt(m) + 0.5); //四舍五入技巧
            if (m == n * n) cout << m << endl;
        }
    }
    return 0;
}

//方法2：暴力枚举 + 取模判断 
#include <iostream>
#include <cmath>
#include <cstdio>

using namespace std;

int main(){
    for (int x = 1; ; x++){
        int n = x * x;
        if (n < 1000) continue;
        if (n > 9999) break;
        
        int hi = n / 100;
        int lo = n % 100;
        if (hi/10 == hi%10 && lo/10 == lo%10){
            printf("%d\n", n);
        }
    }
    
    return 0;
}