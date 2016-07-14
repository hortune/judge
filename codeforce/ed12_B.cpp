#include <bits/stdc++.h>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	int a,b,c,temp;
	vector<int> vec;
	cin>>a>>b>>c;
	for(int i=0;i<c;i++)
		cin>>temp,vec.push_back(temp);
	int ans=0;
	for(int x=0;x<a;x++)
		for(int y=0;y<b;y++)
		{
			cin>>temp; 
			for(int i=0;i<c;i++)
			{
				if(temp==vec[i])
				{
					for(int qq=i;qq>0;qq--)
						vec[qq]=vec[qq-1];
					vec[0]=temp;
					ans+=i+1;
					break;
				}
			}
		} 
	cout<<ans<<endl;
}
