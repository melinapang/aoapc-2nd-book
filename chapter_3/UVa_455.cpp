/*
 * @Descripttion:习题3-4 周期串（Periodic Strings, UVa455） 
 * @Author: Xiaobin Ren
 * @Date: 2020-03-18 10:54:08
 * @LastEditTime: 2020-03-18 16:38:29
 */


/*
    这题一开始我想复杂了 然后暴力枚举 + 各种边界处理 + 细节处理
    导致交上去一直 WA， 实际这题很简单：
    一般处理周期字符串的技巧就是枚举循环节 + 取模数判断
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int T; cin >> T;
    char s[128];
    while (T--)
    {
        memset(s, 0, sizeof(s));
        scanf("%s", s);
        int len = strlen(s);
        int j;
        for (int i = 1; i <= len; ++i) //此处的 i 就是周期 
            if (len%i == 0) 
            {
                for (j = i; j <= len; j++) //周期为 i  则直接从第 i 个元素开始判断
                    if (s[j] != s[j%i])
                        break;
                if (j == len) //没有周期 ， 也就是周期是字符串长度的情况
                {
                    cout << i << endl;
                    break;
                }
            }
        if (T)cout << endl;
    }
}