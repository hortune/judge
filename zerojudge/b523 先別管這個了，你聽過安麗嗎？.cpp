#include <bits/stdc++.h>
using namespace std;
int main()
{
	string str;
	ios::sync_with_stdio(false);
	map<string,bool> ma_in_9;
	while(getline(cin,str))
	{
		if(ma_in_9[str])
			cout<<"YES"<<endl;
		else
		{
			cout<<"NO"<<endl;
			ma_in_9[str]=1;
		}
	}
} 
