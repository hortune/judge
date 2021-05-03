#include <iostream>
#include <string>
#include <cassert>
using namespace std;
int dp[2][10000];
int main(){
    int N, P, ans=0;
    cin >> N >> P;
    string str;
    cin >> str;
    int cur = 1;
    int last;
    for(int i = 0; i < str.length(); i++){
        last = !cur;
        fill_n(dp[cur], P, 0);
        int cur_num = str[i] - '0';
        for(int i = 0 ; i < P ; i++)
            dp[cur][((i * 10) + cur_num) % P] += dp[last][i];
        dp[cur][cur_num % P] += 1;
        ans += dp[cur][0];
        cur = !cur;
    }
    cout << ans << endl;
}
