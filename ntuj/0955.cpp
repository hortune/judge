#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
using namespace std;
int nums[1002][1002], sums[1002][1002]={};
int R,C,H,W;

// if exists smaller equal
bool check(int m){
    for(int i = 1 ; i <= R ; i++){
        for(int j = 1 ; j <= C ; j++){
            sums[i][j] = (nums[i][j] > m) - sums[i-1][j-1] + sums[i-1][j] + sums[i][j-1];
        }
    }
    int half = H*W / 2;
    for(int i = 0 ; i <= (R-H) ; i++)
        for(int j = 0 ; j <= (C-W) ; j++)
            if((sums[i+H][j+W] + sums[i][j] - sums[i][j+W] - sums[i+H][j]) <= half){
                return true;
            }
    return false;
}
int main(){
    int n;
    cin >> n;
    for(int index = 1; index <= n ; index++){
        cin >> R >> C >> H >> W;
        for(int i = 1; i <= R ; i++)
            for (int j = 1; j <= C ; j++)
                cin>> nums[i][j];
        
        
        int up = R*C + 1, low = 1;
        int ans;
        while(up >= low){
            int mid = (up + low) / 2;
            if (!check(mid)){
                low = mid + 1;
            }
            else{
                ans = mid;
                up = mid - 1;
            }
        }
        cout << "Case #" << index << ": " << ans << endl;
    }
}
