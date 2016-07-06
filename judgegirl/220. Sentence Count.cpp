#include <cstdio>
int main(){
	char c,ex_c='1',ex_ex_c='a';
	bool ex_point=0,only_blank_line=0;
	int total=0;
	while(c=getchar())
	{
		switch(c)
		{
			case '.':
					ex_point=1;
					only_blank_line=1;
					break;
			case EOF:
					if(ex_point&&only_blank_line)
					 	total++;
					 	break;
			case '\n':
					if(ex_c=='.')
						{
							total++;
							ex_point=0;
						}
					break;
			case '\0':
					if(ex_c=='.')
					{
						total++;
						ex_point=0;
					}
					break;
			case ' ':
					if(ex_c==' '&&ex_ex_c=='.')
					{
						total++;
						ex_point=0;
					}
					break;
			default : 
					ex_point=0;
					only_blank_line=0;
					break;
		}
		if(c==EOF)break;
		ex_ex_c=ex_c;
		ex_c=c; 
	}
	printf("%d",total);
}
