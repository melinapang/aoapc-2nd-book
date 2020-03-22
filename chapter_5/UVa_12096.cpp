/*
 * @Descripttion:例题5-5  集合栈计算机（The   Set   Stack   Computer，ACM/ICPC   NWERC2006，UVa12096） 
 * @Author: Xiaobin Ren
 * @Date: 2020-03-21 23:05:30
 * @LastEditTime: 2020-03-22 20:22:22
 */

/*
    这题的核心思路是实现 set 和 int 的双射
    map <set, int>, vector<set>
    通过set查到 int 下标，又在vector中通过 下标查到 set
*/
#include <bits/stdc++.h>

using namespace std;

#define ALL(x) x.begin(), x.end()
#define INS(x) inserter(x, x.begin()) //注意宏的括号和inserter

using namespace std;

typedef set<int> Set;
map<Set, int> IDCache;
vector<Set> setCache;
int t, n;
char cmd[10];
int getID(Set s)
{
    if (IDCache.count(s))
        return IDCache[s];
    setCache.push_back(s);                   //将新集合加入Setcache
    return IDCache[s] = setCache.size() - 1; //将ID加入map ，同时返回新分配的ID值
}

int main()
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        stack<int> s;
        while (n--)
        {
            scanf(" %s", &cmd);
            if (cmd[0] == 'P')
                s.push(getID(Set()));
            else if (cmd[0] == 'D')
                s.push(s.top());
            else
            {
                Set s1 = setCache[s.top()];
                s.pop();
                Set s2 = setCache[s.top()];
                s.pop();
                Set x;
                if (cmd[0] == 'U')
                    set_union(ALL(s1), ALL(s2), INS(x));
                if (cmd[0] == 'I')
                    set_intersection(ALL(s1), ALL(s2), INS(x));
                if (cmd[0] == 'A')
                {
                    x = s2;
                    x.insert(getID(s1));
                }
                s.push(getID(x));
            }
            printf("%d\n", setCache[s.top()].size());
        }
        puts("***");
    }
}