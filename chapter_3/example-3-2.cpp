//程序3-2 开灯问题
//注意全局数组开在main外面

#include <iostream>
#include <cstring>

using namespace std;

int a[1005] = {0};

int main(){
    int n, k, flag = 1;
    cin >> n >> k;
    for (int i = 1; i <= k; i++)
        for (int j = 1; j <=n; j++)
            if (j % i == 0) a[j] = !a[j];
    for (int i = 1; i <= n; i++){
        if (a[i])
        {
            if (flag)
                flag = 0; //每组数据结束的换行输出技巧
            else
                cout << " ";
            cout << i;
           }
        }
        cout << endl;
        return 0;
}