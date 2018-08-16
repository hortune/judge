#include <iostream>
using namespace std;
int main(){
	int n;
	cin >> n;
	int a, b, c, d, rank = 1;
	n--;
	cin >> a >> b >> c >> d;
	int sum = a + b + c + d;

	while(n--){
		cin >> a >> b >> c >> d;
		int new_sum = a + b + c + d;
		if (new_sum > sum)
			rank ++;
	}
	cout << rank << endl;
}
