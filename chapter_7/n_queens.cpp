/*
 * @Description: N皇后问题
 * @Author: Xiaobin Ren
 * @Date: 2020-03-29 10:32:25
 * @LastEditTime: 2020-03-29 10:52:17
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

int tot, n = 8; //八皇后
int c[10];
void search(int cur){
    if (cur == n) tot++;
    else rep(i, 0, n){
        int ok = 1;
        /*
        cur 代表当前行的坐标  c[cur]  代表当前列的坐标
        由于是枚举行，所以不存在行冲突的情况，只需要枚举列和对角线即可
        第一个条件判断列，第二个第三个判断对角线。
        原理：两个点坐标连线的斜率不等于 -1 或者 1， 就不在同一对角线上
        */
        c[cur] = i;
        rep(j, 0, cur)
            if(c[cur] == c[j] || cur-c[cur] == j-c[j] || cur+c[cur] == j+c[j]){
                ok = 0;
                break;
            }
            if (ok) search(cur + 1);
    }
}

int main(int argc, char const *argv[]){
  //ios::sync_with_stdio(false);
  //cin.tie(0);
    search(0);
    cout << tot << endl;   //92 种
    
    return 0;
}
















