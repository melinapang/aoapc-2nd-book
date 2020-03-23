/*
 * @Descripttion: 习题5-2Ducci序列（Ducci Sequence, ACM/ICPC Seoul 2009, UVa1594） 
 * @Author: Xiaobin Ren
 * @Date: 2020-03-23 22:24:18
 * @LastEditTime: 2020-03-23 22:41:06
 */

/*
    序列可以直接使用vector<int>模拟，
    vector本身已经重载了等号运算符对两个容器的内容进行比较。
    所以判重和判是否全0直接用“==”操作符即可，
    判重可以使用set < vector<int> >.

*/

#include <bits/stdc++.h>

using namespace std;

int readint(){ int x; scanf("%d", &x); return x;}

int main(){
    int t = readint();  // 样例个数
    vector<int> seq, zeroseq;
    set<vector<int>> seqs;
    while (t--){
        int n = readint();  // 每个序列的数字个数
        seq.clear(); zeroseq.resize(n);
        for (int i = 0; i < n; i++) seq.push_back(readint());
        
        bool zero = false, loop = false;
        seqs.clear(); seqs.insert(seq);
        do{
            if (seq == zeroseq) { puts("ZERO"); break;}

            int a0 = seq[0];
            for (int i = 0; i < n; i++){
                if (i == n - 1)
                    seq[i] = abs(seq[i] - a0);
                else seq[i] = abs(seq[i] - seq[i+1]);
            }
            if (seqs.count(seq)) {puts("LOOP"); break;}
            seqs.insert(seq);
        }while(true);
    }
    return 0;
}