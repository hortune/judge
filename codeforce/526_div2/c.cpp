#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;
long long dp[100010][2]={}; // first dimension with end of the a, second with not
char strings[10010];
int main (){
    string str;
    cin >> str;
    int index = 0;
    for (int i = 0 ; i < str.size() ; i++){
        if (str[i] == 'a' || str[i] == 'b')
            strings[index++] = str[i];
    }
    
    if (index == 0){
        cout << 0 << endl;
        return 0;
    }

    if (strings[0] == 'a')
        dp[0][0] = 1;
    for (int i = 1; i < index ; i++){
        if (strings[i] == 'a'){
            dp[i][0] = (dp[i-1][1] + dp[i-1][0] + 1) % MOD; 
            dp[i][1] = dp[i-1][1];
        } else{
            dp[i][0] = dp[i-1][0];
            dp[i][1] = dp[i-1][0];
        }
    }
    cout << (dp[index - 1][0]) % MOD << endl;
}
