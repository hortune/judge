#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    while(cin>>n, !cin.eof()){
        int nums[100];
        for(int i = 0 ; i < n ; i++)
            cin >> nums[i];
        
        int start = 0, end = n - 1;

        for(int i = 0 ; i < n ; i++){
            if(i % 2 == 0){
                for(int q = start; q <= end; q++)
                    cout << nums[q] << " ";
                start++;
            }
            else{
                for(int q = end; q >= start; q--)
                    cout << nums[q] << " ";
                end--;
            }
            cout << endl;
        }
        cout << endl;
    }
}
