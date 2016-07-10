#include <cstdio>
int main()
{
	long long int a,b,temp,mistress=0;
	scanf("%I64d%I64d",&a,&b);
	char c;
	while(a--)
	{
		scanf("\n%c",&c);
		scanf("%I64d",&temp);
		if(c=='-')
		{
			if(temp>b)
				mistress++;
			else
				b-=temp;
		}
		else
			b+=temp;
	}
	printf("%I64d %d",b,mistress);
} 
