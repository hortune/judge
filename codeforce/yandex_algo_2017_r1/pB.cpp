#include <bits/stdc++.h>
using namespace std;
int main(){
    long long m, n;
    cin >> m >> n;
    long long ans = 0, a, b;
    for (long long i = 0 ; i < 2000 ; i++)
        if ((m - n - i) >= n){
            a = (5000 - ((m - n - i) % 5000)) % 500;
            b = (5000 - ((n+i) % 5000)) % 500;
            ans = max(a+b, ans);
        }
    cout << ans << endl;
}
