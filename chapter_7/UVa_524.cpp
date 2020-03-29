/*
 * @Description: 例题7-4 素数环（Prime Ring Problem, UVa 524）
 * @Author: Xiaobin Ren
 * @Date: 2020-03-29 11:09:41
 * @LastEditTime: 2020-03-29 12:04:12
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

int is_prime(int x) {
  for(int i = 2; i*i <= x; i++)
    if(x % i == 0) return 0;
  return 1;
}
 
int n, A[50], isp[50], vis[50];
void dfs(int cur) {
  if(cur == n && isp[A[0]+A[n-1]]) {
    for(int i = 0; i < n; i++) {
      if(i) printf(" ");
      printf("%d", A[i]);
    }
    printf("\n");
  }
  else for(int i = 2; i <= n; i++)
    if(!vis[i] && isp[i+A[cur-1]]) {
      A[cur] = i;
      vis[i] = 1;
      dfs(cur+1);
      vis[i] = 0;
    }
}
 
int main() {
  int kase = 0;
  while(scanf("%d", &n) == 1 && n > 0) {
    if(kase > 0) printf("\n");
    printf("Case %d:\n", ++kase);
    for(int i = 2; i <= n*2; i++) isp[i] = is_prime(i);
    memset(vis, 0, sizeof(vis));
    A[0] = 1;
    dfs(1);
  }
  return 0;
}