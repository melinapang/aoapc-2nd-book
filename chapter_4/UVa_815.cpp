/*
 * @Descripttion:习题4-10 洪水！（Flooded! ACM/ICPC World Finals 1999, UVa815） 
 * @Author: Xiaobin Ren
 * @Date: 2020-03-21 08:44:29
 * @LastEditTime: 2020-03-21 09:25:14
 */

/*
    这题解法非常多，习题书给的方法算是非常简洁的做法
    因为水池的形状不影响水池的体积， 直接把水池 “压扁” 成一排
    然后把格子的海拔高度从小到大进行排序 然后遍历一次即可， 复杂度 O(n)
*/

#include <bits/stdc++.h>

using namespace std;

int main(){

    vector<int> H;
    //m,n:区域边界长度 wl：已经淹没区域的高度 k:能淹没的格子数量 v:水的总体积
    int m, n; double wl, k, v; 

    for (int r = 1; scanf("%d%d", &m, &n) == 2 && m && n; r++){  //循环输入+编号样例输出的技巧
        n *=m; H.clear();
        int hi;
        for (int i = 0; i < n; i++){
            cin >> hi;
             H.push_back(hi);  //存取每个格子的高度
        }
        //for (auto &p : H) cout << p << " ";  //调试输出
        //cout << endl;

        H.push_back(INT_MAX);  //最后的边界，用于处理装满的情况
        sort(H.begin(), H.end());
        scanf("%lf", &v); v /= 100;  //总体积/100， 将体积均摊成平均高度来处理
        for (int i = 1; i <=n; i++){
            /*
                v += H[i - 1]; wl = v/i; 的解释：
                因为 v 只是水的体积， 但是格子的地基也算体积，为了求均摊的高度
                将格子的地基和水加起来 然后再求。
                v / i 就是求前 i 个格子水的高度，因为全部都淹掉了，所以高度一样都是均摊
            */
            v += H[i-1]; wl = v / i;      //wl:把 0~i-1个格子都淹掉之后的水池高度
            if(wl < H[i]) {k = i; break;} //淹没不了格子 i 
        }

        printf("Region %d\nWater level is %.2lf meters.\n", r, wl);
        printf("%.2lf percent of the region is under water.\n\n", k*100/(H.size() - 1));
    }
    return 0;
}