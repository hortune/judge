#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,d;
    cin>>n>>d;
    int array[101]={};
    for(int i = 0 ; i<n ; i++){
        cin>>array[i];
    }
    sort(array,array+n);
    int amount = 9487;
    for(int i = 0 ; i < n ; i ++){
        for (int j = i ; j < n ; j ++){
            if (array[j]- array[i] > d){
                amount = min(n - j  + i, amount);
                break;
            }
            if (j == n - 1)
                amount = min(i, amount);
        }
    }
    cout<<amount<<endl;
}
