#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

int solve(long long nums[], int n){
    int index = 0;
    int min_index = -1;
    long long min = 2147483647, n_nums;
    for(; index + 2 < n ; index++){
        n_nums = nums[index]*nums[index+1]*nums[index+2];
        if(n_nums < min){
            min_index = index;
            min = n_nums;
        }
    }
    
    for(index = min_index+1; index + 1 < n; index++)
        nums[index] = nums[index+1];
    cout << min << endl;
    return min;
}

int main(){
    int n;
    while(cin >> n){
        if(cin.eof())
            break;
        long long int nums[55]={};
        
        for (int i = 0 ; i < n ; i++)
            cin>>nums[i];

        long long ans = 0;
        
        for(int i = 2 ; i < n ; i++){
            ans += solve(nums, n - i + 2);
        }
        cout << ans <<endl;
    }
}
