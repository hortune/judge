#include <cstdio>
#include <algorithm>
using namespace std;
static int arr[100002]={};
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++)
		scanf("%d",&arr[i]);
	sort(arr+1,arr+a+1);
	int ans=0;
	for(int i=1;i<=a;i++)
	{
		if(ans<arr[i])
			ans++;
	}
	printf("%d",ans+1);
}
