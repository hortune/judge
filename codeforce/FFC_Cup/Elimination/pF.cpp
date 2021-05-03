#include <bits/stdc++.h>
#define MOD 998244353LL
#define N 200010

using namespace std;

long long dp[N][3]; 

// 0: don't have self
// 1: have self legal
// 2: single link (which is not legal yet)

int father[N];
vector<int> childs[N];
int in_count[N];

inline long long ADD(long long A, long long B){
    return (A+B) % MOD;
}
inline long long MUL(long long A, long long B){
    return (A*B) % MOD;
}
inline long long SUB(long long A, long long B){
    return (((A-B) % MOD) + MOD) % MOD;
}

int main(){
    int total;
    cin >> total;

    for(int i = 2 ; i <= total;  i++){
        cin >> father[i];
        childs[father[i]].push_back(i);
        in_count[father[i]]++;
    }

    
    queue<int> bfs;
    for (int i = 1 ; i <= total ; i++){
        if (!childs[i].size()){
            dp[i][1] = 1;
            in_count[father[i]]--;
        }
    }
    
    for (int i = 1 ; i <= total ; i++){
        if ((!in_count[i]) && (childs[i].size())){
            bfs.push(i);
        }
    }
    
    while (!bfs.empty()){
        int node = bfs.front();
        bfs.pop();
        dp[node][0] = 1;
        for (int i = 0 ; i < childs[node].size() ; i++){
            int child = childs[node][i];
            
            long long sum_child = ADD(dp[child][1], dp[child][0]);
            long long last_half = ADD(dp[child][1], dp[child][2]);

            dp[node][1] = ADD(MUL(dp[node][1], ADD(sum_child, last_half)), // 單不包, 單包
                              MUL(last_half, dp[node][2])) ;
            dp[node][2] = ADD(MUL(dp[node][2], sum_child),
                              MUL(dp[node][0], last_half));
            dp[node][0] = MUL(sum_child, dp[node][0]);
            
        }

        in_count[father[node]]--;
        if (!in_count[father[node]])
            bfs.push(father[node]);
    }
    cout << ADD(dp[1][1], dp[1][0]) << endl;
}
