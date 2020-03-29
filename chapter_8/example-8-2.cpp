/*
 * @Description: 程序8-2 最大连续和（2）
 * @Author: Xiaobin Ren
 * @Date: 2020-03-29 22:36:41
 * @LastEditTime: 2020-03-29 22:42:04
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


const int maxn = 1000;
int s[maxn];
/*
    使用前缀和可以讲区间最大连续和问题降低为 O(n^2) 复杂度
    前缀和可以在 O(1) 时间内求出区间和
*/

int main(int argc, char const *argv[]){
  //ios::sync_with_stdio(false);
  //cin.tie(0);
    int A[maxn], best = A[1];
    rep(i, 1, n+1) s[i] = s[i-1] + A[i];    //递推前缀和
    rep(i, 1, n+1) rep(j, i, n+1)
    best = max(best, s[j] - s[i-1]);
    return 0;
}
















