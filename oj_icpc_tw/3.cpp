#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, prev = 0, ans = 0, num;
    bool first = true;
    scanf("%d",&n);
    
    for(int i = 0 ; i < n ; i++){
        scanf("%d", &num);
        ans += (first || prev != num);
        prev = num;
        first = false;
    }
    printf("%d\n", ans);
}
