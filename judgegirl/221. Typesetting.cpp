#include <cstdio>
#include <cstring>
int main()
{
	char str[128][256]={};
	int m,amount=0;
	scanf("%d",&m);
	int size=0;
	while(scanf("%s",str[amount])!=EOF)
	{
		int temp=strlen(str[amount]);
		if((size+temp)>m)
		{
			if(amount!=1) 
			{
				int least = m-(size-amount);
				int temp_1=least/(amount-1);
				int temp_2=least%(amount-1);
				printf("%s",str[0]);
				for(int i=1;i<amount;i++)
				{
					for(int j=0;j<temp_1;j++)
						putchar(' ');
					if(temp_2)
						putchar(' '),temp_2--;
					printf("%s",str[i]);	
				}
			}
			else
			{
				printf("%s",str[0]);
				for(int i=0;i<m-size+1;i++)
					putchar(' ');
			}
			puts("");
			strcpy(str[0],str[amount]);
			amount=1;
			size=temp+1;
			continue;
		}
		else if((size+temp)==m)
		{
			bool first = 1;
			printf("%s",str[0]);
			for(int i=1;i<=amount;i++)
				printf(" %s",str[i]);
			printf("\n");
			amount=0;
			size=0;
			continue;
		}
		
		size+=temp+1;
		amount++;
	}
	if(amount)
	{
		if(amount!=1) 
			{
				int least = m-(size-amount);
				int temp_1=least/(amount-1);
				int temp_2=least%(amount-1);
				printf("%s",str[0]);
				for(int i=1;i<amount;i++)
				{
					for(int j=0;j<temp_1;j++)
						putchar(' ');
					if(temp_2)
						putchar(' '),temp_2--;
					printf("%s",str[i]);	
				}
			}
			else
			{
				printf("%s",str[0]);
				for(int i=0;i<m-size+1;i++)
					putchar(' ');
			}
			puts("");
	}
}
