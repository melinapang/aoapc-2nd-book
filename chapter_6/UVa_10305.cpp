/*
 * @Description: 例题6-15 给任务排序（Ordering Tasks, UVa 10305）
 * @Author: Xiaobin Ren
 * @Date: 2020-03-27 09:09:59
 * @LastEditTime: 2020-03-27 10:11:47
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


const int maxn = 110;
int n, m, u, v, G[maxn][maxn], vis[maxn], topo[maxn], t;

bool dfs(int u){
    vis[u] = -1;
    rep (v, 1, n+1){
        if (G[u][v]){
            if (vis[v] < 0) return false;  //判环
            else if (!vis[v] && !dfs(v)) return false;  //也可以写成： if(flag[v] < 0)   return false; else if(!flag[v])  dfs(v);
        }
    }
        vis[u] = 1; topo[--t] = u;
        return true;
}

bool toposort(){
    t = n;
    memset(vis, 0, sizeof vis);
    rep(u, 1, n+1) if(!vis[u]) if(!dfs(u)) return false;  //非连通图
    return true;
}


int main(int argc, char const *argv[]){
  //ios::sync_with_stdio(false);
  //cin.tie(0);

    while(scanf("%d%d", &n, &m) != EOF){   
    //注意此处有个大坑，这个任务可能只有一个， m 可能为 0
    //所以不能写成 while(scanf("%d%d", &n, &m) == 2 && n && m) 
        memset(G, 0, sizeof G);
        if (n ==0 && m == 0) break;
        rep(i, 1, m+1){
            scanf("%d%d", &u, &v);
            G[u][v] = 1;
        }
        toposort();
        rep(i, 0, n){
            if(i) printf(" ");
            printf("%d", topo[i]);
        }
        printf("\n");
    }
    return 0;
}