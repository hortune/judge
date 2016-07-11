#include <bits/stdc++.h>
int main()
{
	bool yes=0;
	int a;
	char name[20]; 
	scanf("%d",&a);
	while(a--)
	{
		int before, after;
		scanf("%s %d %d",name,&before,&after);
		//printf("%s\n",name);
		if(after>before&&before>=2400)
			{
				yes=1;
				break;
			}
	}
	if(yes)
		printf("YES");
	else
		printf("NO");
}
