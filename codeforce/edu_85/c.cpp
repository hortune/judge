#include <bits/stdc++.h>
using namespace std;
long long int A[300001], B[300001];
int main(){
    int T;
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        for(int i = 0 ; i < n ; i++)
            cin >> A[i] >> B[i];
        for(int i = 0 ; i < n ; i++)
            B[i] = min(B[i], A[(i + 1) % n]);
        long long int ans = 0;
        long long int min_num = 214748364700000;
        for(int i = 0 ; i < n ; i++){
            ans += A[i] - B[(i - 1 + n) % n];
            min_num = min(min_num, B[i]);
        }
        cout << ans + min_num << endl;
    }
}
