//distance 有可能小於0 ...
//區間 貪心
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
struct twodi
{
	double x_front;
	double x_back;
};
bool imp(twodi&a,twodi&b)
{
	if (a.x_front < b.x_front)return 1;
	if (a.x_front == b.x_front && a.x_back < b.x_back)return 1;
	return 0;
}
int main()
{
	long long a, b,n,m,ca=0;
	twodi c[1010];
	while (cin >> a >> b, a + b)
	{
		int ans = 1;
		bool error = 0;
		for (int i = 0; i < a; i++)
		{
			cin >> n >> m;
			long long k = b*b - m*m;
			if (k < 0) 
				error = 1;
			else {
				double g = sqrt((double)k);
				c[i].x_front = (double)n - g;//區間上界
				c[i].x_back = (double)n + g;//區間下界
			}
		}
		if (b < 0)error = 1;
		if (!error) {
			sort(c, c + a, imp);
			double max = c[0].x_back;
			
				for (int k = 1;k<a;k++)
				{
					if (c[k].x_front>max) {
						max = c[k].x_back;
						ans++;
					}
					if (c[k].x_back < max)
						max = c[k].x_back;
					
				}
		}
		ca++;
		cout << "Case " << ca << ": ";
		if (error)
			cout << -1 << endl;
		else
			cout << ans << endl;
	}
	//system("pause");
}