/*
 * @Description: 例题6-16 单词（Play On Words, UVa 10129）
 * @Author: Xiaobin Ren
 * @Date: 2020-03-28 08:47:08
 * @LastEditTime: 2020-03-28 10:15:10
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

//     入度   出度      邻接矩阵        起点    访问标记
int n, in[30], out[30], graph[30][30], start, visit[30];
const int maxn = 1000 + 10;

void dfs(int u){
    visit[u] = 1;
    rep(v, 0, 26){
        if (graph[u][v] > 0){   //存在边 = 1, 访问过= 0
            graph[u][v]--;
            graph[v][u]--;
            dfs(v);
        }
    }
}

//判断连通图
bool isConnected(){
    memset(visit, 0, sizeof visit);
    dfs(start);
    rep(i, 0, 26){ //没有出现过的字母出入度都是0， 不参与搜索
        if (in[i] + out[i]) if (!visit[i]) return false;
    }
    return true;
}

bool solve(){
    if (!isConnected()) return false;

    int beg = 0, en = 0;   //起点终点
    rep(u, 0, 26){
        if (in[u] != out[u]){
            if (!beg && out[u] - in[u] == 1)  beg = 1;  // 标记为第一个奇点为起点， 判断出入度
            else if(!en && in[u] - out[u] == 1) en = 1;
            else return false;
        }
    }
    return true;
}

int main(int argc, char const *argv[]){
  //ios::sync_with_stdio(false);
  //cin.tie(0);

    int kase;
    scanf("%d", &kase);  //样例个数
    while (kase--){
        scanf("%d", &n);   //单词个数

        //刷新全局变量
        memset(in, 0, sizeof in);
        memset(out, 0, sizeof out);
        memset(graph, 0, sizeof graph);

        //输入单词， 确定出入度
        string str;
        rep(i, 0, n){
            cin >> str;
            int u = str[0] - 'a';
            int v = str[str.length() - 1] - 'a';  //以单词的首尾为顶点
            out[u]++, in[v]++;
            graph[u][v]++; graph[v][u]++;
            start = u;
        }
        if (solve()) printf("Ordering is possible.\n");
        else printf("The door cannot be opened.\n");
    }   
    return 0;
}
















