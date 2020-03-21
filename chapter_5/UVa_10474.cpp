/*
 * @Descripttion:例题5-1 大理石在哪儿（Where is the Marble？，Uva 10474） 
 * @Author: Xiaobin Ren
 * @Date: 2020-03-21 11:04:20
 * @LastEditTime: 2020-03-21 16:04:11
 */

#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn = 10000;

int main() {  
    int n, q, x, a[maxn], kase = 0;  
    while(scanf("%d%d", &n, &q) == 2 && n) {    
        printf("CASE# %d:\n", ++kase);    
        for(int i = 0; i < n; i++) 
        scanf("%d", &a[i]);    
        sort(a, a+n); //排序    
        while(q--) {      
            scanf("%d", &x);      
            int p = lower_bound(a, a+n, x) - a; //在已排序数组a中寻找x ，返回的迭代器，直接减掉数组名字就是下标     
            if(a[p] == x) printf("%d found at %d\n", x, p+1);      
            else printf("%d not found\n", x);    
            }  
        }  
        return 0;
}