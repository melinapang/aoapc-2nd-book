/*
 * @Descripttion:习题5-4 交换学生（Foreign Exchange, UVa 10763） 
 * @Author: Xiaobin Ren
 * @Date: 2020-03-24 08:54:53
 * @LastEditTime: 2020-03-24 09:05:06
 */
/*
    这个题的题意好迷啊，根本没读懂样例是啥意思
    直接把样例的两个数字放在 pair<> 里面 然后去map查就行了
*/
#include <bits/stdc++.h>

using namespace std;

int readint(){ int x; scanf("%d", &x); return x;}

int main(){
    map<pair<int, int>, int> ex; int n;
    while (n = readint()){
        bool ans = true;
        ex.clear();
        for (int i = 0; i < n; i++){
            int a = readint(), b = readint();
            ex[make_pair(a, b)]++;
        }
        for (const auto& p : ex){
            pair<int, int> p2 = make_pair(p.first.second, p.first.first);
            if (ex[p2] != p.second) {ans = false; break;}
        }
        puts(ans ? "YES" : "NO");
    }
    return 0;
}