/*
 * @Descripttion:例题6-6 小球下落（Dropping Balls, UVa 679） 
 * @Author: Xiaobin Ren
 * @Date: 2020-03-24 18:35:18
 * @LastEditTime: 2020-03-24 21:22:09
 */

/*
    每个小球都会落在根结点上，因此前两个小球必然是一个在左子树，一个在右子树。
    一般地，只需看小球编号的奇偶性，就能知道它是最终在哪棵子树中。
    对于那些落入根结点左子树的小球来说，只需知道该小球是第几个落在根的左子树里的，
    就可以知道它下一步往左还是往右了。

    依此类推，直到小球落到叶子上。如果使用题目中给出的编号I，则当I是奇数时，
    它是往左走的第（I+1）/2个小球；当I是偶数时，它是往右走的第I/2个小球。
    这样，可以直接模拟最后一个小球的路线
*/

#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    while (cin >> n && n != -1){
        int d, i;  // d是层数， i是节点个数
        while (n--){
            cin >> d >> i; 
            int k = 1;
            for (int j = 0; j < d - 1; j++){
                if (i % 2){ k = k * 2; i = (i+1)/2;}
                else{ k = 2*k+1; i /= 2;}
            }
            cout << k << endl;
        }
    }
    return 0;
}

// TLE做法 太暴力
/*
const int maxd = 20;
int s[1 << maxd];  //最大节点个数为 2^maxd - 1

int main2(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    while (cin >> n && n != -1){  //样例个数
        int d, i;
        while (n--){
            memset(s, 0, sizeof s);
            cin >> d >> i;
            int k, n = (1 << d) - 1;  // n 是最大叶节点的编号
            for (int j = 0; j <i ; j++){   //连续让 i  个小球下落 
                k = 1;
                for(; ;){  
                    s[k] = !s[k];
                    k = s[k] ? 2*k : 2*k+1;
                    if (k > n) break;
                }
            }
            cout << k/2 << endl;
        }
    }
}
*/