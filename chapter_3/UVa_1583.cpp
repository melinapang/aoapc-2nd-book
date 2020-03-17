/*
 * @Descripttion:习题3-2 分子量（Molar Mass, ACM/ICPC Seoul 2007, UVa1586） 
 * @Author: Xiaobin Ren
 * @Date: 2020-03-16 19:40:16
 * @LastEditTime: 2020-03-17 20:53:57
 */


#include <bits/stdc++.h>

using namespace std;

// int main2; //方法2

//方法1： 暴力枚举 复杂度 O(n) 但是这种方法有局限性，对于求大量数据 就不行了

int main(){
    int n, sum = 0, flag = 0;
    cin >> n;
    for (int i = 1; i < n; i++){
        sum = 0;
        int k = i;
        while (k > 0){
            sum += k % 10;
            k /= 10;
        }
        if (i + sum == n){ 
            cout << i << endl;
            flag = 1;
            break;
        }
    }
    if(flag == 0) cout << 0 << endl;
    // main2();
    return 0;
}


/*
方法2： 直接把  1 ~ 1e5 所有数字的 自身+数字和 求出来，然后以此为下标
 然后放在以该数字为下标的数组位置处，数组中存放的是该数字的生成元
 如果新的生成元比原来的小 就更新
对于大量数据 直接查表即可
*/
#define maxn 100005
int ans[maxn];

int main2(){
    int T, n;
    memset(ans, 0 ,sizeof ans); //初始化为0 ， 无解的位置就是0
    for (int m = 1; m < maxn; m++){
        int x = m, y = m;
        while (x > 0) {y += x % 10; x /= 10;}
        if (ans[y] == 0 || m < ans[y]) ans[y] = m;
    }
    scanf("%d", &T);
    while (T--){
        scanf("%d", &n);
        printf("%d\n", ans[n]);
    }
    return 0;
}