#include <cstdio>
struct num
{
	long long int up,down;
}everything[500];
int gcd(long long int a,long long int b)
{
	if(a==0)
	return b;
	long long int temp;
	while(b)
	{
		a=a%b;
		temp = a;
		a=b;
		b=temp;
	}
	return a;
}
void normalization(num &a)
{
	long long int gcd_num=gcd(a.up,a.down);
	//printf("gcd_num %d\n",gcd_num);
	a.up/=gcd_num;
	a.down/=gcd_num;
}
void add(num &a, num &b)
{
		a.up=a.up*b.down+a.down*b.up;
		a.down*=b.down;
		normalization(a);
}
int main()
{
	int a,position=0;
	scanf("%d",&a);
	everything[0].up=everything[0].down=1;
	for(int i=1;i<500;i++)
		everything[i].up=0,everything[i].down=1;
	for(int i=1;i<=a;i++)
		for(int j=1;j<=i;j++)
			{
			    long long int up,down;
				scanf("%lld%lld",&up,&down);
				int gcd_num=gcd(up,down);
				up/=gcd_num;
				down/=gcd_num; 
				if(up==0)
					down=1;
				if(down==0)
					up=1;
				num temp;
				temp.up=up*everything[position].up;
				temp.down=(up+down)*everything[position].down;
				add(everything[position+i],temp);
				temp.up=down*everything[position].up;
				add(everything[position+i+1],temp);
				position++;
			}
	int gcd_num,x,y;
	for(int i=1;i<=a+1;i++)
		{
			x=everything[position].up;
			y=everything[position].down;
			gcd_num=gcd(x,y);
			printf("%d/%d\n",x/gcd_num,y/gcd_num);
			position++;
		}
}
