#include <bits/stdc++.h>
using namespace std;
typedef bool (*comp)(int,int);
bool compare(int a, int b)
{
   return (a>b);
}

int main()
{
	ios::sync_with_stdio(false);
	priority_queue<int, vector<int>,comp > que(compare);
	int n,s;
	scanf("%d",&n);
	char str[100]={};
	stringstream ss;
	long long int line =n;
	while(n--)
	{
		scanf("%s",str);
		if(strcmp(str,"insert")==0)
		{
			scanf("%d",&s);
			que.push(s);
			ss<<"insert "<<s<<"\n";
		}
		else if(strcmp(str,"removeMin")==0)
		{
			if(que.empty())
					{
					ss<<"insert 21232\n";
				line++;
			}
			else
				que.pop();
			ss<<"removeMin\n";
		}
		else
		{
			scanf("%d",&s);
			while(1)
			{
				if(que.empty())
				{
					line ++;
					que.push(s);
					ss<<"insert "<<s<<"\n";
					ss<<"getMin "<<s<<"\n";
					break;
				}
				int temp = que.top();
				if(s>temp)
					{
						line++;
						ss<<"removeMin\n";
						que.pop();
					}
				else if(s==temp)
				{
					ss<<"getMin "<<s<<"\n";
					break;	
				}
				else
				{
					line++;
					ss<<"insert "<<s<<"\n";
					que.push(s);
					ss<<"getMin "<<s<<"\n";
					break;
				}
			}
		}
	}
	cout<<line<<endl;
	cout<<ss.str();
}
