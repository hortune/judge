/*
    如果為 a >= 2 b
    如果 (a % b , b )為必敗， 先手 gogo
    如果 (a % b , b)為必勝， 先手構造 (a % b + b , b)  Done

    其餘狀態只能 a - b, b - a
 */

#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std;

int main(){
    int m, n;
    while(cin >> m >> n, m+n){
        bool first_win = true;

        while(1){
            int q = max(m,n), r = min(m,n);
            if (q >= (2*r) || q == r)
                break;
            else {
                m = q - r;
                n = r;
            }
            first_win = !first_win;
        }

        cout << (first_win?"Stan wins":"Ollie wins") << endl;
    }

}
