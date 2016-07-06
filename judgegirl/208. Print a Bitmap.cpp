#include <cstdio>
int main()
{
	int a,b,total;
	char x_1,x_2;
	unsigned long long num;
	scanf("%d %d",&a,&b);
	scanf("\n%c %c",&x_1,&x_2);
//	printf("%c %c",x_1,x_2);
	total=a*b;
	int i=0;
	while(scanf("%llu",&num)!=EOF)
	{
		for(int j=31;j>=0;j--)
		{
			if(i%a==0&&i)puts("");
			if((1<<j)&num)
				putchar(x_1);
			else
				putchar(x_2);
			i++;
			if(i==total)
				break;
		}
	}
}
