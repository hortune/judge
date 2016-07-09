#include <cstdio>
#include <vector>
using namespace std;
vector <int> a[100001];
bool visit[100001]={};
bool _color[100001]={};
int qq[2]={}; 
bool bfs(int k,bool color)
{
	if(visit[k])
	{
		if(color!=_color[k])
			return false;
		else 
			return true;	
	}
	visit[k]=true;
	_color[k]=color;
	qq[color]++;
	for(int i=0;i<a[k].size();i++)
		if(!bfs(a[k][i],1-color))
			return false;	
	return true;
}
int main()
{
	int asd,b,temp,temp1;
	scanf("%d %d",&asd,&b);
	for(int i=1;i<=b;i++)
		{
			scanf("%d %d",&temp,&temp1);
			a[temp].push_back(temp1);
			a[temp1].push_back(temp); 
		}
	bool ans=true;
	for(int i=1;i<=asd;i++)
		if(!visit[i]&&!a[i].empty())
			if(!bfs(i,0))
				ans=false;
	if(ans)
	{
		printf("%d\n",qq[0]);
		for(int i=1;i<=asd;i++)
		{
			if(visit[i])
				if(!_color[i])
					printf("%d ",i);
		}
		puts("");
		printf("%d\n",qq[1]);
		for(int i=1;i<=asd;i++)
		{
			if(visit[i])
				if(_color[i])
					printf("%d ",i);
		}
		
	}
	else
	printf("-1");			
} 
