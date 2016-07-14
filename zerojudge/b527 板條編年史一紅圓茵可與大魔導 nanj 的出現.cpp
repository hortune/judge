#include <bits/stdc++.h>
using namespace std;
int a,num[22]={};
bool solve()
{
	int upper_boun=(1<<a)-1;
//	cout<<upper_boun<<endl;
		for(int i=1;i<upper_boun;i++)
		{
			
			int fake_i=i,sum1=0,sum2=0;
			for(int j=1;j<=a;j++)
			{
				if(fake_i&1)
					sum1+=num[j];
				else
					sum2+=num[j];
				fake_i>>=1;
			}
			if((sum1%10007)==sum2%10007)
				return true;
		}
	return false;
}
int main()
{
	ios::sync_with_stdio(false);

	cin>>a;
	for(int i=1;i<=a;i++)
		cin>>num[i];
	if(a==1)
		cout<<"NO"<<endl;
	else
	{
		if(solve())
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	} 
}	
