#include <bits/stdc++.h>
using namespace std;
vector <int> prime;
vector <int> odd,even;
bool prime_table[1500]={};
bool it_is_prime(int m)
{
	for(int i=0;i<prime.size();i++)
		if(prime[i]>=m)
			break;
		else if(m%prime[i]==0)
			return false;
	return true;
}
int main()
{
	for(int i=2;i<1500;i++)
		prime_table[i]=true;
	for(int i=2;i<1500;i++)
		if(prime_table[i]) 
		{
		//	cout<<i<<" ";
		prime.push_back(i); 
		for(int j=2*i;j<1500;j+=i)
			prime_table[j]=0;
		} 
	int num[3]={};
	int b,temp_prime,ggg;
	bool have_prime=0;
	scanf("%d",&ggg);
	while(ggg--)
	{
		scanf("%d",&b);
		if(b==1)
			num[1]++;
		else if(b==2)
			num[2]=2,have_prime=1,temp_prime=2;
		else if(!have_prime&&it_is_prime(b))
			have_prime=1,temp_prime=b;

		if(b%2==1)
			odd.push_back(b);
		else{
			even.push_back(b);
			if(!num[2]&&it_is_prime(b+1))
				num[2]=b;
		}
	}
	if(num[1]>=2&&num[2])
	{
		cout<<num[1]+1<<endl;
		for(int i=0;i<num[1];i++)
			cout<<"1 ";
		cout<<num[2]<<endl;
	}
	else if(num[1]>=2)
	{
		cout<<num[1]<<endl;
		for(int i=0;i<num[1];i++)
			cout<<"1 ";
		cout<<endl;
	}
	else
	{	
		sort(even.begin(),even.end());
		sort(odd.begin(),odd.end());
		even.resize(unique(even.begin(),even.end())-even.begin());
		odd.resize(unique(odd.begin(),odd.end())-odd.begin());
		for(int i=0;i<even.size();i++)
			for(int j=0;j<odd.size();j++)
				if(it_is_prime(even[i]+odd[j]))
					{
						cout<<2<<endl;
						cout<<even[i]<<" "<<odd[j];
						return 0;
					}
					
		cout<<1<<endl;
		if(even.size())
		cout<<even[0]<<endl;
		else
		cout<<odd[0]<<endl;
		/*if(have_prime)
			cout<<1<<endl<<temp_prime<<endl;
		else 
			cout<<0<<endl;
		*/
	}
}
