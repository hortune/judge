#include <cstdio>
//Â²³ædp 
int profit[102]={};

int main()
{
	int a;
	int v,p;
	while(scanf("%d",&a)!=EOF){
		for(int i=0;i<=100;i++)
			profit[i]=0;
		while(a--)
		{
			scanf("%d %d",&v,&p);
			for(int i=100;i-v>=0;i--)
			{
				if(profit[i]<(profit[i-v]+p))
					profit[i]=profit[i-v]+p;
			}
		}
		printf("%d\n",profit[100]);
	} 
}
