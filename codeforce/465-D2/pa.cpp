#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int count = 0;
    for(int i = 1 ; i <= n/2 ; i++)
        count += ((n-i) % i == 0);
    cout << count;
}
