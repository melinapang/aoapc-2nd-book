/*
 * @Description:  二进制法枚举子集
 * @Author: Xiaobin Ren
 * @Date: 2020-03-30 18:28:11
 * @LastEditTime: 2020-03-30 18:33:23
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


/*
  二进制法的本质原理: 对于一个数 n , 2^n - 1 有 n 个二进制位为 1
  且每一个 0 ~ 2^n -1 的数的二进制表示都不一样，
  这些所有比 n 小的数的 “二进制表示” 的数中 1 出现的位置下标数
  也就是位移的 “位数” 覆盖了所有的 0 ~ n-1的数
  其实 printf 输出的恰好就是 位移的 “位数”，
  也就是 0 ~ 2^n -1这些每一个数的二进制位为 1 的下标位置
*/

//不用递归， 双层循环 复杂度 O(n*2^n)
void print_subset(int n, int s)
{ //打印{0, 1, 2,..., n-1}的子集S
  for (int i = 0; i < n; i++)
    if (s & (1 << i))
      printf("%d ", i); 
  printf("\n");
}

int main(int argc, char const *argv[]){
  //ios::sync_with_stdio(false);
  //cin.tie(0);
   int n = 3;
   for (int i = 0; i < (1 << n); i++)
       print_subset(n, i);
   return 0;
}














