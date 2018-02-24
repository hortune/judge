#include <bits/stdc++.h>
using namespace std;
int main(){
    long long int n,k,a,b, cost =0;
    cin>>n>>k>>a>>b;
    while(n != 1){
        if (k == 1){
            cost = (n - 1) * a;
            n = 1;
            break;
        }
        if (n % k == 0){
            if((n - n/k)*a < b){
                cost += (n - n/k)*a;
            }
            else{
                cost += b;
            }
            n/=k;
        }
        else if (n > k){
            cost += a * (n%k);
            n -= n % k;
        }
        else{
            cost += a * (n%k -1 );
            n = 1;
        }
    }
    cout << cost << endl;
}
