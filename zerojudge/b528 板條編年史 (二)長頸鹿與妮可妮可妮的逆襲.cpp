#include <bits/stdc++.h>
using namespace std;
double pi=2*asin(1);
int main()
{
	ios::sync_with_stdio(false);
	double a;
	while(cin>>a)
	{
		if(a>1.)
			cout<<"FAIL!"<<endl;
		else
		{
			a=asin(a);
			if(a>1.)
				cout<<"FAIL!"<<endl;
			else
			{
				a=acos(a)*180/pi;
				int ans=a*1000;
				//cout<<a<<endl;
				if(ans%10>=5)
					{				
						ans/=10;
						ans+=1;
					}	
				else
					ans/=10;
				cout<<ans/100;
				ans%=100;
				cout<<"."<<(ans/10)<<ans%10<<endl;
			//	setprecision(2);
			} 
		
		}
	}
}
