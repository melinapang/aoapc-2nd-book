//程序2-7 阶乘之和 1！ + 2 ！ + ......n!
//有溢出风险
//clock() 函数的使用技巧 注意 
#include <iostream>
#include <cmath>
#include <cstdio>
typedef long long ll;

using namespace std;

int main(){
    int n, s = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++){
        int fac = 1;
        for (int j = 1; j <= i; j++){
            fac *= j;
        }
        s += fac;
    }
    
    printf("%d\n", s % 1000000);
    return 0;
}

//改进 每次乘/加之后立即取余
#include <iostream>
#include <cmath>
#include <cstdio>
#include <ctime> //时间函数
typedef long long ll;

using namespace std;

const int MOD = 1000000;

int main(){
    
    int n, s = 0;
    cin >> n;
    for (int i = 1; i <= n; i++){
        int fac = 1;
        for (int j = 1; j <= i; j++)
            fac = (fac * j) % MOD;
        s = (s + fac) % MOD;
    }
    
    cout << s << endl;
    //返回程序运行时间， 返回秒单位
    cout << "time:" << (double)clock()/CLOCKS_PER_SEC << endl; 
    return 0;
}