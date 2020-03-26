/*
 * @Description:例题6-11 四分树（Quadtrees, UVa 297 
 * @Author: Xiaobin Ren
 * @Date: 2020-03-26 15:51:20
 * @LastEditTime: 2020-03-26 16:20:52
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


const int len = 32;
const int maxn = 1024 + 10;
char s[maxn];
int buf[len][len], cnt = 0;

// r 是行，  c是列
void draw(char *s, int &p, int r, int c, int w){
    char ch = s[p++];
    if (ch == 'p'){
        draw(s, p, r,     c+w/2, w/2);   //1
        draw(s, p, r,         c, w/2);   //2
        draw(s, p, r+w/2,     c, w/2);   //3
        draw(s, p, r+w/2, c+w/2, w/2);   //4
    }else if(ch == 'f'){   //画黑像素， 白色的不用画
        rep(i, r, r+w) rep(j, c, c+w)
        if(buf[i][j] == 0){ buf[i][j] = 1; cnt++;}
    }
}

int main(int argc, char const *argv[]){
  //ios::sync_with_stdio(false);
  //cin.tie(0);

    int t;
    cin >> t;
    while (t--){
        memset(buf, 0, sizeof buf);
        cnt = 0;
        rep(i, 0, 2){
            cin >> s;
            int p = 0;
            draw(s, p, 0, 0, len);
        }
        printf("There are %d black pixels.\n", cnt);
    }
    return 0;
}





