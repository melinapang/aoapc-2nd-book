/*
 * @Descripttion:习题3-3 数数字（Digit Counting , ACM/ICPC Danang 2007, UVa1225） 
 * @Author: Xiaobin Ren
 * @Date: 2020-03-18 09:23:24
 * @LastEditTime: 2020-03-18 10:52:39
 */

/*
    做法比较多，我是把用字符串把所有数字拼接起来，然后遍历字符串
    开一个数组来记录数字出现个数 复杂度 O(n)
*/

#include <bits/stdc++.h>

using namespace std;

int main(){
    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        string s = "";
        int a[10] = {0};
        for (int i = 1; i <= n; i++)
            s += to_string(i); //此处 to_string() 函数 整形转为字符串
        for (int i = 0; i < s.length(); i++)
            a[s[i] - '0']++; //此处注意s[i]  取得的类型是 char
        for (int i = 0; i < 9; i++)
            cout << a[i] << " ";
        cout << a[9]; //注意输出格式，最后不能有空格 第一次没管交上去PE了
        cout << endl;
    }
    return 0;
}