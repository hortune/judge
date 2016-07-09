//雖然說是greedy
//但其實就是考驗細心= =

#include <iostream>
using namespace std;
int g[4] = { 0,5,3,1 };
int main()
{
	long long int a[6] = {};
	
	while (cin >> a[0] >> a[1] >> a[2] >> a[3] >> a[4] >> a[5], a[0] + a[1] + a[2] + a[3] + a[4] + a[5])
	{
		long long int ans = a[5];//處理6x6
		ans += a[4];//處理5x5
		a[0] -= (11 * a[4]);

		ans += a[3];//處理4x4
		long long int k = 20* a[3] - 4 * a[1];
			a[1] -= (5 * a[3]);//2x2 in 3x3
			if(k>0)
			a[0] -= k;

		ans += (a[2] / 4);
		k = a[2] % 4;
		if (k)
		{
		    long long int q;
			if (a[1] <= g[k] && a[1] >= 0)
				q = 36 - k * 9 - 4 * a[1];
			else if (a[1] < 0)
				q = 36 - k * 9;
			else
				q = 36 - 9 * k - 4 * g[k];
			ans++;
			a[1] -= g[k];
			a[0] -= q;
		}
		if (a[1] > 0)
		{
			ans +=  a[1]/9;
			k = a[1] % 9;
			if (k)
				ans++;
			a[0] -= (36 - 4 * k);
		}
		if (a[0] > 0) {
			ans += a[0] / 36;
			if (a[0] % 36 != 0)
				ans++;
		}
		cout << ans << endl;
		
	}
}