/*
 * @Descripttion:习题4-2 正方形（Squares, ACM/ICPC World Finals 1990, UVa201） 
 * @Author: Xiaobin Ren
 * @Date: 2020-03-20 10:20:40
 * @LastEditTime: 2020-03-20 11:26:47
 */


#include <bits/stdc++.h>

using namespace std;

const int maxn = 16;
//n: 正方形边长 m: 边数量  vexp：顶点的向下最大延申边数 hexp：顶点的最大向右延申边数
//h：所有的纵向边  v:所有的横向边  squares：squares[i] 代表面积为 i 的正方形的数量
int n ,m ,vexp[maxn][maxn], hexp[maxn][maxn], h[maxn][maxn], v[maxn][maxn], squares[maxn];

int main(){
    char buf[4];   //储存每条边的信息
    int x, y;      //边的坐标
    for (int t = 1; scanf("%d", &n) == 1; t++){   //t是problem 编号 这里可以一块定义
        if (t > 1) printf("\n**********************************\n\n");
        memset(vexp, 0, sizeof vexp), memset(hexp, 0, sizeof hexp);
        memset(h, 0, sizeof h), memset(v, 0, sizeof v), memset(squares, 0, sizeof squares);
        
        scanf("%d", &m); //边的数量
        for (int i = 0; i < m; i++){  //读边存边， 存在就二维数组标记为 1
            scanf("%s%d%d", buf, &x, &y);
            if (buf[0] == 'H') h[x][y] = 1;
            else v[y][x] = 1;
        }

        for (int i = n; i >= 1; i--){
            for (int j = n; j >= 1; j--){  //计算每个点的向下向右最大延申长度
                if (h[i][j]) hexp[i][j] = hexp[i][j + 1] + 1;
                if (v[i][j]) vexp[i][j] = vexp[i + 1][j] + 1;
            }
        }
        
        for (int i = 1; i <= n; i++){ //遍历所有的顶点并判断 符合条件的 面积如果为 s ，则squares[s]++
            for (int j = 1; j <= n; j++){
                int maxs = min(hexp[i][j], vexp[i][j]);
                for (int s = 1; s <= maxs; s++)
                    if(hexp[i+s][j] >= s && vexp[i][j+s] >= s) squares[s]++;
            }
        }

        printf("Problem #%d\n\n", t);
        bool found = false;
        for (int i = 1; i <= n; i++)
            if (squares[i]) {
                found = true;
                printf("%d square (s) of size %d\n", squares[i], i);
            }
        if (!found) puts("No completed squares can be found.");
    }
    return 0;
}