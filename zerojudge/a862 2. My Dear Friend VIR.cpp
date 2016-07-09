#include <cstdio>
int main()
{
    double a,b;
	while(scanf("%lf %lf",&a,&b)!=EOF)
	{
	//	printf("%lf %lf",a,b);
		printf("%.4lf\n",1000*(a/b));
	}
}
