#include <iostream>
using namespace std;
int ans, c, b, ll, l;
char a[25][25] = {};

void dfs(int g, int h)
{
	if (h<0 || h >= b || g<0 || g >= c)
		return;
	if (a[g][h] != '#')
	{
		ans++;
		a[g][h] = '#';
	}
	else return;
	dfs(g + 1, h);
	dfs(g, h + 1);
	dfs(g - 1, h);
	dfs(g, h - 1);
}

int main()
{
	char o;
	while (cin >> b >> c, b + c)
	{
		for (int i = 0; i<c; i++)
			for (int j = 0; j<b; j++)
			{
				cin >> a[i][j];
				if (a[i][j] == '@')
				{
					ll = i;
					l = j;
				}

			}
		ans = 0;
		dfs(ll, l);
		cout << ans << endl;
	}

}