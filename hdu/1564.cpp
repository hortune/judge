/*
 1 * 1 後手贏
 2 * 2 先手贏
 3 * 3 後手贏
 奇偶性...
 */


#include <iostream>
using namespace std;
int main(){
    int n;
    while (cin>>n, n){
        if (n % 2)
            cout << "ailyanlu" << endl;
        else
            cout << "8600" << endl;
    }
}
