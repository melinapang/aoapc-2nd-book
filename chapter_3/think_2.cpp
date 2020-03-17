/*
思考题：题目2（统计字符1的个数）
*/

/*
原代码：

        #include <cstdio>
        #define maxn 10000000 + 10

        int main(){
            char s[maxn];
            scanf("%s", s);
            int tot = 0;
            for (int i = 0; i < strlen(s); i++)
                if (s[i] == 1) tot++;
           printf("%d", tot); 
        }
*/

/*
修改：   错误1： 没有导入 <cstring> 头文件 编译错误
        错误2： scanf 无法读取空格， 应该用 getchar()
        错误3：直接拿 s[i] 和数字比较 应该为和char比较
        效率： 每次循环都要调用一次 getchar(), 应该把getchar()常量放在循环外

*/

//正确代码:
#include <bits/stdc++.h>
#define maxn 10000000 + 10

using namespace std;

int main(){
    //char s[maxn];
    int tot = 0;
    for (int i = 0; i < maxn; i++){
        char c = getchar();
        if (c == '1') tot++;
        if (c == '\n') break;
    } 
    cout << tot << endl;

    return 0;
}