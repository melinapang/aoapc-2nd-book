/*
例题3-6 环状序列（Circular Sequence, ACM/ICPC Seoul 2004, UVa1584）
处理环形问题技巧 多考虑取模
*/
#include <bits/stdc++.h>
#define maxn 105
using namespace std;

int cmp(const char *s, int p, int q){  //比较从下标 p， q 分别开始的字典序大小
    int n = strlen(s);
    for (int i = 0; i < n; i++){
        if (s[(p + i) % n] != s[(q + i) % n])
            return s[(p + i) % n] < s[(q + i) % n]; //char是可以直接拿来比较的
    }
    return 0; //相等
}

int main(){
    int T;
    char s[maxn];
    scanf("%d", &T);
    while (T--){
        scanf("%s", s);
        int ans = 0;
        int n =strlen(s);
        for (int i = 0; i < n; i++) if (cmp(s, i, ans)) ans = i; //从0 ，1 位置开始枚举
        for (int i = 0; i < n; i++)
            putchar(s[(ans + i) % n]);
        putchar('\n'); //细节注意putchar 是输出 char ，不能写成双引号
    }

    return 0;
}