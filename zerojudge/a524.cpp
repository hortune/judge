#include <bits/stdc++.h>
using namespace std;

int result[15];
bool vis[15];

void dfs(int n, int length){
    if (n == length){
        for (int i = 0 ; i < length ; i++)
            printf("%d", result[i]);
        puts("");
        return;
    }
    for (int i = length ; i > 0 ; i--)
        if (!vis[i]){
            vis[i] = true;
            result[n] = i;
            dfs(n+1, length);
            vis[i] = false;
        }
}

int main(){
    int n;
    while(cin >> n){
        dfs(0, n);
    }
}
