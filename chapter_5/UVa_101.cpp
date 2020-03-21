/*
 * @Descripttion:例题5-2 木块问题（The Blocks Problem，Uva 101） 
 * @Author: Xiaobin Ren
 * @Date: 2020-03-21 16:07:47
 * @LastEditTime: 2020-03-21 18:53:31
 */

/*
    sstream的输入输出逻辑： 
    无论输入输出，遇到空格换行符就会停
    如果某个 string变量含有 ‘ ’ 空格， 则不可能让sstream >> 到一个string里面完全保存
    要么保存空格前的部分，要么后部分。所以使用while(sstream >> buf),最后buf储存的是空格后的部分
    下边的代码注释掉最后两行，取消注释 33 行， 即可测试
*/

#include <bits/stdc++.h>

using namespace std;
set<string> dict; //string 集合

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s, buf;  
    while(cin >> s) {  
        for(int i = 0; i < s.length(); i++)    
        if(isalpha(s[i])) s[i] = tolower(s[i]); 
        else s[i] = ' ';  
        stringstream ss(s);  
        while(ss >> buf) dict.insert(buf); 
        //这里要用循环是因为 sstream 无论是输入还是输出， 遇到空格换行符就会停
        }
        //cout << buf << endl;
        for(set<string>::iterator it = dict.begin(); it != dict.end(); ++it)  
        cout << *it << "\n";return 0;

    return 0;
}

