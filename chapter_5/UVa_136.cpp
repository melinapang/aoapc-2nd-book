/*
 * @Descripttion:例题5-7 丑数（Ugly Numbers，Uva 136） 
 * @Author: Xiaobin Ren
 * @Date: 2020-03-22 22:42:34
 * @LastEditTime: 2020-03-22 23:19:39
 */

/*
    此题是数论题，意思是该数的素因子只有 2，3，5
    由素幂因子分解可知，如果素因子只有这三个，那么若 x 符合条件
    只有 2x， 3x， 5x 继续符合条件，即每次乘2，3，5都是且仅是的唯一符合条件的数
    因为是从小到大求，所以每次都取堆中最小的数来乘，维持最小增长，这样不会遗漏
*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int coeff[3] = {2,3,5};

int main(){
    // ios::sync_with_stdio(false);
    // cin.tie(0);

    priority_queue<ll, vector<ll>, greater<ll> > pq;
    set<ll> s;
    pq.push(1);
    s.insert(1);
    for (int i = 1; ; i++){
        ll x = pq.top(); pq.pop();
        if (i == 1500) {
            cout << "The 1500'th ugly number is " << x << ".\n";
            break;
        }
        for (int j = 0; j < 3; j++){
            ll x2 = x*coeff[j];
            if (!s.count(x2)){s.insert(x2); pq.push(x2);}
        }
    }

    return 0;
}