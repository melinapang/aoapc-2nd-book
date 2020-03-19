/*
 * @Descripttion: 例题4-3 救济金发放（The Dole Queue, UVa 133） 
 * @Author: Xiaobin Ren
 * @Date: 2020-03-19 20:29:31
 * @LastEditTime: 2020-03-19 23:19:56
 */
/*
    此题就是约瑟夫环的加强版，
    用到主要的 (p + n - 1 + d ) %N + 1 技巧
    之后在代码里面解释这个算法
*/

#include <bits/stdc++.h>
#define maxn 25

int n, k, m, a[maxn];

//逆时针走t步，步长是d（-1表示顺时针走），返回新位置
int go(int p, int d, int t){
    while(t--){
        do { p = (p+d+n-1) % n + 1; } while(a[p] == 0); //走到下一个非0数字
    }
    /*
        p = (p+d+n-1) % n + 1：
        首先是，模 n 可以将一个长度为 n 的数组抽象成环来操作，至于担心数组下标从 1 开始，
        有可能取模之后下标会为 0，但是0位置又没有元素，该技巧可以避免“走到下标为 0” 这个问题。
        p + n - 1，对于任意的位置 p，加 n - 1之后再取模，就可将其移到自己在“某方向”旋转的后一个位置，
        即相邻的位置， 然后如果是顺时针， 该位置且在 p 的左边，那么就不用再动了，但是 d = -1，
        所以最后的 + 1，消去了这一步。如果是逆时针，那么还要再逆时针走 2 步， 此时 d = 1，
        此公式恰好是 d + 1 = 2。 妙不可言。         
    */
    return p;
}

int main(){

    while (scanf("%d%d%d", &n, &k, &m) == 3 && n){
        for (int i = 1; i <= n; i++) a[i] = i;
        int left = n; //剩下的人数
        int p1 = n, p2 = 1;
        while (left){
            p1 = go(p1, 1, k); //逆时针数 k 个人
            p2 = go(p2, -1, m); //顺时针数 m 个人
            /*
                这两个 go()的参数意义:
                数 x 个人，是从 该人开始数的， 所以走的是 x - 1 步。
                这等价于 从该位置的前一个位置， 多走一步， 即走 x 步， 也可以走到。
            */
            printf("%3d", p1); left--;
            if(p2 != p1) { printf("%3d", p2); left--; }
            a[p1] = a[p2] = 0;
            if (left) printf(",");
        }
        printf("\n");
    }
    return 0;
}
