/*
 * @Descripttion:例题6-3 矩阵链乘（Matrix Chain Multiplication, UVa 442） 
 * @Author: Xiaobin Ren
 * @Date: 2020-03-24 10:43:09
 * @LastEditTime: 2020-03-24 11:03:48
 */

#include <bits/stdc++.h>

using namespace std;

struct matrix{
    int a, b;
    matrix(int a = 0, int b = 0) : a(a), b(b) {}
}m[26];

stack<matrix> s;

int main(){
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){  //读取所有数据， 放在一个结构体数组里面
        string name;
        cin >> name;
        int k = name[0] - 'A';
        cin >> m[k].a >> m[k].b;
    }
    string expr;  //表达式
    while (cin >> expr){
        int len = expr.length();
        bool error = false;
        int ans = 0;
        for (int i = 0; i < len; i++){
            if (isalpha(expr[i])) s.push(m[expr[i] - 'A']); //压栈处理，遇到右括号弹出计算再压进去
            else if(expr[i] == ')'){
                matrix m2 = s.top(); s.pop();
                matrix m1 = s.top(); s.pop();
                if (m1.b != m2.a) {error = true; break;}
                ans += m1.a * m2.b * m1.b;
                s.push(matrix(m1.a, m2.b));
            }
        }
        if(error) printf("error\n"); else printf("%d\n", ans); //只有一个矩阵的特殊情况也包含在内
    }
    return 0;
}