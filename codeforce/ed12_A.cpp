#include <bits/stdc++.h>
using namespace std;
int main()
{
	int a,b,c,d,h,m;
	ios::sync_with_stdio(false); 
	cin>>a>>b>>c>>d;
	char cha;
	cin>>h>>cha>>m;
	int time = h*60+m;
//	cout<<a<<" "<<b<<" "<<c<<" "<<d<<" "<<h<<" "<<m<<endl; 
	int ans=0;
	for(int i=time-d+1;i<time+b;i+=1)
	{
		if(i-300<0)
			continue;
		else if(i-1440>=0)
			break;
		else 
		{
			if((i-300)%c==0)
				ans++;
		}
	}
	cout<<ans<<endl;
}
 
