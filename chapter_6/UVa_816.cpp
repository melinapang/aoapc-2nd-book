/*
 * @Description: 例题6-14Abbott的复仇（Abbott's Revenge, ACM/ICPC World Finals 2000, UVa 816）
 * @Author: Xiaobin Ren
 * @Date: 2020-03-26 19:13:31
 * @LastEditTime: 2020-03-26 21:21:02
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


struct NODE   // 储存点， 方向
{
    //r： 横坐标 c： 纵坐标 dir： 方向
    int r, c, dir;
    NODE(int r = 0, int c = 0, int dir = 0): r(r), c(c), dir(dir){}
};

const int maxn = 100;
const char *dirs = "NESW";
const char *turns = "FLR";
const int dr[] = {-1, 0, 1, 0};
const int dc[] = {0, 1, 0, -1};
/*
    d[r][c][dir]表示初始状态到(r,c,dir)的最短路长度，
    p[r][c][dir]保存了状态(r,c,dir)在BFS树中的父结点
    has_edge[r][c][dir][turn]表示当前状态是(r,c,dir)，是否可以沿着转弯方向turn行走
*/
int d[maxn][maxn][4], has_edge[maxn][maxn][4][3];
int c1, r1, r2, c2, dir, r0, c0;
NODE p[maxn][maxn][4];
string name;

//进入的方向
int dir_id(char c) { return strchr(dirs, c) - dirs;}
//转出的方向
int turn_id(char c) { return strchr(turns, c) - turns;}

//走向下一个点
NODE walk(const NODE &u, int run){
    int dir = u.dir;
    if (run == 1) dir = (dir + 3) % 4;  //向左转， 逆时针
    if (run == 2) dir = (dir + 1) % 4;  //向右转，顺时针
    return NODE(u.r + dr[dir], u.c + dc[dir], dir);
}

bool inside(int r, int c){
    return r >= 1 && r <= 9 && c >=1 && c <= 9; //坐标从1开始
}

//输出答案， 用vector保存节点
void print_ans(NODE u){
    vector<NODE> nodes;
    //从最后一个节点往前找,此时的u已经是终点
    for(; ;){
        nodes.push_back(u);
        if (d[u.r][u.c][u.dir] == 0) break;
        u = p[u.r][u.c][u.dir];
    }
    nodes.push_back (NODE(r0, c0, dir));

    int cnt = 0;
    per(i, 0, int(nodes.size())){
        if (cnt % 10 == 0) printf(" ");
        printf(" (%d,%d)", nodes[i].r, nodes[i].c);
        if (++cnt % 10 == 0) printf("\n");
    }
    if (nodes.size() % 10 != 0) printf("\n");
}

//bfs
void solve(){
    queue<NODE> q;
    memset(d, -1, sizeof d);
    NODE u(r1, c1, dir);
    d[u.r][u.c][u.dir] = 0;
    q.push(u);
    while(!q.empty()){
        NODE u = q.front(); q.pop();
        if (u.r == r2 && u.c == c2){   //  到终点
            print_ans(u);
            return;
        }

        rep(i, 0, 3){
            NODE v = walk(u, i);
            if (has_edge[u.r][u.c][u.dir][i] && inside (v.r, v.c) && d[v.r][v.c][v.dir] < 0) {
                d[v.r][v.c][v.dir] = d[u.r][u.c][u.dir] + 1;
                p[v.r][v.c][v.dir] = u;
                q.push(v);
            }
        }
    }
    printf ("  No Solution Possible\n");
}

//输入函数
bool scan(){
    memset(has_edge, 0, sizeof(has_edge));
    cin >> name;
    if (name == "END") return false;
    char s[100];
    cin >> r0 >> c0 >> s >> r2 >> c2;
    cout << name << endl;
    r1 = r0 + dr[dir_id (s[0])];
    c1 = c0 + dc[dir_id (s[0])];
    dir = dir_id (s[0]);
    int r, c;
    while (cin >> r){
        if (r == 0) break;
        cin >> c;
        char s2[100];
        while(cin >> s2){
            if (s2[0] == '*') break;
            int l = strlen(s2);
            rep(i, 1, l) has_edge[r][c][dir_id (s2[0])][turn_id (s2[i])] = 1;
        }
    }
    return true;
}

int main(int argc, char const *argv[]){
  //ios::sync_with_stdio(false);
  //cin.tie(0);

    while (scan()){ solve();}
    return 0;
}