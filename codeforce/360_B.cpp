#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
	string str;
	getline(cin,str);
	
	cout<<str;
	reverse(str.begin(),str.end());
	cout<<str;
}
