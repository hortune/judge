#include <cstdio>
int jai[10]={};
int main()
{
	
	jai[1]=1;
	for(int i=2;i<10;i++)
	jai[i]=jai[i-1]*i;
	
	scanf("%d %d",&a,&b);
	int clone_b = b;
	int clone_a = a;
	int num_a[10],size_a=0,num_b[10],size_b=0;
	a--;
	b--;
	while(a)
	{
		if(a/7)
		{
			num_a[size_a]=a%7;
			a/=7;
			size_a++;
		}
	}
	while(b)
	{
		if(b/7)
		{
			num_b[size_b]=b%7;
			b/=7;
			size_b++;
		}
	}
	int sum=0;
	if((size_a+size_b)>7)
		sum=0;
	else if(size_a==0)
	{
		for(int i=0;i<b;i++)
		{
			bool visit[10]={};
			bool yes =1;
			num_b[0]--;
			for(int j=0;j<size_b;j++)
			{
				if(num_b[j]<0)
				{
					num_b[j+1]--;
					num_b[j]+=7;
					if(visit[num_b[j]])
						yes=0;
					visit[num_b[j]]=1;
				}
			}
			if(yes)
				sum++;
		}		
	} 
	else if(size_b==0)
	{
		for(int i=0;i<a;i++)
		{
			bool visit[10]={};
			bool yes =1;
			num_a[0]--;
			for(int j=0;j<size_a;j++)
			{
				if(num_a[j]<0)
				{
					num_a[j+1]--;
					num_a[j]+=7;
					if(visit[num_a[j]])
						yes=0;
					visit[num_a[j]]=1;
				}
			}
			if(yes)
				sum++;
		}		
	} 
	else
	{
		for(int i=0;i<a;i++)
		{
			bool visit[10]={};
			bool yes =1;
			num_a[0]--;
			for(int j=0;j<size_a;j++)
			{
				if(num_a[j]<0)
				{
					num_a[j+1]--;
					num_a[j]+=7;
					if(visit[num_a[j]])
						yes=0;
					visit[num_a[j]]=1;
				}
			}
			bool vis[10]={};
			for(int q=0;q<b;q++)
			{
				
			}
			if(yes)
				sum++;
		}		
	}
}
