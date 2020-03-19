/*
 * @Descripttion:程序4-4 素数判定（2） 
 * @Author: Xiaobin Ren
 * @Date: 2020-03-19 08:07:57
 * @LastEditTime: 2020-03-19 08:20:30
 */

/*
    注意点： 
    除了特判n≤1的情况外，程序中还使用了变量m，一方面避免了每次重复计算sqrt(n)，
    另一方面也通过四舍五入避免了浮点误差——正如前面所说，如果sqrt将某个本应是整数的值
    变成了xxx.99999，也将被修正，但若直接写m = sqrt(n)，“.99999”会被直接截掉
*/

#include <iostream>
#include <cmath>
using namespace std;

int is_prime(int n){
    if (n <=1) return 0;
    int m = floor(sqrt(n) + 0.5);
    for (int i = 2; i <= m; i++){
        if (n % i == 0) return 0;
    }
    return 1;
}

//test

int main(){

    cout << is_prime(4) << endl;
    cout << is_prime(5) << endl;

    return 0;
}