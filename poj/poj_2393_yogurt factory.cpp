#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int a, b,c,d,num=25000;
	cin >> a >> b;
	long long int ans = 0;
	while (a--)
	{
		cin >> c >> d;
		num = min(num, c);
		ans += num*d;
		num += b;
	}
	cout << ans << endl;
	//system("pause");
}