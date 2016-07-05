#include <cstdio>
int main()
{
	int s,f,t;
	scanf("%d%d%d",&s,&f,&t);
	int a,b,c;
	c=s-t;
	b=(6*t-8*s+f)/2;
	a=s-b-c;
	printf("%d\n%d\n%d",a,b,c);
}
