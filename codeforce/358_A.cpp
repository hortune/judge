#include <cstdio>
int main()
{
	long long int ans=0,a,b;
	scanf("%I64d %I64d",&a,&b);
	long long int last_dig_a=a%5,last_dig_b=b%5;
	
	for(int i=1;i<5;i++)
	{
		ans+=(a/5+(last_dig_a>=i))*(b/5+(last_dig_b>=(5-i)));
	}
	ans+=(a/5)*(b/5);
	printf("%I64d",ans); 
}
