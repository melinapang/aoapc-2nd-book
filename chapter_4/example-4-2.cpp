/*
 * @Descripttion: 程序 4-2  组合数
 * @Author: Xiaobin Ren
 * @Date: 2020-03-18 23:50:27
 * @LastEditTime: 2020-03-19 00:04:20
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

/*
    此函数用到的技巧是 组合数的性质, 以及先从 n！中除掉 m 那部分 再除分母 (n - m)!
    当 m < n - m 时候 m = n - m; 
    意思就是 放大 m；
    放大 m 之后， 在第24行代码 就可以减少计算次数 优化时间
*/

ll cnm(int m, int n){
    if (m < n - m) m = n -m; //组合数的性质： c(n, m) = c(n, n-m)
    ll ans = 1;
    for (int i = m + 1; i <= n; i++) ans *= i; //放大 m 减少计算次数
    for (int i = 1; i <= n - m; i++) ans /= i;

    return ans;
}