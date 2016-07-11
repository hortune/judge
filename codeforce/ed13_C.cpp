#include <bits/stdc++.h>
using namespace std;

int gcd(long long int a,long long int b)
{
	while(b)
	{
		long long int temp= a%b;
		a=a%b;
		a=b;
		b=temp;
	}
	return a;
}
long long int lcm(long long int a,long long int b)
{
	return a/gcd(a,b)*b;
}
int main()
{
	ios::sync_with_stdio(false);
	long long int n,a,b,p,q;
	cin>>n>>a>>b>>p>>q;
	if(p<q)
		cout<<(n/a)*p-(p*(n/(lcm(a,b))))+(n/b)*q;
	else
		 	cout<<(n/a)*p-(q*(n/(lcm(a,b))))+(n/b)*q;
}
