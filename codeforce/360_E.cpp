#include <cstdio>

int main()
{
	bool *dp=new bool[500000];
	int a,b;
	scanf("%d %d",&a,&b);
	int temp;
	for(int i=0;i<=b;i++)
		dp[i]=0;
	dp[0]=1;
	while(a--)
	{
		scanf("%d",&temp);
		for(int i=b;(i-temp)>=0;i--)
			if(dp[i-temp])
				dp[i]=1;
	}
	int ans=0;
	for(int i=0;i<=b;i++)
		if(dp[i])
			ans++;
	printf("%d\n",ans);
	for(int i=0;i<=b;i++)
		if(dp[i])
			printf("%d ",i);
}
