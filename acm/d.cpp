#include <bits/stdc++.h>
using namespace std;
int main(){
    long long int n, tmp;
    map<long long int,bool> vis;
    cin >> n;
    while(1){
        if (n == 1){
            cout << "HAPPY" << endl;
            return 0;
        }
        if (vis.find(n) != vis.end()){
            cout << "UNHAPPY" << endl;
            return 0;
        }

        vis[n] = true;
        
        tmp = 0;
        while(n){
            tmp += (n%10)*(n%10);
            n /= 10;
        }
        n = tmp;
    }

}
