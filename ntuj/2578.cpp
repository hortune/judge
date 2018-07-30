#include <bits/stdc++.h>
using namespace std;
long long int  vis[100003];
long long int dp[100001];

int main(){
    int T;
    cin >> T;
    while(T--){
        // reset
        for (int i = 0 ; i < 100003 ; i ++)
            vis[i] = -1;

        long long int N, ans = 0;
        long long int M,A,B,x;
        cin >> N >> M >> A >> B >> x;
        
        // calculate f to find same
        long long int index = 0;
        while(vis[x] == -1){
            vis[x] = index , dp[index++] = x;
            x = (A * x + B) % M + 2;
        }

        long long len = index - vis[x], pre = vis[x];

        if ((N-1) < pre){
            for (int i = 0 ; i < N ; i++)
               ans ^= (dp[i]-2); 
        }
        else {
            for (int i = 0 ; i < pre ; i++)
               ans ^= (dp[i]-2); 
            
            long long int num = (N - pre) % (2*len);
            if (num > len){
                for (int i = (num % len) ; i < len ; i++)
                    ans ^= (dp[pre + i]-2);
            }
            else{
                for (int i = 0 ; i < num ; i++)
                    ans ^= (dp[pre + i]-2);
            }
        } 

        if (ans == 0)
            cout << "Second" << endl;
        else
            cout << "First" << endl;
    }
}
