#include <iostream>
using namespace std;
#include <string>
#include <algorithm>

int a[10] = {};
int INF = 1000000;
inline int abs(int x, int y)
{
	if (x>y)return x - y;
	return y - x;
}
int anp(int x, int y)
{
	int ans = 0;
	if (a[x] == 0)return INF;
	for (int i = x; i <= y; i++)
		ans = ans * 10 + a[i];
	return ans;
}
int main()
{
	int b, x, y;
	string in;
	cin >> b;
	cin.ignore();
	while (b--)
	{
		getline(cin, in);
		for (int i = 0; i<10; i++)a[i] = 0;
		int p = 0, ans = INF;
		string k;
		for (int i = 0; i<in.length(); i++)
			if (in[i] <= '9'&&in[i] >= '0')
				a[p++] = in[i] - '0';
		if (p == 2)ans = abs(a[0], a[1]);
		else
			do
			{
				x = anp(0, (p >> 1) - 1);
				y = anp((p >> 1), p - 1);
				if (x != INF&&y != INF&&abs(x, y)<ans)ans = abs(x, y);
			} while (next_permutation(a, a + p));
			cout << ans << endl;
	}
}