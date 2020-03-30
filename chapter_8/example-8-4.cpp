/*
 * @Description: 程序8-4 归并排序（从小到大）
 * @Author: Xiaobin Ren
 * @Date: 2020-03-30 10:18:31
 * @LastEditTime: 2020-03-30 10:41:40
 */


#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for(int i = a; i< n; i++)
#define per(i,a,n) for(int i=n-1; i>=a; i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define sz(x) ((int)(x).size())
typedef vector<int> VI;
typedef long long ll;
typedef pair<int, int> PII;
typedef double db;
mt19937 mrand(random_device{}());
const ll mod = 1000000007;
int rnd(int x) { return mrand() % x;}
ll mulmod(ll a, ll b) {ll res=0;a%=mod;assert(b>=0);for(;b;b>>=1){if(b&1)res+=a%mod;a+=a%mod;}return res;}
ll powmod(ll a, ll b) {ll res=1;a%=mod;assert(b>=0);for(;b;b>>=1){if(b&1)res*=a%mod;a*=a%mod;}return res;}
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a;}
//head

//排序数组a的x到y范围的元素, t是辅助数组
void merge_sort(int *a, int x, int y, int *t){
    if (y-x > 1){   //注意是左闭右开 不然就是 y != x 
        int m = x + (y-x)/2;
        int p = x, q = m, i = x; 
        merge_sort(a, x, m, t);
        merge_sort(a, m, y, t);
        while(p < m || q < y){
            if (q >= y || (p < m && a[p] <= a[q])) t[i++] = a[p++];  //从左半数组复制到临时空间
            else t[i++] = a[q++];  //从右半数组复制到临时空间
        }
        rep(i, x, y) a[i] = t[i];
    }
}

int main(int argc, char const *argv[]){
  //ios::sync_with_stdio(false);
  //cin.tie(0);

    int a[10] = {3,41,5,6,23,9};
    int t[10];
    merge_sort(a, 0, 4, t);
    for(int x : a) cout << x << " ";
    cout << endl;    
    return 0;
}
















