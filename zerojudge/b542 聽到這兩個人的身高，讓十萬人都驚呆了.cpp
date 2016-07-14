//BS ©~µM¹L¤F §è 
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int main()
{
	LL n,q,ki;
	map <LL,bool> _map;
	vector <LL> _seq;
	ios::sync_with_stdio(false);
	cin>>n>>q;
	while(n--)
	{
		cin >> ki;
		_seq.push_back(ki);
	}
	sort(_seq.begin(),_seq.end());
	LL max = *(_seq.end()-1);
	while(q--)
	{
		cin>>ki;
		bool yes=0;
		for(int i=0;(_seq[i]+ki)<=max;i++)
		if(binary_search(_seq.begin()+i, _seq.end(),
                  _seq[i]+ki)) {
				yes=1;
				break;	
			}  
		if(yes)cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
}
