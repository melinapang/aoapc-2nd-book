/*
习题2-6 排列
这个做法有点状压dp的味道 复杂度 O(n)

因为abc:def:ghi=1：2：3，
所以abc最大不超过333，最小不小于111，
以abc为基数，用abc来表示def和ghi，
用一个数组储存1-9，共9个数，将用过的数里存为1，
输出时判断数组加起来是否为9即可 
*/
#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    int s[10] = {0};
    for (int i = 111; i < 333; i++)
    {
            memset(s, 0, sizeof s); //每次检验一个数后数组初始化
            s[i / 100] = 1;
            s[i / 10 % 10] = 1;
            s[i % 10] = 1;
            int j = 2 * i;
            s[j / 100] = 1;
            s[j / 10 % 10] = 1;
            s[j % 10] = 1;
            int k = 3 * i;
            s[k / 100] = 1;
            s[k / 10 % 10] = 1;
            s[k % 10] = 1;
            int sum = 0;
            for (int m = 1; m < 10; m++) sum += s[m];
            if (sum == 9) cout << i << " " << j << " " << k << endl;
    }
    return 0;
}
