////didn't summit
#include <stdio.h>
#include <stdbool.h>
int ans[102][102]={};
bool is_1[102][102]={};
int i,j;
void intersection(int map[100][100], int result[4])
{
	for(i=1;i<=100;i++)
		for(j=1;j<=100;j++)
			{
				//scanf("%d",&temp);	
				if(map[i-1][j-1]==1)
					is_1[i][j]=1,ans[i][j+1]++,ans[i+1][j]++,ans[i-1][j]++,ans[i][j-1]++; 
			}
	int result_temp[5]={};
	for(i=1;i<=100;i++)
		for(j=1;j<=100;j++)
			if(is_1[i][j])
				{
					if(ans[i][j]==2)
					{
						if(is_1[i-1][j]!=is_1[i+1][j])
							result_temp[2]++;		
					}
					else
							result_temp[ans[i][j]]++;
						//	printf("%d\n",ans[i][j]);
				}
	for(i=0;i<4;i++)
		result[i]=result_temp[4-i];
		//printf("%d ",result[i]);
}

