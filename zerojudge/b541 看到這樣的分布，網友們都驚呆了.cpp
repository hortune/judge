#include <bits/stdc++.h>
using namespace std;
int main()
{
	ios::sync_with_stdio(false); 
	string str[41];
	str[1]="1";
	char temp='c';
	int num=0;
	for(int i=2;i<=40;i++)
	{
		temp='c';
		for(int j=0;j<str[i-1].size();j++)
			{
				if(temp==str[i-1][j])
					num++;
				else 
				{
					if(temp!='c')
					str[i]+=char(num+'0'),str[i]+=temp;	
					temp=str[i-1][j];
					num=1;	
				}
			}
			str[i]+=char(num+'0'),str[i]+=temp;
	}
	for(int i=1;i<41;i++)
		str[i]+='\n';
	int a;
	while(cin>>a)
		cout<<str[a];
}
