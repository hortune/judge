//bfs easy
#include <cstdio>
int map[102][102]={};
int max=0;
bool visit[102][102]={};
int bfs(int i,int j)
{

	if(visit[i][j]||map[i][j]==0)
		return 0;
	int ans=0;
	ans=map[i][j];
	visit[i][j]=1;
	ans+=bfs(i+1,j)+bfs(i-1,j)+bfs(i,j+1)+bfs(i,j-1);
	
	return ans;
} 
int main(){
	int m,n;
	while(scanf("%d %d",&m,&n)!=EOF)
	{
		max=0;
		for(int i=0;i<=m+1;i++)
			for(int j=1;j<=n+1;j++)
				map[i][j]=visit[i][j]=0;
		for(int i=1;i<=m;i++)
			for(int j=1;j<=n;j++)
				scanf("%d",&map[i][j]);
				
		int total=0;
		for(int i=1;i<=m;i++)
			for(int j=1;j<=n;j++)
				if(!visit[i][j]&&map[i][j])
				{
					total++;
					int temp = bfs(i,j);
					if(temp>max)
						max = temp;	
				}	
		printf("%d\n%d\n",total,max);
	}	
	
}
