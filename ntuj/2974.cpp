#include <bits/stdc++.h>
using namespace std;
#define app pair<int, int>

struct qaq {
    app _app;
    int index;
} apps[501];

bool cmp(qaq &a, qaq &b){
    return (a._app.first - a._app.second) > (b._app.first - b._app.second);
}
int dp[501][10001];
int father[501][10001];

int main(){
    int n, t;
    cin >> n >> t;
    for(int i = 1; i <= n ; i++){
        cin >> apps[i]._app.first >> apps[i]._app.second;
        apps[i].index= i; 
    }
    for(int i = 0; i <= t ; i++)
        father[0][i] = i;
    sort(apps+1, apps+n+1, cmp);

    for(int i = 1; i <= n ; i++){
        for(int j = t - apps[i]._app.second; j>=0 ;j--){
            if(((dp[i-1][j+apps[i]._app.second] + 1) > dp[i-1][j]) &&
                 (j + apps[i]._app.second) >= apps[i]._app.first ){
                dp[i][j] = dp[i-1][j+apps[i]._app.second] + 1;
                father[i][j] = j+apps[i]._app.second;
            }
            else{
                father[i][j] = j;
                dp[i][j] = dp[i-1][j];
            }
        }
        
        for(int j = max(t - apps[i]._app.second + 1, 0); j<=t ; j++){
            father[i][j] = j;
            dp[i][j] = dp[i-1][j];
        }
    }

    int index = -1, num = -1;
    for(int i = 0; i <= t ; i++){
        if(dp[n][i] > num)
            index = i, num = dp[n][i];
    }

    cout << dp[n][index] << endl;
    int temp[501], start = 0;
    if (num){
        for(int i = n; i>0 ; i--){
            if (father[i][index] != index){
                temp[start++] = apps[i].index;
                index = father[i][index];
            }
        }
        for (int i = start - 1; i >= 0  ; i--){
            if(i == start -1)
                cout << temp[i];
            else
                cout << " " << temp[i];
        }
        cout << endl;
    }
}
