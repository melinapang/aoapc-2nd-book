//习题2-5 分数化小数
//手动模拟高精度除法

#include <iostream>
using namespace std;
int n, m[110];
int main()
{
    int a, b, c, k = 0;
    while (cin >> a >> b >> c && (a || b || c))
    {
        k++;
        n = a / b; //商
        a = a % b;
        m[0] = 0; //整数最后一位， m[1] 是小数位开始
        for (int i = 1; i <= c; i++)
        {
            m[i] = a * 10 / b;
            a = a * 10 % b;
        }
        if (a * 10 / b >= 5) //此时a的值是最后一位小数，判断是否四舍五入
        {
            for (int i = c; i >= 0; i--)
            {
                m[i] = m[i] + 1;
                if (m[i] < 10)
                    break;
                else
                {
                    m[i] -= 10;
                }
            }
            n = n + m[0];                 //整数部分进位处理。
            printf("Case %d: %d.", k, n); //打印整数部分及小数点
            for (int i = 1; i <= c; i++)
                printf("%d", m[i]); //打印小数部分。
            printf("\n");
        }
    }
}