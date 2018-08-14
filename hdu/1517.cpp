#include <iostream>
using namespace std;

int main(){
    double n; 
    while(cin >> n){
        if (cin.eof()) break;
        while(n > 18){
            n /= 18;
        }
        if (n <= 9) cout << "Stan wins." << endl;
        else cout << "Ollie wins." << endl;
    }
}

/*

如果是後手局
那麼只要先手出2就出9

*/


