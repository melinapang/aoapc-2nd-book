//程序2-6 近似计算
#include <iostream>
#include <cmath>
#include <cstdio>
typedef long long ll;

using namespace std;

int main(){
    
   double sum = 0;
   
   for (int i = 0; ; i++){
       double term = 1.0 / (i*2+1);
       if (i % 2 == 0) sum += term;
       else sum -= term;
       if (term < 1e-6) break;
   }
   
   printf("%.6f\n", sum);
}

//do-while 做法：
#include <iostream>
#include <cmath>
#include <cstdio>
typedef long long ll;

using namespace std;

int main(){
    int i = 0;
    double sum = 0;
    double term = 0;
   do{
        term = 1.0 / (i*2+1);
        if (i % 2 == 0) sum += term;
        else sum -= term;
        i++;
        if (term < 1e-6) break;

   }while(term >= 1e-6);
   
   printf("%.6f\n", sum);
}
