#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std;
int dp[2005][2005] = {}; // close open
int main(){
    int m, n;
    int cost[26];
    char str[2005];
    cin >> m >> n;
    cin >> str;
    for(int i = 0 ; i < m ; i++){
        char q;
        int c1, c2;
        cin >> q >> c1 >> c2;
        cost[q-'a'] = min(c1,c2);
    }
    
    for(int i = 0 ; i < n ; i ++)
        dp[i][i+1] = 0;

    for(int div = 2 ; div <= n ; div++)
        for (int i = 0 ; (i + div) <= n ; i++){
            dp[i][i+div] = min(dp[i][i+div-1] + cost[str[i+div-1]-'a'], dp[i+1][i+div] + cost[str[i] - 'a']);
            if(str[i] == str[i+div-1])
                dp[i][i+div] = min(dp[i+1][i+div-1], dp[i][i+div]);
        }
    cout << dp[0][n];
}
