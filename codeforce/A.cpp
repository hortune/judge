#include <cstdio>
bool bool_1[6][5]={};
struct position
{
	int x,y;
}phone[10];

int main()
{
	phone[0].x=4;
	phone[0].y=2;
	phone[1].x=1;
	phone[1].y=1;
	phone[2].x=1;
	phone[2].y=2;
	phone[3].x=1;
	phone[3].y=3;
	phone[4].x=2;
	phone[4].y=1;
	phone[5].x=2;
	phone[5].y=2;
	phone[6].x=2;
	phone[6].y=3;
	phone[7].x=3;
	phone[7].y=1;
	phone[8].x=3;
	phone[8].y=2;
	phone[9].x=3;
	phone[9].y=3;	
	for(int i=1;i<4;i++)
		for(int j=1;j<4;j++)
			bool_1[i][j]=1;
	bool_1[4][2]=1;
	int num,tot[10]={};
	scanf("%d",&num);
	char c;
	scanf("%c",&c);
	for(int i=0;i<num;i++)
	{
		scanf("%c",&c);
		tot[i]=c-'0';
	} 
	bool yes[4]={true,true,true,true};
	for(int i=0;i<num;i++)	
		{
		//	printf("%d %d\n",phone[tot[i]].x,phone[tot[i]].y+1);
			if(!bool_1[phone[tot[i]].x][phone[tot[i]].y+1])
				yes[0]=0;
			if(!bool_1[phone[tot[i]].x][phone[tot[i]].y-1])
				yes[1]=0;
			if(!bool_1[phone[tot[i]].x+1][phone[tot[i]].y])
				yes[2]=0;
			if(!bool_1[phone[tot[i]].x-1][phone[tot[i]].y])
				yes[3]=0;
		}
	bool ans=0;
	for(int i=0;i<4;i++)
	if(yes[i])
	ans=1;
	if(!ans)
		printf("YES\n");
	else
		printf("NO\n");
}
