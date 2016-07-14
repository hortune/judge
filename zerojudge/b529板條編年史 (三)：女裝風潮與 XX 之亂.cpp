#include <bits/stdc++.h>
using namespace std;
vector<string> a;
string temp;
void print()
{
	for(int i=0;i<a.size();i++)
		cout<<"\\"<<a[i];
	cout<<"\\"<<endl;
}
void parse()
{
	int i=0;
	string te;
	if(temp[i]=='\\')
		i++,a.clear();
	
	for(;i<temp.size();i++)
	{
		if(temp[i]=='_')
			i++,a.erase(a.end()-1);
		else if(temp[i]=='\\')
			a.push_back(te),te.clear();
		else
			te+=temp[i];
//		cout<<"te : "<<te<<endl;
	}
	if(te.size())
		a.push_back(te);
//	cout<<"te :" <<endl;
}
int main(){
	
	int total_line;
	ios::sync_with_stdio(false);
	cin>>total_line;
	cin.ignore();
	while(total_line--)
	{
		
		getline(cin,temp);
		if(temp=="Where's my asphalt?")
			print();
		else 
		{
			getline(cin,temp);
			parse();
		}
	}	
} 
