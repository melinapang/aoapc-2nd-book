/*
 * @Description: 例题6-9 天平（Not so Mobile, UVa 839）
 * @Author: Xiaobin Ren
 * @Date: 2020-03-26 10:29:35
 * @LastEditTime: 2020-03-26 10:40:03
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
int rnd(int x) {return mrand() % x;}
ll mulmod(ll a, ll b) {ll res=0;a%=mod;assert(b>=0);for(;b;b>>=1){if(b&1)res+=a%mod;a+=a%mod;}return res;}
ll powmod(ll a, ll b) {ll res=1;a%=mod;assert(b>=0);for(;b;b>>=1){if(b&1)res*=a%mod;a*=a%mod;}return res;}
ll gcd(ll a, ll b) {return b ? gcd(b, a % b) : a;}
//head

bool solve(int & w){
    int w1, w2, d1, d2;
    bool b1 = true;
    bool b2 = true;
    cin >> w1 >> d1 >> w2 >> d2;
    if (!w1) b1 = solve(w1);
    if (!w2) b2 = solve(w2);
    w = w1 + w2;
    return b1 && b2 && (w1 * d1 == w2 * d2); 
}

int main(int argc, char const *argv[]){
    // ios::sync_with_stdio(false);
    // cin.tie(0);

    int t, w;
    cin >> t;
    while (t--){
        if (solve(w)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}
