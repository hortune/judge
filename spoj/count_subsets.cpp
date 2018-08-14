#define ll long long 
#include <iostream>
using namespace std;

ll dp[1000011] = {};
const ll MOD7 = 1e9 + 7;

ll pow_mod(ll base, ll pow, ll mod=MOD7){
	ll ans = 1;
	ll iter = base % mod;
	while(pow){
		if (pow & 1){
			ans = (iter * ans) % mod;
		}
		pow >>= 1;
		iter = (iter * iter) % mod;
	}	
	return ans;
}
int main(){
	for (int i = 2 ; i <= 1e6 ; i++)
		dp[i] = (3*dp[i-1] + ((pow_mod(2,i-1) * (pow_mod(2,i-1) + MOD7 - 1)) % MOD7)) % MOD7;
	ll T, n;
	cin >> T;
	while(T--){
		cin >> n;
		cout << dp[n] << endl;
	}
}
