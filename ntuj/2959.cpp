#include <bits/stdc++.h>
using namespace std;
int dp[100011][10] = {}, cum[100011] = {};
// cum[k] 代表 k位的all
const int MOD = 1000000007;


// calculate 1-bound
int query_num( string &str){
    if (str == "0")
        return 0;
    
    int ans = 0, last_num = -1;
    // head
    ans = (ans + cum[str.length()-1]) % MOD;
    
    // example 16
    for (unsigned int i = 0 ; i < str.length() ; i++){
        int real_num = str[i] - '0', cur_len = str.size()-i;
        // add 1-3
        // if the first, no boundary
        if (last_num == -1){
            if(i == (str.length()-1))  real_num++;
            //cout << "real_num "<< real_num << endl;
            for (int qq = 1 ; qq < real_num ; qq++){
                ans = (ans + dp[cur_len][qq]) % MOD;
            }
        } else {
            // 4 + 4 vs 9
            int upper = min(10, last_num+4);
            // don't touch the bound
            if (i == (str.length()-1))
                upper = min(upper, real_num + 1);
            else
                upper = min(upper, real_num);
            
            
            //cout << "bound " << max(last_num-3,0) << " " << upper << endl;
            for (int gogo = max(last_num - 3, 0) ; gogo < upper ; gogo++)
                ans = (ans + dp[cur_len][gogo]) % MOD;
        }
        
        // if the current boundary would not be used GGGG 
        if (last_num != -1 && abs(str[i-1] - str[i]) > 3)
            break;
        
        last_num = real_num; 
    }

    return ans;
}

bool validate(string str){
    for (unsigned int i = 1 ; i < str.length() ; i++)
        if (abs(str[i] - str[i-1]) > 3)
            return false;
    return true;
}

int main(){
    // create table
    for (int i = 0 ; i < 10 ; i++)
        dp[1][i] = 1;
    cum[1] = 9;
    for (int i = 2 ; i < 100002 ; i++){
        cum[i] = cum[i-1];
        for (int j = 0 ; j < 10 ; j++){
            int lower = max(0,j-3), upper = min(9,j+3);
            for (int  q = lower ; q <= upper ; q++){
                dp[i][j] = (dp[i][j] + dp[i-1][q]) % MOD;
            }
            if (j != 0)
                cum[i] = (cum[i] + dp[i][j]) % MOD;
        } 
    }
    int T;
    string a, b;
    /*
    for (int i = 1 ; i < 100001 ; i++){
        a = to_string(i);
        cout << query_num(a) + 1 << endl;
    }*/
    
    cin >> T;
    while(T--){
        cin >> a >> b;
        //cout << query_num(a) << endl;
        //cout << query_num(b) << endl;
        if (validate(a))
            cout << ((query_num(b) - query_num(a)) + 1 + MOD) % MOD << endl;
        else
            cout << ((query_num(b) - query_num(a)) + MOD) % MOD << endl;
            
    }
}
