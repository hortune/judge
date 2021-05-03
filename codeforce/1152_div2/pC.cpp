#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;
typedef long long LL;
int main(){
    LL a, b;
    cin >> a >> b;
    LL tmp = abs(a-b);
    vector<vector<LL> > primes;
    if (!tmp || a % tmp == 0)
        cout << 0 << endl;
    else {
        cout << tmp - (a % tmp) << endl;
    }
}
