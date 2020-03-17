/*
 * @Descripttion: 例题3-3 回文词（Palindromes, UVa401）
 * @Author: Xiaobin Ren
 * @Date: 2020-03-16 17:18:50
 * @LastEditTime: 2020-03-17 20:57:29
 */


#include <cstdio>
#include <cctype>
#include <cstring>
using namespace std;

const char* rev = "A   3  HIL JM O   2TUVWXY51SE Z  8 ";
const char* msg[] = {"not a palindrome", "a regular palindrome", 
                    "a mirrored string", "a mirrored palindrome"};
char r(char ch){
    if (isalpha(ch)) return rev[ch - 'A'];
    return rev[ch - '0' + 25];
}

int main(){
    char s[30];
    while (scanf("%s", s) == 1){
        int len = strlen(s);
        int p = 1, m = 1;
        for (int i = 0; i < (len + 1) / 2; i++){
            if (s[i] != s[len - 1 - i]) p = 0; //不是回文串
            if (r(s[i]) != s[len - 1 -i]) m = 0; //不是镜像串
        }
        //注意此处的 printf 是一个 trick， m*2+p的范围是0-3,恰好对应msg数组中的选项。
        printf("%s -- is %s.\n\n", s, msg[m * 2 + p]);
    }
    return 0;
}