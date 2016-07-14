#include <bits/stdc++.h>
using namespace std;
struct data
{
	int rank,att,def,num;	
};
bool cmp(const data &a,const data &b)
{
	if(a.rank>b.rank)
		return true;
	else
		return false;
}
int yes(const data &a,const data &b)
{
	if(a.rank<=b.rank)
		return -1;
	if(a.att>b.def)
		return 1;
	else
		return 0;
}
vector <data> member; 
int main()
{
	ios::sync_with_stdio(false);
	int m;
	cin>>m;
	while(m--)
	{
		member.clear();
		int n;
		cin>>n;
		bool table[5000]={};
		queue<int> bfs; 
		for(int i=1;i<=n;i++)
		{
			int rank,att,def;
			cin>>rank>>att>>def;
			member.push_back({rank,att,def,i});
		}
		int first;
		cin>>first;
		sort(member.begin(),member.end(),cmp);
		for(int i=0;i<n;i++)
		if(member[i].num==first)
			{
				first = i;
				break;
			}
		//cout<<first<<endl;
		bfs.push(first);
		int ans=1;
		table[first]=1;
		while(!bfs.empty())
		{
			int k=bfs.front();
			/*
			don't put ans++ and table[k]=1 here
			because it will cause multiple choice
			*/
			for(int i=k+1;i<n;i++)
				if(!table[i])
				{
					int te=yes(member[k],member[i]);
					if(te==-1)
						break;
					if(te){
						bfs.push(i);
						table[i]=1;
						ans++;
					}
					
				}
			bfs.pop();	
		}
		cout<<ans<<endl;

		
	}
}
