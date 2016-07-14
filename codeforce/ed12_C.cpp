#include <bits/stdc++.h>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	char pre;
	pre=' ';
	string str;
	getline(cin,str);
	cout<<str[0];
	for(int i=1;i<str.size();i++)
	{
		if(str[i-1]==str[i])
		{
			if((i+1)==str.size())
			{
				str[i]=(str[i]+1-'a')%26+'a';
			}
			else
			{
				char temp = (str[i+1]+1-'a')%26+'a';
				if(temp==str[i])
					str[i]=(str[i]+1-'a')%26+'a';
				else
					str[i]=temp;
			}
			
		}
		cout<<str[i];
		
	}	
} 
