/*
 * @Descripttion:例题5-6 团体队列（Team Queue，UVa540） 
 * @Author: Xiaobin Ren
 * @Date: 2020-03-22 21:03:50
 * @LastEditTime: 2020-03-22 22:32:54
 */

#include <bits/stdc++.h>

using namespace std;

const int maxn = 1000+10;

int main(){
   // ios::sync_with_stdio(false);
   // cin.tie(0);

    int t, kase = 0;   // t： 队伍个数  kase：样例编号
    while (cin >> t && t){
        printf("Scenario #%d\n", ++kase);

        //记录所有人的团队编号
        map<int, int> team;  // team[x] 表示编号为 x 的人所在的团队编号
        for (int i = 0; i < t; i++){ //输入 t 个队伍的所有数据
            int n, x;  // n: 队伍长度
            cin >> n;
            while(n--){cin >> x; team[x] = i;}  // i : 队伍0，队伍1.....
        }

        //模拟
        queue<int> q;  //存放所有队伍的编号，队伍1就是1， 队伍2 就是2
        queue<int> q2[maxn];  // q2[i] 是成员 i 所属的整个队列
        //通过 q 里面的数来操作 q2 里面的队员
        while(1){
            int x;
            char cmd[10];
            cin >> cmd;
            if (cmd[0] == 'S') break;
            else if(cmd[0] == 'D'){
                int t = q.front();
                cout << q2[t].front() << endl; q2[t].pop();
                if(q2[t].empty()) q.pop(); 
            }
            else if(cmd[0] == 'E'){
                cin >> x;
                int t = team[x];
                if (q2[t].empty()) q.push(t); // 团队 t 进去队列
                q2[t].push(x);
            }
        }
        cout << endl;
    }
    return 0;
}