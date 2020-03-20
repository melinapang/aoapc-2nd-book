/*
 * @Descripttion:习题4-8  特别困的学生（Extraordinarily  Tired  Students,  ACM/ICPC  Xi'an  2006,UVa12108） 
 * @Author: Xiaobin Ren
 * @Date: 2020-03-20 17:34:30
 * @LastEditTime: 2020-03-20 23:44:35
 */


/*
    陈锋原书的做法比较复杂，关键是代码没有注释。
    我又在网上找了一个解法，这个方法比较短。
    参考： https://blog.csdn.net/qq_30278727/article/details/50504777?depth_1-utm_source=distribute.pc_relevant.none-task

    大致的思路是，所有可能出现的情况，都会在 “所有人周期的公倍数” 时间内出现，
    所以直接遍历公倍数次，符合条件直接跳出即可。
    如果公倍数次内也没有符合的， 那么再也不会有符合的了。
*/


#include <bits/stdc++.h>

using namespace std;

int main(){
    //n学生数 time当前时刻分钟数 awake醒着的数 sleep 睡着的数 state记录每个学生状态
    //lcm 所有学生周期的公倍数 flag有效标记
    int n, time, awake, sleep, i, j, state[100][100], lcm, flag, num = 1;
    while (scanf("%d", &n) == 1 && n){
        lcm = 1, flag = 0;
        memset(state, 0, sizeof state);
        for (int i = 0; i < n; i++){  //输入所有数据
            cin >> state[i][0] >> state[i][1] >> state[i][2];
            state[i][3] = state[i][0] + state[i][1];
            lcm *= state[i][3];
        }
        for (time = 1; time <= lcm; time++){  //判断每个时刻的情况
            awake = sleep = 0; //每个时刻醒着和睡着的人数
            for (int i = 0; i < n; i++){ //求出此时刻睡着和醒着的人数
                if (state[i][2] > state[i][0]) sleep++;
                else awake++;
            }
            if (sleep == 0){flag = 1; break;} //满足条件就跳出

            if (sleep > awake){  //更新此 time 时刻 所有人的状态
                for (int i = 0; i < n; i++){
                    if (state[i][2] == state[i][3]) state[i][2] = 1;  //越界转换处理
                    else state[i][2]++; 
                }
            }else{  //醒着的多于睡着的。这种情况下更新每个人的状态
                for (int i = 0; i < n; i++){
                    //if是不敢睡的，要再撑着醒一次
                    if (state[i][2] == state[i][0] || state[i][2] == state[i][3]) state[i][2] = 1;
                    else state[i][2]++;
                }
            }
        }
        
        if(flag)printf("Case %d: %d\n",num++,time);
        else printf("Case %d: -1\n",num++);
    }
    return 0;
}