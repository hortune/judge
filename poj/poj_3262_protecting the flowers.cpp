//把longlong 用 %d 會出錯
//水題
//取分數 greedy
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
struct node
{
	long long int t, d;
	bool operator <(const node &a)const
	{ 
		if (t*a.d < d*a.t)return 1;
		else return 0;
	}
}cow[100001];
int main()
{
	int n;
	scanf_s("%lld", &n);
	for (int i = 0; i < n; i++)
		scanf_s("%lld%lld", &cow[i].t, &cow[i].d);
	long long int ans = 0,time;
	sort(cow, cow + n);
	time = cow[0].t;
	for (int i = 1; i < n; i++)
	{
		ans += 2*time*cow[i].d;
		time += cow[i].t;
	}
	printf_s("%lld\n", ans);
	//system("pause");
}