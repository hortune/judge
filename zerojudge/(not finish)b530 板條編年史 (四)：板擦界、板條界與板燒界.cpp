///tle
#include <bits/stdc++.h>
using namespace std;
bool every2[3000][3000]={},everything [3000][3000]={};
int main()
{
	ios::sync_with_stdio(false);
	int num;
	cin>>num;
	for(int i=0;i<num;i++)
		for(int j=0;j<num;j++)
			cin>>every2[i][j];
	for(int i=0;i<num;i++)
		for(int j=0;j<num;j++)
			cin>>everything[i][j];
	bool a;
	for(int i=0;i<num;i++)
		for(int j=0;j<num;j++)
			{
				cin>>a;
				bool yes=0;
				for(int qq=0;qq<num;qq++)
					if(every2[i][qq]&everything[qq][j])
						yes=1-yes;
				if(yes!=a)
					{
					cout<<"NO";
					return 0;
					}
			}
	cout<<"YES";
}


