#include <cstdio>
int gcd(long long int a,long long int b)
{
	long long int temp;
	while(b)
	{
		a%=b;
		temp=a;
		a=b;
		b=temp;	
	}
	return a;
}
long long int lcm(long long int &a,long long int &b)
{
	return a*b/gcd(a,b);
}
int main()
{
	long long int m,n,temp,remain=1;
	scanf("%I64d %I64d",&m,&n);
	bool ans=0;
	while(m--)
	{
		scanf("%I64d",&temp);
		long long int k=gcd(n,temp);
		if(k!=1)
			remain=lcm(remain,k);
	}

	if(remain%n==0)
		printf("YES");
	else 
		printf("NO");
}
