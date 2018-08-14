/*

n = k(p + q) + s                s = 1
後手必贏

n = k(p + q) + s + 1            s in [p,q]
先手必贏


*/


#include <iostream>
using namespace std;
int main(){
    int n,p,q;
    while(cin >> n >> p >> q){
        if (cin.eof()) break;
        int ans = n % (p+q);
        if ( ans > p || ans == 0){
            cout << "WIN" << endl;    
        } else {
            cout << "LOST" << endl;
        }
    }
}
