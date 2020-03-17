/*
 * @Descripttion: // UVa 10082 : WERTYU
 * @Author: Xiaobin Ren
 * @Date: 2020-03-16 16:57:14
 * @LastEditTime: 2020-03-17 20:54:51
 */


#include <cstdio>

//常量数组 不需要指明大小, 编译器自动推断
char s[] = "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./"; 

int main(){
    int i, c;
    while ((c = getchar()) != EOF){
        for (i = 1; s[i] && s[i]!=c; i++); //第一个s[i]是判断 是否越界，遇到'\0'退出
        if (s[i]) putchar(s[i - 1]);
        else putchar(c); //这一步好像题目没要求？ 题目说输出的一定是错位后的字符
    }

    return 0;
}