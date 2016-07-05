#include <cstdio>
struct vector
{
	int x, y;
};
int area (vector &a,vector &b,vector &c)
{
	int ans=0;
	ans+=a.x*b.y+b.x*c.y+c.x*a.y;
	ans-=a.y*b.x+b.y*c.x+c.y*a.x;
	if(ans<0)
		return -ans;
	else
		return ans;
}
int main()
{
	vector a,b,c,d,origin;
	origin.x=origin.y=0;
	scanf("%d%d%d%d%d%d%d%d",&a.x,&a.y,&b.x,&b.y,&c.x,&c.y,&d.x,&d.y);
	int area1 = area(a,b,c)+area(a,c,d);
	int area2 = area(a,b,origin)+area(b,c,origin)+area(c,d,origin)+area(a,d,origin);
//	printf("%d %d",area1,area2);
	if(area1==area2)
		puts("1");
	else
		puts("0");

}
