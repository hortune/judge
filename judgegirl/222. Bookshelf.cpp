#include <stdio.h>
int hasEOF = 0;
int readchar() {
    static int N = 1<<20;
    static char buf[1<<20];
    static char *p = buf, *end = buf;
    if(p == end) {
        if((end = buf + fread(buf, 1, N, stdin)) == buf) {
            hasEOF = 1;
            return EOF;    
        }
        p = buf;
    }
    return *p++;
}
int ReadInt(int *x) {
    char c, neg;
    while((c = readchar()) < '-')    {if(c == EOF) return 0;}
    neg = (c == '-') ? -1 : 1;
    *x = (neg == 1) ? c-'0' : 0;
    while((c = readchar()) >= '0')
        *x = (*x << 3) + (*x << 1) + c-'0';
    *x *= neg;
    return 1;
}
int main() {
    int x;
    unsigned long long int temp,total=0;
    int yes=(1<<8)-1;
	bool _is=0;
	while (ReadInt(&x)) {
		//printf("%d \n",x);
		temp=total;
		_is=0;
		for(int i=0;i<8;i++)
		{
		//	printf("%d\n",x&temp);
			if(((x^temp)&yes)==0)
			{
				total-=temp<<(i*8);//////
				total=((temp>>8)<<(i+1)*8)+(total<<8)+x;
				_is=1;
				break;
			}
			temp>>=8; 
		}
		if(!_is)
		{
			total<<=8;
			total+=x;
		}
		//printf("%d\n",total);
	
		// add your code
    }   
    bool first=1;
		for(int i=7;i>=0;i--)
			if(!first)
				printf(" %u",(total>>i*8)%256);
			else
				first=0,printf("%u",(total>>i*8)%256);
		//printf("\n"); 
    // output your answer
    return 0;
}
