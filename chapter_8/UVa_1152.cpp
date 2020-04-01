/*
 * @Description: 1152 - 4 Values whose Sum is 0
 * @Author: Xiaobin Ren
 * @Date: 2020-04-01 08:56:43
 * @LastEditTime: 2020-04-01 09:22:19
 */

/*
    将ab，cd的和的所有情况存入数组，然后再二分搜， 复杂度 O(n^2 * logN)
    如果数据量太大，则要自己手写 hash
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


const int INF = 0x3f3f3f3f;
const int maxn = 4e3 + 5;
int a[maxn], b[maxn], c[maxn], d[maxn];
int s1[maxn*maxn], s2[maxn*maxn];
int n; ll ans;

int main(int argc, char const *argv[]){
  //ios::sync_with_stdio(false);
  //cin.tie(0);

    int T; int flag = 1;
    scanf("%d", &T);
    while(T--){
        scanf("%d", &n);
        rep(i, 0, n) scanf("%d%d%d%d", &a[i], &b[i], &c[i], &d[i]);
        rep(i, 0, n) rep(j, 0, n) s1[i*n + j] = a[i] + b[j];   //注意此处的读数技巧
        rep(i, 0, n) rep(j, 0, n) s2[i*n + j] = -c[i] - d[j];
        sort(s1, s1+n*n);
        sort(s2, s2+n*n);
        ans = 0; int tmp;
        for(int i = 0, limit = n*n; i < limit; i++){
            int j = i;
            while(s1[j+1] == s1[i]) j++;   //因为可能有多个相同的值， 直接跳过
            tmp = upper_bound(s2, s2+n*n, s1[i]) - lower_bound(s2, s2+n*n, s1[i]);
            ans += 1L*tmp*(j-i+1);   //此处的计算技巧 包含了多个相同值的情况, j-i+1 是因为上边的判断条件是 s1[j+1]
            i = j;
        }
        if(flag) flag = 0;
        else printf("\n");
        printf("%lld\n", ans);
    } 
    return 0;
}


