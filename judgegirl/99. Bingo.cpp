#include <cstdio>
struct bingo_map{
	int x,y;
}everything[10][65536];
int ans_y[10][256]={};
int ans_x[10][256]={};
int ans_not[10][2]={};
char name[10][65]={};
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	
	for(int i=0;i<n;i++)
	{
		int temp;
		gets(name[i]);
		gets(name[i]);
		//puts(name[i]);
		for(int x=0;x<m;x++)
			for(int y=0;y<m;y++)
			{
				scanf("%d",&temp);
				temp--;		
				everything[i][temp].x=x;
				everything[i][temp].y=y;
			}
	
	}
	int temp;
	bool win[10]={};
	bool have_winner=0; 
	while(scanf("%d",&temp)!=EOF)
	{
		for(int i=0;i<n;i++)
		{
			int temp_x=everything[i][temp-1].x;
			int temp_y=everything[i][temp-1].y;
			ans_x[i][temp_x]++;
			if(ans_x[i][temp_x]==m)
				{
					win[i]=1;
					have_winner=1;
					continue;
				}
			ans_y[i][temp_y]++;	
			if(ans_y[i][temp_y]==m)
				{
					win[i]=1;
					have_winner=1;
					continue;
				}
			if(temp_x==temp_y)
				{
					ans_not[i][0]++;
					if(ans_not[i][0]==m)
					{	
						win[i]=1;
						have_winner=1;
						continue;
					}
				}
			if((temp_x+temp_y)==(m-1))
				{
					ans_not[i][1]++;
					if(ans_not[i][1]==m)
					{	
						win[i]=1;
						have_winner=1;
						continue;
					}
				}
		}
		
		if(have_winner)
			break;
	}
	printf("%d",temp);
	for(int i=0;i<n;i++)
		if(win[i])
			printf(" %s",name[i]);
	
}
