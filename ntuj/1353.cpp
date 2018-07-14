// dp(m,n) 代表m個人 長為n的排法
// dp(m,n) = dp(m-1,n)*n + dp(m-1,n-1)*n
// initialize dp(m,1) = 1


#include <cstdio>
#include <iostream>
using namespace std;

int main(){
    int t;
    cin >> t;
    long long int dp[1001][1001] = {};
     
    for (int i = 0; i < 1001; i++)
        dp[i][1] = 1;

    for (int i = 2; i < 1001; i++)
        for(int j = 2; j <= i; j++)
            dp[i][j] = (dp[i-1][j]*j + dp[i-1][j-1]*j) % 10056;
    long long int ans[1001] = {};
    
    for (int i = 1; i < 1001; i++){
        for (int j = 1 ; j <= i ; j++)
            ans[i] += dp[i][j];
        ans[i] %= 10056;
    }
    
    while(t--){
        int n;
        cin >> n;
        cout << ans[n] << endl;
    }        
}
