#include <cstdio>
int main()
{
	int a,b,c,d,e;
	scanf("%d%d%d%d%d",&a,&b,&c,&d,&e);
	int volume = a*b*c-2*(d*(c-2*e)*(b-2*e)+d*(a-2*e)*(b-2*e)+d*(a-2*e)*(c-2*e));
//	volume-=(a-2*e)*(b-2*d)*(c-2*e);
	int surface = 2*(a*b+b*c+a*c);
	surface+=8*(a-2*e+b-2*e+c-2*e)*d;
	printf("%d\n%d",surface,volume);
	
}
