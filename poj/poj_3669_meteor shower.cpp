#include <iostream>
using namespace std;
#include <queue>
int a[350][350] = {};
bool vis[350][350] = {};
queue<pair<int, int> > que;
void give(int c, int d, int t)
{
	if (a[c][d]>t || a[c][d] == -1)
		a[c][d] = t;
};
int bfs(int c, int d, int t)
{
	int gg = c * 500 + d;
	que.push(make_pair(gg, t));
	pair<int, int> k;
	do
	{
		k = que.front();
		que.pop();
		c = k.first / 500;
		d = k.first % 500;
		t = k.second;
		if (a[c][d] == -1)return t;//
		if (!(vis[c][d] || t >= a[c][d])) {
			vis[c][d] = 1;
			que.push(make_pair((c + 1) * 500 + d, t + 1));
			que.push(make_pair((c)* 500 + d + 1, t + 1));


			if (c>1)
				que.push(make_pair((c - 1) * 500 + d, t + 1));
			if (d>1)
				que.push(make_pair((c)* 500 + d - 1, t + 1));
		}
	} while (!que.empty());
	return -1;
};
int main()
{
	int b, c, d, t;
	for (int i = 0; i<350; i++)//
		for (int j = 0; j<350; j++)
			a[i][j] = -1;
	cin >> b;
	while (b--)
	{
		cin >> c >> d >> t;
		give(c + 1, d + 2, t);
		give(c + 1, d, t);
		give(c + 2, d + 1, t);
		give(c + 1, d + 1, t);
		give(c, d + 1, t);
	}
	cout << bfs(1, 1, 0) << endl;
}