#include <cstdio>
int main()
{
	int a,b[105];
	scanf("%d",&a);
	for(int i=0;i<a;i++)
		scanf("%d",&b[i]);
	int l,r,min=b[0],min_loc=0;
	for(int i=0;i<a;i++)
	{
		min=b[i];
		min_loc=i;
		for(int j=i+1;j<a;j++)
		{
			if(b[j]<min)
				{
					min_loc=j;
					min=b[j];
				}
		}
		for(int j=min_loc;j>i;j--)
		{
			printf("%d %d\n",j,j+1);
			int temp=b[j];
			b[j]=b[j-1];
			b[j-1]=temp;
		}
	}
		
}
