#include <bits/stdc++.h>
using namespace std;

char str[15], result[15];


void dfs(int n, int length){
    if (n == length){
        puts(result);
        return;
    }
    
    for (int i = n ; i >= 1 ; i--){
        result[i] = result[i-1];
    }

    for (int i = 0 ; i <= n ; i++){
        result[i] = str[n];
        dfs(n+1, length);
        result[i] = result[i+1];       
    }
}

int main(){
    int n;
    bool first = true;
    while(cin >> str){
        if (first)
            first = false;
        else
            puts("");
        dfs(0, strlen(str));
    }
}
