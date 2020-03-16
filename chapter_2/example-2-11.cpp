//程序2 - 11 数据统计 fopen版本

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