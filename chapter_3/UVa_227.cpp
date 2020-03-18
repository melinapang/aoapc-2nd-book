/*
 * @Descripttion:习题3-5 谜题（Puzzle，ACM/ICPC World Finals 1993，UVa227） 
 * @Author: Xiaobin Ren
 * @Date: 2020-03-18 16:39:26
 * @LastEditTime: 2020-03-18 20:43:49
 */

/*
    不愧是 final题嗷 
    输入输出给我整懵逼了
    原书采用getline() 来读入， 这里用 fgets() 但是 fgets()要处理最后的换行符
    还有处理指令行 0  后面的换行符

*/
#include <bits/stdc++.h>

using namespace std;

char puzzle[10][10];

void printGraph(){   //打印图
    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j++){
            if (j) cout << ' '; //输出行尾不能有回车 
            cout << puzzle[i][j];
        }
        cout << endl;
    }
}

int main(){
    int kase = 0;
    while (fgets(puzzle[0], 7, stdin)){ //读取图的第一行以及末尾换行符 一共6字符
        if (puzzle[0][0] == 'Z') break;
        for (int i = 1; i < 5; i++){   //读取剩下的 4 行
            fgets(puzzle[i], 7, stdin);
        }
     // printGraph();
        int ei = 0, ej = 0; //空格的横纵坐标
        for (int i = 0; i < 5; i++){
            for (int j  = 0; j < 5; j++){   //找出空格的横纵坐标
                if (puzzle[i][j] == ' '){
                ei = i;
                ej = j;
                break;
                }
            }
        }
        bool valid = true;  //指令有效标记
        char moves[101]; //存储指令
        int cnt = 0;
        char c;
        while (scanf("%c", &c) == 1 && c != '0'){
            moves[cnt++] = c;
        }
        int ni = ei, nj = ej;
        for (int i = 0; i < cnt; i++){
            switch(moves[i]) //进行转换操作
            {
                case 'A': ni = ei-1; nj = ej; break;
                case 'B': ni = ei+1; nj = ej; break;
                case 'L': nj = ej-1; ni = ei; break;
                case 'R': nj = ej+1; ni = ei; break;
                default: break;
            }
             //printGraph();
            if (ni < 0 || nj < 0 || ni > 4 || nj > 4){  //超出边界
                valid = false;
                break;
            }else{
                swap(puzzle[ei][ej], puzzle[ni][nj]);
                ei = ni;
                ej = nj; //更新空格位置 
            }
        } //转换完毕
        //printGraph();
        getchar(); // 过滤掉指令 0 后边的回车 
        if (kase++) cout << endl; //在第一个输出以后输出换行
        cout << "Puzzle #" << kase << ":\n"; 
        if (valid == false)
            cout << "This puzzle has no final configuration." << endl;
        else
            printGraph();
    }
    return 0;
}