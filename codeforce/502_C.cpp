#include <iostream>
using namespace std;
int main(){
	int n , i;
	cin >> n ;
	for (i = 1 ; i*i <= n ; i++);
	i--;

	while(n > 0){
		for (int j = max(n-i + 1,1) ;  j <= n ; j++)
			cout << j << " ";
		n -= i;
	}
}
