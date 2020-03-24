/*
 * @Descripttion: 习题5-5 复合词（Compound Words, UVa 10391） 
 * @Author: Xiaobin Ren
 * @Date: 2020-03-24 09:22:27
 * @LastEditTime: 2020-03-24 09:32:49
 */

#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    set<string> words;
    string word, left, right;
    while (cin >> word) words.insert(word);  //读取所有单词
    
    for (const auto& s : words){
        for (int j = 1; j < s.size(); j++){
            left.assign(s, 0, j);
            right.assign(s, j, s.size()-j);
            if(words.count(left) && words.count(right)){
                cout << s << endl;
                break;
            }
        }
    }
    return 0;
}