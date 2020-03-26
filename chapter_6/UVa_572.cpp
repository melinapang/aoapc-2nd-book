/*
 * @Description: 例题6-12 油田（Oil Deposits, UVa 572）
 * @Author: Xiaobin Ren
 * @Date: 2020-03-26 16:26:40
 * @LastEditTime: 2020-03-26 16:38:53
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

const int maxn = 100 + 5;
char pic[maxn][maxn];
int m, n, idx[maxn][maxn];

//r: row  c: col
void dfs(int r, int c, int id){
    if ( r < 0 || r > m || c < 0 || c > n) return;
    if (idx[r][c] > 0 || pic[r][c] != '@') return;   //搜过了， 或者这个格子不是 '@'
    idx[r][c] = id;   //属于同一个八连通的字符， id都一样
    rep(dr, -1, 2) rep(dc, -1, 2)
    if (dr != 0 || dc != 0) dfs(r+dr, c+dc, id);  //dr=dc=0 时候就是本身格子， 不用搜这个格子
}

int main(int argc, char const *argv[]){
  //ios::sync_with_stdio(false);
  //cin.tie(0);

    while(scanf("%d%d", &m, &n) == 2 && m && n){
        rep(i, 0, m) scanf("%s", pic[i]);
        memset(idx, 0, sizeof idx);
        int cnt = 0;
        rep(i, 0, m) rep(j, 0, n)
        if (idx[i][j] == 0 && pic[i][j] == '@') dfs(i, j, ++cnt);
        printf("%d\n", cnt);
    }
    return 0;
}
















