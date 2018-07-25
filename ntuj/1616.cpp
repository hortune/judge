#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;
long long int dp[1001][100001];
long long int skill[1001][2];
vector<int> childs[1001];
long long int N, K, P;

void dfs(int index, int father, long long int csum){
    for(int n = K ;  n >= csum ; n--)
        dp[index][n] = dp[father][n-skill[index][0]] + skill[index][1];

    // update cost matrix ? 
    for(auto& child :  childs[index])
        if (skill[child][0] + csum <= K){
            dfs(child, index, csum + skill[child][0]);
        }
    
    for(int n = K ;  n >= csum ; n--)
        dp[father][n] = max(dp[index][n],dp[father][n]);
}
int main(){
    int T;
    cin >> T;
    while(T--){
        cin >> N >> K;
        for(int i = 0; i <= N ;i++)
            childs[i].clear();
        
        for(int i = 0; i <= K ;i++)
            dp[0][i] = 0;
        
        // TODO clean dp[0] 
        for(int i = 1; i <= N ;i++){
            cin >> P >> skill[i][0] >> skill[i][1];
            childs[P].push_back(i);
        }
        
        dfs(0,0,0);
        
        // 反正都會更新回給dp[0] <3 
        long long int ans = 0;
        for(int i = 0 ; i<=K ; i++)
            ans = max(dp[0][i],ans);
        cout << ans << endl;
    }
}

