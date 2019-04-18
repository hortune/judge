#include <bits/stdc++.h>
using namespace std;
long long v[1010];
long long val[1010];
long long amount[1010];
int main(){
    long long n, s, total = 0;
    cin >> n >> s;
    for (int i = 0 ; i < n ; i++){
        cin >> v[i];
        total += v[i];
    }
    if (total < s){
        cout << -1 << endl;
        return 0;
    }

    sort(v,v+n);
    s -= (total - v[0]*n);
    if (s <= 0)
        cout << v[0] << endl;
    else
        cout << v[0] - (((s - 1) / n) + 1) << endl;
}
