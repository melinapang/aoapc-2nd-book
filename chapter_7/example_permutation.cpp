/*
 * @Description: 生成1～n的排列
 * @Author: Xiaobin Ren
 * @Date: 2020-03-28 11:52:25
 * @LastEditTime: 2020-03-28 12:03:25
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

void permutation(int n, int *a, int cur){
    if (cur == n){
        rep(i, 0, n) printf("%d ", a[i]);
        printf("\n");
    }
    else rep(i, 1, n+1){
        int ok = 1;
        rep(j, 0, cur) if(a[j] == i) ok = 0;
        if(ok){
            a[cur] = i;
            permutation(n, a, cur+1);
        }
    } 
}

int main(int argc, char const *argv[]){
  //ios::sync_with_stdio(false);
  //cin.tie(0);

    int a[11];
    permutation(10, a, 0);
    return 0;
}
















