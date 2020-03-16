//程序2 - 12 改bug之后的：
#include <iostream>
#include <cmath>
#include <cstdio>

#define INF 1000000000
typedef long long ll;

using namespace std;

int main(){

    int x, n = 0, kase = 0;
    /*
    kase 计数器 常用于多种数据输出之间要有空行
    但是第一组没有空行 所以先将kase置为0 
    在第一次if判断kase之后 kase ++
    */
    while(scanf("%d", &n) == 1 && n){
        int min = INF, max = -INF;
        int s = 0;
        for (int i = 0; i < n; i++) {
            scanf("%d", &x);
            s += x;
            if (x < min) min = x;
            if (x > max) max = x;
        }
        if (kase) printf("\n");
        printf("Case %d: %d %d %.3f\n", ++kase, min, max, (double)s/n);
        
    }
  return 0;
}