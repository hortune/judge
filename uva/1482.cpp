#include <iostream>
using namespace std;
long long sg(long long num){
    if (num&1)
        return sg(num/2);
    return num/2;
}
int main(){
    int T;
    cin >> T;
    while (T--){
        int n;
        long long ans = 0, num;
        cin >> n;
        while (n--){
            cin >> num;
            ans^= sg(num);
        }
        if (ans)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}


/*
#include <bits/stdc++.h>
using namespace std;
int gd[1000] = {};
// true if first win
int main(){
   for(int i = 2; i < 100; i++){
        bool vis[1000] = {};
        for(int j = i / 2 ; j > 0 ; j--)
            vis[gd[i-j]] = true;
        for(int qq = 0 ; qq < 1000 ; qq++)
            if (!vis[qq]){
                gd[i] = qq;
                break;
            }
   } 

   for (int i = 1; i < 50 ; i++)
       cout << gd[i] << " ";
}*/
