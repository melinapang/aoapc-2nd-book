//程序 3 - 1 逆序输出
//教材没有给出结尾标记  这里以0为结束标记
#include <cstdio>
#define maxn 105
int a[maxn];
int main()
{
    int x, n = 0;
    while (scanf("%d", &x) == 1 && x)
        a[n++] = x;
    for (int i = n - 1; i >= 1; i--)
        printf("%d ", a[i]);
    printf("%d\n", a[0]);
    return 0;
}