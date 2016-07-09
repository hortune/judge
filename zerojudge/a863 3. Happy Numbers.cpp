#include <cstdio>
bool map[2000];
int temp,qq;
bool find_thing(int &a)
{
	//printf("%d\n",a);
	if(a==1)
		return 1;
	if(a<2000)
	{	
		if(map[a])
			return 0;
		map[a]=1;
	}
	temp=0;
	while(a)
	{
		qq=a%10;
		temp+=(qq*qq);
		a/=10;
	} 
	a=temp;
	return find_thing(a);
}
int main()
{
	int a;

	while(scanf("%d",&a)!=EOF)
	{
		printf("%d ",a);
		for(int i=0;i<2000;i++)
			map[i]=0;
		bool ans=0;
		ans=find_thing(a);
		if(ans)
			printf("is a happy number\n");
		else
			printf("is an unhappy number\n");
	}
	
}
