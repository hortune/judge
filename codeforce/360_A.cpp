#include <cstdio>
int main()
{
	int max=0;
	int m,n,ans=0;
	char c;
	bool every;
	scanf("%d %d",&m,&n);
	for(int i=0;i<n;i++)
	{
		c=getchar();
		every=1;
		for(int j=0;j<m;j++)
			{
				c=getchar();
				if(c=='0')
					every=0;
			}
		if(every)
			{
			if(max<ans)
				max=ans;
				ans=0;	
			}
		else
			ans++;
	}
	if(!every)
	{
		if(max<ans)
			max=ans;
	}
	printf("%d",max);
}		

