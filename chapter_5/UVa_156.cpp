/*
 * @Descripttion: 例题5-4 反片语（Ananagrams，Uva 156） 
 * @Author: Xiaobin Ren
 * @Date: 2020-03-21 22:43:27
 * @LastEditTime: 2020-03-21 22:58:21
 */

#include <bits/stdc++.h>

using namespace std;

map<string, int> cnt;
vector<string> words;

string repr(const string& s){  //将每个单词变为小写 然后按字典序排序
    string ans = s;
    for (int i = 0; i < ans.length(); i++)
        ans[i] = tolower(ans[i]);
    sort(ans.begin(), ans.end());
    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n = 0; string s;
    while (cin >> s){
        if (s[0] == '#') break;
        words.push_back(s);
        string r = repr(s);
        if (!cnt.count(r)) cnt[r] = 0;  //如果map中没有， 就创建一个
        cnt[r]++; //存在的话 就 +1，不存在就是 1， 这个思路很巧妙
    }

    vector<string> ans;
    for (int i = 0; i < words.size(); i++)
        if (cnt[repr(words[i])] == 1) ans.push_back(words[i]);
    sort(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << endl;
    return 0;
}
