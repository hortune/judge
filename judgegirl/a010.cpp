#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    while(cin>>n, !cin.eof()){
        vector<pair<int, int>> factors;

        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                int count = 0;
                do
                    n /= i, count++;
                while (n % i == 0);
                factors.emplace_back(i, count);
                // factors.push_back(pair<int, int>(i, 
            }
        }
        if (n >= 2) {
            factors.emplace_back(n, 1);
        }

        for (int i = 0; i < (int) factors.size(); i++) {
            cout << factors[i].first;
            if (factors[i].second > 1) {
                cout << "^" << factors[i].second;
            }
            cout << (i == (int) factors.size() - 1 ? "\n": " * ");
              
        }
    } 
}
