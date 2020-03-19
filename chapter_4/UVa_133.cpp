/*
 * @Descripttion: 例题4-3 救济金发放（The Dole Queue, UVa 133） 
 * @Author: Xiaobin Ren
 * @Date: 2020-03-19 20:29:31
 * @LastEditTime: 2020-03-19 21:36:30
 */


#include <bits/stdc++.h>
#define maxn 25

int n, k, m, a[maxn];

//逆时针走t步，步长是d（-1表示顺时针走），返回新位置
int go(int p, int d, int t){
    while(t--){
        // 注意的此处的 模 n 再加 1， 是因为数组下标是从第一个开始的
        do { p = (p+d+n-1) % n + 1; } while(a[p] == 0); //走到下一个非0数字
    }
    return p;
}

int main(){

    while (scanf("%d%d%d", &n, &k, &m) == 3 && n){
        for (int i = 1; i <= n; i++) a[i] = i;
        int left = n; //剩下的人数
        int p1 = n, p2 = 1;
        while (left){
            p1 = go(p1, 1, k);
            p2 = go(p2, -1, m);
            printf("%3d", p1); left--;
            if(p2 != p1) { printf("%3d", p2); left--; }
            a[p1] = a[p2] = 0;
            if (left) printf(",");
        }
        printf("\n");
    }
    return 0;
}
