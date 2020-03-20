/*
 * @Descripttion: 习题4-6 莫尔斯电码（Morse Mismatches, ACM/ICPC World Finals 1997, UVa508） 
 * @Author: Xiaobin Ren
 * @Date: 2020-03-20 16:39:00
 * @LastEditTime: 2020-03-20 17:16:32
 */

/*
    此题的表意其实很模糊，本质就是字符串匹配
    因为 “每个单词” 中的 “每个字母” 的摩斯电码不分开连在一起就会造成重复的序列
    所以多个单词的该 “电码串” 可能是相同的, 也就是可能一个电码串会对应多个单词
    从而可以用电码串来匹配单词
*/


#include <bits/stdc++.h>

using namespace std;

unordered_map<char, string> morse;  //储存每个字母/数字 对应的电码
unordered_map<string, vector<string>> context; //key 是所有合并去重之后 “可能” 的单词电码串，value是所有与之匹配的单词集合

bool isPre(const string &a, const string &b){  //a是否是b的前缀
    return a.size() < b.size() && b.compare(0, a.size(), a) == 0; 
}

void solve (const string& m){   //m就是最后来匹配单词的电码字符串
    if (context.count(m)){  //可以直接匹配上 ，不用判断前后缀截取
        const auto &v = context[m];
        assert(!v.empty());
        cout << v.front();
        if (v.size() > 1) cout << "!";
        cout << endl;
        return ;
    }

    //没有直接匹配上， 需要判断前后缀
    map<int, string> ans;  //有序map， key存放“来匹配”和“被匹配”字符串的长度差， 所求的是长度差最小的一个匹配
    for (const auto& p: context){
        const string& cm = p.first;  //以存下的电码串 cm
        if (isPre(m, cm)) ans[cm.size() - m.size()] = p.second.front();
        else if(isPre(cm, m)) ans[m.size() - cm.size()] = p.second.front();
    }
    cout << ans.begin()->second << "?" << endl; //输出长度差最小的匹配串 
}


int main(){
    string C, M;  
    while (cin >> C && C != "*"){
    //C是字母/数字， M是对应的电码。因为 cin不能输入空格， 所以要分两次入
        cin >> M;
        assert(C.size() == 1);
        morse[C[0]] = M;
    }

    while (cin >> C && C != "*"){  //C是被匹配的单词
        M.clear(); //复用 M ,  M是单词对应的电码串
        for (auto c : C) M += morse[c];
        context[M].push_back(C);
    }

    while (cin >> M && M != "*") solve(M); 

    return 0;
}