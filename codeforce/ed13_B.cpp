#include <bits/stdc++.h>
using namespace std;
bool leaps_year(int &a)
{
	if(a%4!=0)
		return false;
	if(a%400==0)
		return true;
	if(a%100!=0)
		return true;
	return false;
}
int main()
{
	ios::sync_with_stdio(false);
	int a;
	scanf("%d",&a);
	bool a_leap=leaps_year(a);
	int n=0;
	if(a_leap)
		n+=2;
	else
		n+=1;
	for(int i=a+1;;i++)
	{
		int temp_leap=leaps_year(i);
		if(n%7==0&&temp_leap==a_leap)
		{
			cout<<i<<endl;
			return 0;
		}
		else
			{
				if(temp_leap)
					n+=2;
				else
					n+=1;
			}
	}
}
