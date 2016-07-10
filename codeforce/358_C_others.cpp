#include<bits/stdc++.h>
using namespace std;
vector <pair<long,long> >k[100001];
int data[100001];
int ans;
void dfs(int node,long long d)
{
	if(d>data[node])
	{
		return ;
	}
	ans++;
	for(int i=0;i<k[node].size();i++)
	{
		dfs(k[node][i].first,max(d+k[node][i].second,0LL));//here use dp really cool
	}
}
int main()
{
	int n;
	while(~scanf("%d",&n))
	{
		ans=0;
		for(int i=0;i<n;i++)
		{
			scanf("%d",&data[i]);
		}
		for(int i=1;i<n;i++)
		{
			int a,b;
			scanf("%d%d",&a,&b);
			a--;
			k[a].push_back(make_pair(i,b));
		}
		dfs(0,0);
		printf("%d\n",n-ans);
	}
}
