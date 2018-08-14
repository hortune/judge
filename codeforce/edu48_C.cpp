#include <bits/stdc++.h>
using namespace std;
long long int dp[300001][4];
long long int nums[300001][2];

int main(){
   int n;
   cin >> n;
   for (int i = 0 ; i < n ; i++){
       cin >> nums[i][0];
   }
   for (int j = 0 ; j < n ; j++){
       cin >> nums[j][1];
   }

   // dp [0] up in down leave
   // dp [1] down in up leave
   // dp [2] up in
   // dp [3] down in
   

   // initialize
   dp[n-1][0] = dp[n-1][2] = nums[n-1][1];
   dp[n-1][1] = dp[n-1][3] = nums[n-1][0];

   long long prefix_sum = nums[n-1][1] + nums[n-1][0];
   for (int i=n-2 ; i >= 0 ; i--){
       dp[i][0] = dp[i+1][0]+prefix_sum+nums[i][1]*(2*(n-i)-1);
       dp[i][1] = dp[i+1][1]+prefix_sum+nums[i][0]*(2*(n-i)-1);
       dp[i][2] = dp[i+1][3]+2*prefix_sum + nums[i][1];
       dp[i][3] = dp[i+1][2]+2*prefix_sum + nums[i][0];
       dp[i][2] = max(dp[i][2],dp[i][0]);
       dp[i][3] = max(dp[i][3],dp[i][1]);
       prefix_sum += nums[i][0] + nums[i][1];
   }
   cout << dp[0][2] << endl;
}

