/*
 * @Descripttion:例题6-4  破损的键盘（又名：悲剧文本）（Broken  Keyboard（a.k.a.  Beiju  Text）,UVa 11988） 
 * @Author: Xiaobin Ren
 * @Date: 2020-03-24 16:51:54
 * @LastEditTime: 2020-03-24 17:11:18
 */

#include <bits/stdc++.h>

//using namespace std;

const int maxn = 100000 + 5;
int last, cur, next[maxn];
char s[maxn];

int main(){
    while (scanf("%s", s + 1) == 1){  //从 下标 1 开始读入数据
    int n = strlen (s + 1);
    last = cur = 0;
    next[0] = 0;
    for (int i = 1; i <= n; i++){
        char ch = s[i];
        if (ch == '[') cur = 0;
        else if (ch == ']') cur = last;
        else{
            next[i] = next[cur]; //从光标处开始往出读
            next[cur] = i;
            if (cur == last) last = i; //不断更新当前字符串尾的位置
            cur = i;  //移动光标
        }
    }
    for(int i = next[0]; i != 0; i = next[i])
        printf("%c", s[i]);
    printf("\n");
    }
    return 0;
}