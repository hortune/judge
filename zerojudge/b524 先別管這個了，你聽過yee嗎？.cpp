#include <bits/stdc++.h>
using namespace std;

int main()
{
	string str;
	ios::sync_with_stdio(false);
	while(getline(cin,str)){
	int next_y_pos=0;
	int ans=0;
	for(int i=0;i<str.size();i++)
		if(str[i]=='y')
			ans+=abs(i-next_y_pos),next_y_pos+=3;
	cout<<ans<<endl;
	}
}
