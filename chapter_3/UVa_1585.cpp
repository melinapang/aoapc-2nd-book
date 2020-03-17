/*
 * @Descripttion: 习题3-1 得分（Score, ACM/ICPC Seoul 2005, UVa1585）
 * @Author: Xiaobin Ren
 * @Date: 2020-03-17 11:41:36
 * @LastEditTime: 2020-03-17 20:55:43
 */



#include <bits/stdc++.h>
#define max 100

using namespace std;

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        char s[100];
        int score = 0, count = 0; //用变量 count 来维护当前最长的序列，遇见 ‘X’就为 0
        scanf("%s", s);
        for (int i = 0; i < max; i++)
        {
            if (s[i] == 'X')
            {
                count = 0;
            }
            if (s[i] == 'O')
            {
                ++count;
                score += count;
            }
            if ((s[i] != 'X') && (s[i] != 'O')) break; //数组边界，当然也可以用strlen(),我这里有点啰嗦
        }
            cout << score << endl;
    }
    return 0;
}