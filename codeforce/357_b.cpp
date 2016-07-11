#include <bits/stdc++.h>
int main()
{
	int a;
	scanf("%d",&a);
	int sum,sum2;
	bool ans=1;
	for(int i=0;i<=a;i+=1234567)
	{
		sum=i;
		for(int j=0;sum+j<=a;j+=123456)
		{
			sum2=sum+j;
			if((a-sum2)%1234==0)
				{
					printf("YES");
					return 0;
				}
		}
	}
	printf("NO");
	return 0;
}
