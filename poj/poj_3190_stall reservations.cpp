//greedy
//想法:先依開始時間sort
//最早開始的一定是第一個，所以建立他的
//然後把能開始的丟到priority_queue 以末數sort
//caution priority queue 是降冪排序...

#include <cstdio>
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
struct node
{
	int pos, fr, ba;
	bool operator <(const node& a)const
	{
		return ba > a.ba;
	}
}no[50011];
bool cmp(node &a, node&b)
{
	if (a.fr==b.fr)
		return a.ba<b.ba;
		return a.fr < b.fr;
}
int main()
{
	int num=1,a, b, c;
	priority_queue<node> q;
	int n;
	scanf_s("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf_s("%d%d", &no[i].fr, &no[i].ba);
		no[i].pos = i;
	}
	sort(no, no + n, cmp);
	q.push(no[0]);
	int ans[50010] = {};
	ans[no[0].pos] = 1;
	for (int i = 1; i < n; i++)
	{
		if ((!q.empty()) && no[i].fr>q.top().ba)
		{
			ans[no[i].pos] = ans[q.top().pos];
			q.pop();
		}
		else
		{
			num++;
			ans[no[i].pos] = num;
		}
		q.push(no[i]);
	}
	printf_s("%d\n", num);
	for (int i = 0; i < n; i++)
		printf_s("%d\n", ans[i]);
	//system("pause");
}