//STOP 不一定在最後面 用EOF 
#include <cstdio>
#include <map>
#include <cstring>
using namespace std;
int total;
char op_op[5][2]={"+", "-", "*", "/", "%"};
char op_33[6][3]={"==", "!=", ">", "<", ">=","<="};
char var_name[110][10]={};
int var[110]={};
int the_place(char * in)
{
	for(int i=0;i<total;i++)
		if(strcmp(var_name[i],in)==0)
			return i; 
}
struct operation
{
	int type;//0=print 1=if 2=normal 3=stop 4=goto
	int var1,var2,var3;
	int operate,destination;
}op[2000];
int main()
{

	char temp[7];
	int i=0,num;
	while(scanf("%s",var_name[i]))
	{
		if(strcmp(var_name[i],"END")==0)break;
		scanf("%s",temp);
		scanf("%d",&num);
		var[i]=num;
		i++;
	}
	total=i;
	i=1;
	bool byebye=0;
	while(scanf("%s",temp)!=EOF)
	{
		if(strcmp(temp,"STOP")==0)
		{
			op[i].type=3;
		}
		else if(strcmp(temp,"PRINT")==0)
		{
			scanf("%s",temp);
			op[i].type=0;
			op[i].var1=the_place(temp);
		}
		else if(strcmp(temp,"IF")==0)
		{
			op[i].type=1;
			scanf("%s",temp);
			op[i].var1=the_place(temp);
			scanf("%s",temp);
			for(int q=0;q<6;q++)
				if(strcmp(op_33[q],temp)==0)
					op[i].operate=q; 
			scanf("%s",temp);
			op[i].var2=the_place(temp);
			scanf("%s",temp);
			scanf("%d",&num);
			op[i].destination=num;
		}
		else if(strcmp(temp,"GOTO")==0)
		{
			scanf("%d",&num);
			op[i].type=4;
			op[i].destination=num;
		}
		else
		{
			op[i].type=2;
			op[i].var1=the_place(temp);
			scanf("%s",temp);
			scanf("%s",temp);
			op[i].var2=the_place(temp);
			scanf("%s",temp);
			for(int q=0;q<5;q++)
				if(strcmp(op_op[q],temp)==0)
					op[i].operate=q;
			scanf("%s",temp);
			op[i].var3=the_place(temp);
		}
		i++;
	}
//	printf("total command: %d\n",i);
	i=1;
	bool bye=0;
	while(1)
	{
//		printf("position %d type %d \n",i,op[i].type);
		switch(op[i].type)
		{
			case 0:
					printf("%d\n",var[op[i].var1]);
					i++;
					break;
			case 1:{ 
					bool achieve=0;
					switch(op[i].operate)
					{
						case 0:
								if(var[op[i].var1]==var[op[i].var2])
									achieve=1;
								break;
						case 1:
								if(var[op[i].var1]!=var[op[i].var2])
									achieve=1;
								break;
						case 2:
								if(var[op[i].var1]>var[op[i].var2])
									achieve=1;
								break;	
						case 3:
								if(var[op[i].var1]<var[op[i].var2])
									achieve=1;
								break;		
						case 4:
								if(var[op[i].var1]>=var[op[i].var2])
									achieve=1;
								break;		
						case 5:
								if(var[op[i].var1]<=var[op[i].var2])
									achieve=1;
								break;							
					}
					if(achieve)
						i=op[i].destination;
					else
						i++;
					break;
					} 
			case 2:{
					switch(op[i].operate)
					{
						case 0:
								var[op[i].var1]=var[op[i].var2]+var[op[i].var3];
								break;
						case 1:
								var[op[i].var1]=var[op[i].var2]-var[op[i].var3];
								break;
						case 2:
								var[op[i].var1]=var[op[i].var2]*var[op[i].var3];
								break;
						case 3:
								var[op[i].var1]=var[op[i].var2]/var[op[i].var3];
								break;
						case 4:
								var[op[i].var1]=var[op[i].var2]%var[op[i].var3];
								break;
					} 
					i++;
					break;
					} 
			case 3:
					bye=1;
					break;
			case 4:
				//	printf("dest %d\n",op[i].destination);
					i=op[i].destination;
					break;		
		}
		if(bye)break;
		
	}
}
