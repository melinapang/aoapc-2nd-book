/*
 * @Descripttion: 例题3-4 猜数字游戏的提示（Master-Mind Hints, UVa 340）
 * @Author: Xiaobin Ren
 * @Date: 2020-03-16 18:55:12
 * @LastEditTime: 2020-03-17 20:57:51
 */


#include <bits/stdc++.h>
#define maxn 1010
using namespace std;

int main(){
    int n, a[maxn], b[maxn];
    int kase = 0;
    while (scanf("%d", &n) == 1 && n){ // n == 0 时候输入结束
        printf("Game %d:\n", ++kase);
        for (int i = 0; i < n; i++) scanf("%d", &a[i]); //答案
        for (; ;){
            int A = 0, B = 0;
            for (int i = 0; i < n; i++){
                scanf("%d", &b[i]);
                if (a[i] == b[i]) A++;
            }
            if (b[0] == 0) break;  //正常的猜测序列不会有0，所以只判断第一个数是否为0即可
            for (int d = 1; d <= 9; d++){
                int c1 =0, c2 = 0; //统计数字 d 在俩数组中各出现了多少次
                for (int i = 0; i < n; i++){
                    if (a[i] == d) c1++;
                    if (b[i] == d) c2++;
                }
                B += min(c1, c2);
            }
            printf("    (%d,%d)\n", A, B-A);
        }
    }
    return 0;
}

