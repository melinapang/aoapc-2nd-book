/*
 * @Descripttion:例题4-1 古老的密码（Ancient Cipher, NEERC 2004, UVa1339） 
 * @Author: Xiaobin Ren
 * @Date: 2020-03-19 09:32:16
 * @LastEditTime: 2020-03-19 17:44:31
 */

/*
    分析：（紫书原文）
    既然字母可以重排，则每个字母的位置并不重要，重要的是每个字母出现的次数。
    这样可以先统计出两个字符串中各个字母出现的次数，得到两个数组cnt1[26]和cnt2[26]。
    下一步需要一点想象力：
    只要两个数组排序之后的结果相同，输入的两个串就可以通过重排和一一映射变得相同。
    
    一开始没太懂这种映射的关系， 以为是必须符合凯撒密码的映射。
    结果这题的映射关系是随意的。很简单 (我multiset写了一大堆垃圾全是WA
*/


#include <bits/stdc++.h>

using namespace std;

char s1[101], s2[101];
int num1[27], num2[27];

int main(){
    
    while (~scanf("%s%s", s1, s2)){
        if (strlen(s1) != strlen(s2)){
            cout << "NO" << endl;
            continue;
        }
       // cout << s1 << endl;
        //cout << s2 << endl;
        memset(num1, 0, sizeof num1);
        memset(num2, 0, sizeof num2);
        int len = strlen(s1);
        for (int i = 0; i < len; i++){
            num1[s1[i] - 'A']++;
            num2[s2[i] - 'A']++;
        }
        sort(num1, num1 + 26);
        sort(num2, num2 + 26);
        bool flag = true;
        for (int i = 0; i < 26; i++){
            if (num1[i] != num2[i]){
                cout << "NO" <<endl;
                flag = false;
                break;
            }
        }
       if (flag){cout << "YES" << endl;} 
    } 
    return 0;
}

/*
忽略这段垃圾代码


#include <bits/stdc++.h>

using namespace std;

int main(){

    //char s1[128], s2[128];
    string s1, s2;
    int cnt1, cnt2;

    while (getline(cin, s1) && getline(cin, s2)){
        //scanf("%s", s2);
        if (s1.length()!= s2.length()) cout << "NO" << endl;
        multiset<char> set1;
        multiset<char> set2;
        int sum1[300] = {0};
        int sum2[300] = {0}; 
        for (auto x : s1) set1.insert(x);
        for (auto x : s2) set2.insert(x);
        cnt1 = 0, cnt2 = 0;
        for (auto &m : set1) sum1[cnt1++] = set1.count(m);
        for (auto &m : set2) sum2[cnt2++] = set2.count(m);
        sort(sum1, sum1 + 101);
        sort(sum2, sum2 + 101);
        for (int &x : sum1) cout << x << " ";
        cout << endl; 
        for (int &x : sum2) cout << x << " ";
        cout << endl; 
        int sz = s1.length();
        for (int i = 0; i < sz; i++){
            if (sum1[i] != sum2[i]){
                cout << "NO" << endl;
                break;
            }else{cout << "YES" << endl; break;};
        }
        return 0;
    }
}
*/