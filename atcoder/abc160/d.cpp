#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, x, y;
    int ans[2001] = {};
    cin >> n >> x >> y;
    for(int i = 1 ; i < n ; i++)
        for(int j = i + 1 ; j <= n ; j++){
            int dist = j - i;
            dist = min(dist, abs(j - y) + abs(x - i) + 1);
            dist = min(dist, abs(j - x) + abs(y - i) + 1);
            ans[dist] += 1; 
        }
    for (int i = 1 ; i < n ; i++)
        printf("%d\n", ans[i]);
        
}
