#include <bits/stdc++.h>
using namespace std;
int cum[100001] = {};
// cum[k] 代表 k位的all
const int MOD = 1000000007;
bool validate(string str){
    for (unsigned int i = 1 ; i < str.length() ; i++)
        if (abs(str[i] - str[i-1]) > 3)
            return false;
    return true;
}
int main(){
    cum [0] = 1;
    for (int i = 1 ; i < 100001 ; i++){
        cum[i] = cum[i-1];
        if(validate(to_string(i)))
            cum[i]++;
    }

    for (int i = 1 ; i < 100001 ; i++){
        cout << cum[i] << endl; 
    }
}
