//教材第一章代码的注意点
/*
const double PI = acos(-1.0); //弧度制
printf("%d", 8.0/5.0); //warning 
prinf("%f", 8/5); //waring
scanf("%d%d", &a, &b); //忽略a b中间的所有空/tab/回车
printf("%03d",x); 前导0补齐 超过长度则忽略
printf("%03d\n", 2); //002
printf("%03d\n", 2133); //2133
*/

//交换变量4方法：

#include <iostream>
#include <cstdio>

using namespace std;

int main(){
    //method1
    int a = 3;
    int b = 0;
    a^=b^=a^=b;
    cout << a << " " << b << endl;
    
    //method2
    int c = 0;
    int d = 3;
    c = c ^ d;
    d = c ^ d;
    c = c ^ d;
    cout << c << " " << d << endl;
    
    //method3
    int e = 3, f = 4;
    e = e + f;
    f = e - f;
    e = e - f;
    cout << e << " " << f << endl;
    
    //method4
    int k, m, t;
    t = m;
    m = k;
    k = t;
    
    return 0;
}

/*
输入输出的trick 
如果只是交换并且输出
*/
int main(){
    int a, b;
    scanf("%d%d", &a, &b);
    ptintf("%d %d", b, a);
    
    return 0;
}