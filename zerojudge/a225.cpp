#include <cstdio>
#include <algorithm>
using namespace std;
int num[1000];
int comp(int a,int b){
	if(a%10!=b%10)
		return (a%10<b%10);
	return a>b;
}
int main(){
	int n,i;
	while(scanf("%d",&n)==1){
		for(i=0;i<n;i++)
			scanf("%d",&num[i]);
		sort(num,num+n,comp);
		for(i=0;i<n-1;i++)
			printf("%d ",num[i]);
		printf("%d\n",num[i]);
	}
}
