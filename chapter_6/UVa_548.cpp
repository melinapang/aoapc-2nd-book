/*
 * @Description: 例题6-8 树（Tree, UVa 548）
 * @Author: Xiaobin Ren
 * @Date: 2020-03-25 21:10:39
 * @LastEditTime: 2020-03-25 21:39:03
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
ll gcd(ll a, ll b) {return b?gcd(b,a%b):a;}
//head

const int maxv = 10000 + 10;
int in_order[maxv], post_order[maxv], lch[maxv], rch[maxv];
int n;

bool read_list(int *a){
    string line;
    if (!getline(cin, line)) return false;
    stringstream ss(line);
    n = 0;
    int x;
    while (ss >> x) a[n++] = x;
    return n > 0;
}
//建树， l1 r1, 是中序的首位坐标。 l2, r2 是后序的首位坐标
int build(int l1, int r1, int l2, int r2){
    if (l1 > r1) return 0;  //空树
    int root = post_order[r2];
    int p = l1;
    while(in_order[p]!=root) p++;
    int cnt = p - l1;
    /*
        使用递归来逐步建立，由后序连确定当前递归中的分支的根节点，再在中序中找到根的位置，
        则中序中根左的为左子树的中序排列，根右的为右子树的中序。
        设此时左子树的长度为len，则当前的后序的前len个数据是左子树的后序排列。
        同理进行递归即可。右子树同理。
    */
    lch[root] = build(l1, p-1, l2, l2+cnt-1);   //以根为分界点， 左右递归中序和后序的数组.
    rch[root] = build(p+1, r1, l2+cnt, r2-1);
    return root;
}

int best, best_sum;

void dfs(int u, int sum){
    sum += u;
    if (!lch[u] && !rch[u]){   //叶子
        if (sum < best_sum || (sum == best_sum && u < best)){
            best = u;
            best_sum = sum;
        }
    }
    if (lch[u]) dfs(lch[u], sum);
    if (rch[u]) dfs(rch[u], sum);
}

int main(int argc, char const *argv[]){
   //ios::sync_with_stdio(false);
   //cin.tie(0);
   
    while(read_list(in_order)){
        read_list(post_order);
        build(0, n-1, 0, n-1);
        best_sum = 0x3f3f3f3f;
        dfs(post_order[n-1], 0);
        cout << best << endl;
    }
    
    return 0;
}
