#include <iostream>
#include <algorithm>
using namespace std;
int a[10] = { 1,2,3,4,5,6,7,8,9,10 };
int b[10] = {};
int c[10] = {};
bool text(int g, int k)
{
	if (g == 1)
	{
		if (c[0] != k)
			return 0;
		else
			return 1;
	}
	for (int i = 0; i < (g - 1); i++)
		c[i] = c[i] + c[i + 1];
	return text(g - 1, k);

}
int main() {

	int g, d;
	cin >> g >> d;
	for (int i = 0; i <= g; i++)
		b[i] = a[i];
	while (next_permutation(b, b + g))
	{
		for (int i = 0; i < g; i++)
			c[i] = b[i];
		if (text(g, d))break;
	}
	for (int i = 0; i < g; i++)
		cout << b[i] << " ";
	cout << endl;

}