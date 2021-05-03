#include<bits/stdc++.h>
using namespace std;
int n,ans[500010],del[500010],ns;
int main(){
	scanf("%d",&n),ns=n,ans[n+1]=1e9;
	for(int i=1;i<=n;++i)ans[i]=1e9;
	for(int i=n;i>=1;--i){
		for(int j=(i<<1);j<=n;j+=i)ns-=!del[j],del[j]=1;
		ans[ns]=min(ans[ns],i-1);
	}
	for(int i=n;i>=2;--i)ans[i]=min(ans[i],ans[i+1]);
	for(int i=2;i<=n;++i)printf("%d%c",ans[i]," \n"[i==n]);
	return 0;
}
