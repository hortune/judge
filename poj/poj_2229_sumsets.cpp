//簡易dp
//要從front 來
//因為要算重複的
//注意digit
#include <iostream>
using namespace std;
long long int dp[1000001] = {};
int main()
{
	int n;
	cin >> n;
	for (int i = 0; i <= n; i++)
		dp[i] = 1;
	for (int j = 2; j <= n; j *= 2)
		for (int i = j; i <= n; i++)
		{
			dp[i] += dp[i - j];
			if (dp[i] >= 1000000000)dp[i] %= 1000000000;
		}
	cout << dp[n] << endl;
	//system("pause");
}