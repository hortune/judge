//簡單dp
//空間變化
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

struct node {
	int begin;
	int end;
	int value;
	bool operator <(const node& a)
	{
		if (begin < a.begin)return 1;
		else {
			if (begin==a.begin&&end < a.end)return 1;
			else return 0;
		}
	}

}no[1001];
int main()
{
	int dp[1001] = {};
	int n, m,r;
	cin >> n >> m >> r;
	for (int i = 0; i < m; i++)
		cin >> no[i].begin >> no[i].end>>no[i].value;
	sort(no, no + m);
	for (int i = 0; i < m; i++)
	{
		int ans = 0;
		for (int j = 0; j < i; j++)
		{
			if (ans < dp[j]&&(no[j].end+r)<=no[i].begin)
				ans = dp[j];
		}
		dp[i] = ans + no[i].value;
	}
	int ans = 0;
	for (int i = 0; i < m; i++)
		if (ans < dp[i] && no[i].end <= n)
			ans = dp[i];
	cout << ans << endl;
	system("pause");
	
}