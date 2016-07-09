//想清楚
//dp
//easy case
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int main()
{
	int dp[31][1001][2] = {};//dp[i][j][k] 在exchange i 次 range 到j 的k樹的最大值
	int res[1001] = {};
	int a, b;
	cin >> a >> b;
	for (int i = 1; i <= a; i++)
		cin >> res[i];	
	for (int i = 1; i <= a; i++)
		dp[0][i][1] = dp[0][i - 1][1] + (res[i] == 1);
	for (int i = 0; i < b; i++)
		for (int j = 0; j <= a; j++)
		{
			dp[i+1][j+1][0] = max(dp[i][j][1], dp[i+1][j][0]) + (res[j + 1] == 2);
			dp[i+1][j+1][1] = max(dp[i][j][0], dp[i+1][j][1]) + (res[j + 1] == 1);
		}

	int ans = 0;
	for (int i = 0; i <= b;i++)
	for (int j = 0; j <= a ; j++)
		for (int z = 0; z < 2; z++)
			if (ans < dp[i][j][z])
				ans = dp[i][j][z];
	cout << ans << endl;
	system("pause");
}