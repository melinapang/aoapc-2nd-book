/*
 * @Descripttion: 习题5-3 卡片游戏（Throwing cards away I, UVa 10935） 
 * @Author: Xiaobin Ren
 * @Date: 2020-03-23 22:58:27
 * @LastEditTime: 2020-03-23 23:16:51
 */

#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    while (scanf("%d", &n) == 1 && n){
        // n == 1 的情况特判：
        // if(n == 1){
        //     printf("Discarded cards:\n");
        //     printf("Remaining card: 1\n");
        //     break;
        // }
        //n >= 1 情况, 一并考虑特判：
        queue<int> q;
        for (int i = 1; i <= n; i++) q.push(i);
        printf("Discarded cards:");
        bool first = true;  //开头的输出格式
        while (q.size() >= 2){
            if (first){ first = false; printf(" %d", q.front());}
            else printf(", %d", q.front());
            q.pop();
            q.push(q.front());
            q.pop();
        }
        printf("\nRemaining card: %d\n", q.front());
    }
    return 0;
}