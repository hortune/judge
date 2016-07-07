//Â²³æÃD
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath>
using namespace std;
bool cmd(double a, double b)
{
	if (a > b)
		return 1;
	return 0;
}
int main()
{
	double a[101] = {};
	int d;
	cin >> d;
	for (int i = 0; i < d; i++)
		cin >> a[i];
	sort(a, a + d, cmd);
	double ans = a[0];
	for (int i = 1; i < d; i++)
		ans = 2 * sqrt(a[i] * ans);
	cout<<fixed<<setprecision(3) << ans << endl;
//	system("pause");
}