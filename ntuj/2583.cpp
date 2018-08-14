#include <bits/stdc++.h>
using namespace std;
int main(){
    int T;
    cin >> T;
    while(T--){
        long long int n, a, b, ans, num;
        bool gg =false;
        cin >> n >> a >> b;
        ans = a * b;
        while(n--){
            cin >> num;
            ans -= num;
            if (ans < 0)
                gg = true;
        }
        if (ans || gg)
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
     }
}
