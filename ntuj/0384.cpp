// Idea 存線，做二分搜... 嘻嘻 
// x + by + c 模式
// 如果上述 小於 0 點在線左邊
// 如果上述 大於 0 點在線右邊
// 做單次二分搜就可惹
// 5000 * log 5000 
// It will pass
#include <cstdio>
#include <iostream>
using namespace std;

bool rightofline(long long x, long long y,long long x1,long long y1, long long x2, long long y2){
    return ((x-x2)*(y1-y2)) > ((y-y2)*(x1-x2));
}

int main(){
    long long n, m, x1, y1, x2, y2;
    long long partitions[5003][2];
    bool first = true;
    while (cin >> n, n){
        int ans[5002] = {};
        cin >> m >> x1 >> y1 >> x2 >> y2;
        for (int i = 1 ; i <= n ; i++){
            cin >> partitions[i][0] >> partitions[i][1];
        }
        
        partitions[0][0] = x1;
        partitions[0][1] = x2;
        
        while (m--){
            long long x, y;
            cin >> x >> y;
            
            int left = 0, right = n+1;
            while(left + 1 < right){
                int mid = (left + right) / 2;
                if (rightofline(x,y,partitions[mid][0],y1,partitions[mid][1],y2)){
                    left = mid;
                }
                else{
                    right = mid;
                }
            }
            ans[left]++;
        }
        if (!first){
            cout << endl;
        }
        else{
            first = false;
        }
        
        for (int i = 0; i <= n ; i++)
            cout << i << ": " << ans[i] <<endl;
    }
    
}
