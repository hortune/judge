#include <iostream>
#include <string>
using namespace std;
int main(){
	int n;
	string a, b;
	cin >> n >> a >> b;
	long long int count[2][2] = {};
	for (int i = 0 ; i < n ; i++)
		count[b[i]-'0'][a[i]-'0']++;

	cout << count[0][0]*(count[0][1] + count[1][1]) + count[0][1]*count[1][0] << endl;
}
