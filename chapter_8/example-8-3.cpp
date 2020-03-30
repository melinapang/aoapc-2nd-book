/*
 * @Description: 程序8-3 最大连续和（3）
 * @Author: Xiaobin Ren
 * @Date: 2020-03-30 09:15:40
 * @LastEditTime: 2020-03-30 10:28:37
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

/*
    分治三个步骤： 划分 递归 合并
*/


int maxsum(int *a, int x, int y){  //返回数组在左闭右开区间[x,y)中的最大连续和
    int v, l, r, maxs;
    if (y - x == 1) return a[x];   //等于一是因为 这是左闭右开的区间
    int m = x + ((y - x) >> 1);  //中间位置 分治
    maxs = max(maxsum(a, x, m), (a, m, y));   //递归
    v = 0; l = a[m-1];    //从分界点开始的往左的最大连续和 l
    per(i, x, m) l = max(l, v += a[i]);
    v = 0; r = a[m];  //从分界点开始往右的最大连续和 r 
    rep(i, m, y) r = max(r, v+=a[i]);
    return max(maxs, l+r);  //子问题和 l  r  比较
}

int main(int argc, char const *argv[]){
  //ios::sync_with_stdio(false);
  //cin.tie(0);

    
    return 0;
}
















