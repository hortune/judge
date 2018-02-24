#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, num[100010];
    string b;
    cin >> n;
    for (int i = 0 ; i < n ; i++)
        cin>>num[i];
    cin >> b;
    int rmax = 1e9;
    int lmin = -1e9;
    for(int i = 4 ; i < n ; i++){
        int curr_min = 2147483647, curr_max = -2147483647;
        for(int j = 0; j < 5 ; j++){
            curr_min = min(num[i - j],curr_min);
            curr_max = max(num[i - j],curr_max);
        }
        if(b[i] != b[i-1]){
            if(b[i] == '0') {
                rmax = min(rmax, curr_min - 1); 
            }
            else{
                lmin = max(lmin, curr_max + 1);
            }
        }
        else if(b[i-1] == b[i-2] && b[i-2] == b[i-3] && b[i-3] == b[i-4]){
            if(b[i] == '0'){
                lmin = min(curr_max - 1,lmin);
            }
            else{
                rmax = max(curr_min + 1,rmax);
            }
        }
    }
    cout << lmin << " " << rmax;
    
    
}
