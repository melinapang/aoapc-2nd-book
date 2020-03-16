/*
算法竞赛中的输入输出框架
参考博客： https://blog.csdn.net/xavierdarkness/article/details/80638641
          https://oi-wiki.org/lang/file-op/
*/

/*
总结： 可以重定向 freopn 不能重定向 fopen
标准输入输出 printf scanf
fopen的fscanf/fprintf是文件输入输出， scanf/printf是标准输入输出
fopen可以同时文件输入输出和标准输入输出

freopen所有的输入输出(scanf,printf，cin,cout)都被重定向 
fopen的文件 要定义fin/fout
*/

//freopen 模板
#include <cstdio>
#include <iostream>
int main(void) {
  freopen("data.in", "r", stdin);
  freopen("data.out", "w", stdout);
  /*
  中间的代码不需要改变，直接使用 cin 和 cout 即可
  */
  fclose(stdin);
  fclose(stdout);
  return 0;
}

//fopen 模板
FILE *in, *out;  // 定义文件指针
in = fopen("data.in", "r");
out = fopen("data.out", "w");
/*
do what you want to do
*/
fclose(stdin);
fclose(stdout);

//c++ fstream模板：
#include <cstdio>
#include <fstream>
ifstream fin("data.in");
ofstream fout("data.out");
int main(void) {
  /*
  中间的代码改变 cin 为 fin ，cout 为 fout 即可
  */
  fin.close();
  fout.close();
  return 0;
}

//带条件编译的freopen：
#include <iostream>
#define INF 1000000000
#define LOCAL //条件编译
typedef long long ll;

using namespace std;

int main(){
    
#ifdef LOCAL
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
 
    /*
        code
    */
    
//    printf();  测试代码 调试用
  fclose(stdin);
  fclose(stdout);
  return 0;
}


//程序2 - 11 数据统计

#include <iostream>
#include <cmath>
#include <cstdio>
#include <ctime>

#define INF 1000000000
typedef long long ll;

using namespace std;

int main(){

    FILE *fin, *fout;
    fin = fopen("data.in", "rb");
    fout = fopen("data.out", "wb");
    
    int x, n= 0, min = INF, max = -INF, s = 0;
    while(fscanf(fin, "%d", &x) == 1){
        s += x;
        if (x < min) min = x;
        if (x > max) max = x;
        n++;
    }
    fprintf(fout, "%d %d %.3f\n", min, max, (double)s/n);
    fclose(fin);
  return 0;
}

//程序2 - 12 改bug之后的：
#include <iostream>
#include <cmath>
#include <cstdio>

#define INF 1000000000
typedef long long ll;

using namespace std;

int main(){

    int x, n = 0, kase = 0;
    /*
    kase 计数器 常用于多种数据输出之间要有空行
    但是第一组没有空行 所以先将kase置为0 
    在第一次if判断kase之后 kase ++
    */
    while(scanf("%d", &n) == 1 && n){
        int min = INF, max = -INF;
        int s = 0;
        for (int i = 0; i < n; i++) {
            scanf("%d", &x);
            s += x;
            if (x < min) min = x;
            if (x > max) max = x;
        }
        if (kase) printf("\n");
        printf("Case %d: %d %d %.3f\n", ++kase, min, max, (double)s/n);
        
    }
  return 0;
}