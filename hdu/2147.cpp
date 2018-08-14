#include <iostream>
using namespace std;
int main(){
    int m, n;
    while(cin>>m>>n, m+n){
        if ((m & 1) && (n & 1)){
            cout << "What a pity!" << endl;
        } else {
            cout << "Wonderful!" << endl;
        }
    }
}
