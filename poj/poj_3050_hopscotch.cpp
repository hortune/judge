#include <iostream>
using namespace std;
int a[5][5];
bool c[1000000] = {};

void dfs(int i, int j, int k, int b)
{
	b = b * 10 + a[i][j];
	if (k == 5)
	{
		// cout<<b<<endl;
		c[b] = 1;
		return;
	}
	if (i<4)
		dfs(i + 1, j, k + 1, b);
	if (j<4)
		dfs(i, j + 1, k + 1, b);
	if (i>0)
		dfs(i - 1, j, k + 1, b);
	if (j>0)
		dfs(i, j - 1, k + 1, b);

};
int main()
{
	int gg = 0;
	for (int i = 0; i<5; i++)
		for (int j = 0; j<5; j++)
			cin >> a[i][j];
	for (int i = 0; i<5; i++)
		for (int j = 0; j<5; j++)
			dfs(i, j, 0, 0);
	for (int i = 0; i<1000000; i++)
		if (c[i])
			gg++;
	//cout<<gg<<" : "<<i<<endl;
	cout << gg << endl;

}