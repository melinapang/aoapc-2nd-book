/*
 * @Description: 例题6-7 树的层次遍历（Trees on the level, Duke 1993, UVa 122）
 * @Author: Xiaobin Ren
 * @Date: 2020-03-25 11:44:15
 * @LastEditTime: 2020-03-25 17:09:33
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

struct Node
{
    bool have_value;   //是否被赋值过
    int v;   //节点值
    Node *left, *right;
    Node():have_value(false), left(NULL), right(NULL){}   //构造函数
};

Node* root;    //根节点
Node* newnode(){return new Node();}

const int maxn = 300;  //储存所有的节点
char s[maxn];
VI ans(maxn);  //储存答案
bool failed = true;

void addnote(int v, char* s){
    int n = strlen(s);
    Node * u = root;   //从根节点往下走
    rep(i, 0, n)
        if (s[i] == 'L'){
            if (u->left == NULL) u->left = newnode();  //节点不存在 建立新节点
            u = u->left;
        }else if(s[i] == 'R'){
            if (u->right == NULL) u->right = newnode();
            u = u->right;
        }
    if (u->have_value) failed = true;   //以及赋值过， 输入有误，不能重复赋值
    u->v = v;  //给节点复制
    u->have_value = true;
}

bool bfs(VI& ans){   //宽搜
    queue<Node*> q;
    ans.clear();
    q.push(root);     //初始时候只有一个根节点
    while(!q.empty()){
        Node* u = q.front(); q.pop();
        if (!u->have_value) return false;
        ans.pb(u->v);
        if (u->left != NULL) q.push(u->left);
        if (u->right != NULL) q.push(u->right);
    }
    return true;
}

void remove_tree(Node* u){   //递归释放整棵树
    if (u == NULL)  return;
    remove_tree(u->left);
    remove_tree(u->right);
    delete u;
}

bool read_input(){  //读取节点
    failed = false;
    remove_tree(root);  //释放上一个样例的内存
    root = newnode();   //创建根节点
    for (;;){
        if (scanf("%s", s) != 1) return false;   //输入结束
        if (!strcmp(s, "()")) break;    //读到结束标志 退出循环
        int v;
        sscanf(&s[1], "%d", &v);   //读入节点值
        addnote(v, strchr(s, ',')+1);  //查找逗号，然后插入节点
    }
    return true;
}

int main(int argc, char const *argv[]){
   //ios::sync_with_stdio(false);
   //cin.tie(0);

   while(read_input()){
       if(failed || !bfs(ans))
           printf("not complete\n");
        else{
            printf("%d",ans[0]);
            rep(i, 1, ans.size())
                printf(" %d",ans[i]);
            printf("\n");
        }
   }
   return 0;
}
