#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std;

int main(){
    int n;
    int dp[351][351] = {};
    
    cin >> n;

    for(int i = 0; i < n ; i++)
        for(int j = 0 ; j < i+1 ; j++)
            cin >> dp[i][j];
    
    for(int i = 1; i < n ; i++)
        for(int j = 0; j < i+1 ; j++)
            if( j == 0)
                dp[i][j] += dp[i-1][j];
            else if (j == i)
                dp[i][j] += dp[i-1][j-1];
            else 
                dp[i][j] += max(dp[i-1][j],dp[i-1][j-1]);

    int ans = 0;
    for (int i = 0; i < n ; i++)
        ans = max(ans,dp[n-1][i]);
    cout << ans ;
}
