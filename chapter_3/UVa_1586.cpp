/*
    习题3-2 分子量（Molar Mass, ACM/ICPC Seoul 2007, UVa1586）
*/

/*
    自己用栈的做法，但是浮点数有误差， 题目没规定小数位啊
    差距就是浮点数的精度，交上去 WA了 2333333
    这个题如果不卡精度，我这个做法, 将会绝杀。可惜杀不得。
*/

#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, i = 0;
    stack<char> st;
    scanf("%d\n", &n); 
    while (n--){
        double sum = 0;
        char s[128];
        scanf("%s",s);
        i = 0;
        while (i < strlen(s)){
           // if (!isdigit(s[i]) && !isalpha(s[i])) break;
            if (s[i] == '\0') break;
            for (i; i < strlen(s); i++){ //数字压栈
               // if (isalpha(s[i])) st.push(s[i]);
               if (s[i] >= 'A' && s[i] <= 'z') st.push(s[i]);
               // if (isdigit(s[i]) && isdigit(s[i+1])){st.push(s[i]); st.push(s[i+1]);i+=2;break;}
                if (s[i] > '0' && s[i] <='9' && s[i+1] > '0' && s[i+1] <='9'){st.push(s[i]); st.push(s[i+1]);i+=2;break;}
               // if (isdigit(s[i]) && !isdigit(s[i+1])){st.push(s[i]); i++;break;}
                if (s[i] >'0' && s[i] <='9' && s[i+1] >='A' && s[i+1] <='z'){st.push(s[i]); i++;break;}
            }
               int a = 1;
               if(st.top() > '0' && st.top() <= '9'){
                    a = st.top() - '0';
                    st.pop();
               }
               // if (isdigit(st.top())){a = 10 * st.top() + a; st.pop();} //求出每节的末尾数字
                if (st.top() >'0' && st.top() <='9'){a = 10 * (st.top()-'0') + a; st.pop();} //求出每节的末尾数字
                if (st.top() == 'C'){sum += a*12.01;}  //求数字左边第一个的值，下边的要么空
                //要么只有一个元素 
                if (st.top() == 'N'){sum += a*14.01;}
                if (st.top() == 'H'){sum += a*1.008;}
                if (st.top() == 'O'){sum += a*16.00;}
                st.pop();//弹出末尾第一个字母
                while(!st.empty()){ //求出栈中剩余的 sum
                    if (st.top() == 'C'){sum += 12.01;st.pop();}
                    if (!st.empty() && st.top() == 'N'){sum += 14.01;st.pop();}
                    if (!st.empty() && st.top() == 'H'){sum += 1.008;st.pop();}
                    if (!st.empty() && st.top() == 'O'){sum += 16.00;st.pop();}
                }
        }
        printf("%.3lf\n", sum);
    }

    return 0;
    
}


/*
原书的做法：一行注释都没有 看不懂 告辞
*/

#include <bits/stdc++.h>

using namespace std;

int main(){
    int T, sz, cnt;
    double w[256], ans;
    char buf[256], c, s;
    w['C'] = 12.01;
    w['H'] = 1.008;
    w['O'] = 16.0;
    w['N'] = 14.01;
    scanf ("%d\n", &T);
    while (T--){
        scanf ("%s", buf);
        ans = 0;
        s  =0; cnt = -1; sz = strlen(buf);
        for (int i = 0; i < sz ; i++){
            char c = buf[i];
            if (isupper(c)){
                if (i){
                    if (cnt == -1) cnt = 1;
                    ans += w[s] * cnt;
                }
                s = c;
                cnt = -1;
            }else{
                assert(isdigit(c));
                if (cnt == -1) cnt = 0;
                cnt = cnt * 10 + c - '0';
            }
        }
        if (cnt  == -1) cnt = 1;
        ans += w[s] * cnt;
        printf("%.3lf\n", ans);
    }
    return 0;

}