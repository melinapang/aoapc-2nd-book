/*
 * @Description: 120 - Stacks of Flapjacks 
 * @Author: Xiaobin Ren
 * @Date: 2020-03-31 17:32:20
 * @LastEditTime: 2020-03-31 19:45:51
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


int n, a[10005];
string s;

void solve(int p){
    for(int i = 0; i < p-i; i++){
        swap(a[i], a[p-i]);
    }
    cout << n-p << " ";
}

int main(int argc, char const *argv[]){
  //ios::sync_with_stdio(false);
  //cin.tie(0);

    while(getline(cin, s)){
        cout << s << endl;
        stringstream ss(s);
        n = 0;
        while(ss >> a[n]) n++;
        for(int i = n-1; i>0; i--){
            int p = max_element(a, a+i+1) - a;
            if(p == i) continue;
            if(p > 0) solve(p);
            solve(i);   //翻上去再翻下来
        }
        cout << "0" << endl;
    }
    return 0;
}
















