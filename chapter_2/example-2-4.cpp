/*
3n+1 问题：
数据范围是 1e9， 所以乘法会直接溢出 要用long long
要注意的是 对于long long的输入输出，MinGw的是"%I64d"
但是linux下的gcc是"%lld"，紫书推荐用cin/cout 或者自己定义输入输出
*/
//递归版：
#include <iostream>
#include <cmath>
#include <cstdio>
typedef long long ll;

using namespace std;

ll sum = 0;

ll sumx(ll n){
    if (n == 1) return sum;
    if (n & 1){
      n = 3 * n + 1;
      sum ++;
    }else{
        n = n / 2;
        sum ++;
    }
    return sumx(n);
}

int main(){  
    ll n;
    cin >> n;
    cout << sumx(n) << endl;
    
    return 0;
}

//非递归版本，先把n2赋值给long long的变量 可以避免ll的输入输出
#include <iostream>
#include <cmath>
#include <cstdio>
typedef long long ll;

using namespace std;

int main(){
    
    int n2, count = 0;
    scanf("%d", &n2);
    ll n = n2;
    while (n > 1){
        if (n % 2 ==1) n = n*3 + 1;
        else n /= 2;
        count ++;
    }
    printf("%d\n", count);
    
    return 0;
}