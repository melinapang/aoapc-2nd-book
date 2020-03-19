/*
 * @Descripttion: 例题4-2 刽子手游戏（Hangman Judge, UVa 489） 
 * @Author: Xiaobin Ren
 * @Date: 2020-03-19 19:06:49
 * @LastEditTime: 2020-03-19 20:28:41
 */


/*
    这道题的题意还是比较模糊的， 输入一个答案串， 一个自己的串
    猜过的不能再猜， 则猜过之后就将其改为 ' '
    这样一来 即使你重复猜你也必输
*/


#include <bits/stdc++.h>
#define maxn 100


int left, chance;
char s[maxn], s2[maxn];
int win, lose;

void guess(char ch){           //猜测每一个字符
    int bad = 1;
    int sz = strlen(s);
    for (int i = 0; i < sz; i++){
        if (s[i] == ch){
            left--;
            s[i] = ' ';
            bad = 0;
        }
    }
        if(bad) chance--;
        if (!chance) lose = 1;
        if (!left) win = 1; 

}

int main(){

    int rnd;
    while (scanf("%d%s%s", &rnd, s, s2) == 3 && rnd != -1){
        printf("Round %d\n",rnd);
        win = lose = 0;
        left = strlen(s);
        chance = 7;
        int sz = strlen(s2);
        for (int i = 0; i < sz; i++){
            guess(s2[i]);
            if (win || lose) break;
        }
        if (win) printf("You win.\n");
        else if(lose) printf("You lose.\n");
        else printf("You chickened out.\n");
    }
    return 0;
}