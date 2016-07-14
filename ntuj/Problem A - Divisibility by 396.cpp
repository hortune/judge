#include <bits/stdc++.h>
using namespace std;
int cmp(string &a,string &b)
{
	if(a.size()<b.size())
		return 0;
	if(a.size()>b.size())
		return 1;
	
	for(int i=0;i<a.size();i++)
	if(a[i]<b[i])
		return 0;
	else if(a[i]>b[i])
		return 1;
		
		return -1;
	 
}
int main()
{
	ios::sync_with_stdio(false);
	int a;
	while(cin>>a)
	{
	
		bool duplicate=0;
		string str,max;
		str.clear();
		max.clear();
		int index=0;
		int max_num=0,second_max_num=0;
		char c;
		while(a--){
			int odd=0,even=0;
			index++;
			
			str.clear();
			bool is_odd=1,prev_is_0=1;
			while((c=getchar())!='\n')
			{
				if(c==EOF) return 0;
				if(c==' ')continue;
				if(c=='0'&&prev_is_0)
					continue;
				else
				{
					prev_is_0=0;
					if(is_odd)
						odd+=c-'0';
					else
						even+=c-'0';
					is_odd^=1;
					str+=c;		
				}
			}
			cout<<even<<" "<<odd<<endl;
			if(str.empty())
				continue;
			if(abs(even-odd)%11==0&&(even+odd)%9==0)//deal with 9 and 11
			{
				int num=0;
				for(int i=str.size()-2;i<str.size();i++)//deal with 4
				if(i>=0)
						num=(num*10+(str[i]-'0'));
						
						
				if(num%4==0)
					{
						int result=cmp(str,max);
						if(result==-1)
							{
								duplicate=1;
								second_max_num=max_num;
								max_num=index;
							}
						else if(result)
							{
								duplicate=0;
								max_num=index;
								max=str;
							}
					}
			}
		}
		if(max_num)
		{
			if(duplicate) 
				cout<<second_max_num<<endl;
			else
				cout<<max_num<<endl;
		}
		else
		{
			cout<<0<<endl;
		}
		if(c==EOF)return 0;
	}
} 
