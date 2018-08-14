#define ll long long 
#include <bits/stdc++.h>
using namespace std;

const ll MOD = 1e9 + 7;
ll ext_eular(ll a, ll b, ll &x, ll &y){
    ll d = a;
    if (b){
        d = ext_eular(b, a%b, y, x);
        y -= (a/b)*x;
    } else {
        x = 1, y = 0;
    }
    return d;
}

ll mod_reverse(ll num){
    ll ans, tmp;
    ext_eular(num,MOD,ans,tmp);
    return (ans + MOD) % MOD;
}

int nums[100010][2];

int main(){
    int n, m;
    ll ans = 0, same = 1;
    cin >> n >> m;
    for (int i = 0 ; i < n ; i++)
        cin >> nums[i][0];

    for (int i = 0 ; i < n ; i++)
        cin >> nums[i][1];
    
    for (int i = 0; i < n && same  ; i++){
        if(nums[i][0] == 0 && nums[i][1] == 0){
            ans += ((((m-1) * mod_reverse(2*m)) % MOD) * same) % MOD;
            same = (same * mod_reverse(m)) % MOD;
        } else if (nums[i][0] == 0){
            same = (same * mod_reverse(m)) % MOD;
            ans += (same * (m-nums[i][1])) % MOD;
        } else if (nums[i][1] == 0) {
            same = (same * mod_reverse(m)) % MOD;
            ans += (same * (nums[i][0]-1)) % MOD;
        } else {
            ans += (nums[i][0] > nums[i][1] ? same : 0);
            same *= (nums[i][0] == nums[i][1]);
        }
        ans %= MOD;
    }
    cout << ans << endl;
}
