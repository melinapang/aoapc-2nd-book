//程序3 - 3 蛇形填数
//注意数组下标 很坑

#include <iostream>
#include <cstring>

using namespace std;

int a[10][10];

int main(){
    int x, y, n;
    cin >> n;
    memset(a, 0, sizeof a);
    int tot = a[x=0][y=n-1] = 1; //起点处在右上角
    while (tot < n*n){   //tot是步数 走n*n - 1 步
        while (x + 1 < n && !a[x+1][y]) a[++x][y] = ++tot;
        while (y - 1 >= 0 && !a[x][y-1]) a[x][--y] = ++tot;
        while (x - 1 >= 0 && !a[x-1][y]) a[--x][y] = ++tot;
        while (y + 1 < n && !a[x][y+1]) a[x][++y] = ++tot;
    }
    for (int x = 0; x < n; x++){
        for (int y = 0; y < n; y++)
            printf("%3d", a[x][y]);
            printf("\n");
    }
    return 0;
}
