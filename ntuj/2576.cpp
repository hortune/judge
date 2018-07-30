#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    while(n--){
        int m, ans = 0;
        int amiba[514][2];
        cin >> m;
        for (int i = 0 ; i < m ; i++)
            cin >> amiba[i][0] >> amiba[i][1];

        for (int i = 1 ; i < m ; i++)
            amiba[i][0] += amiba[i-1][0];
        
        for (int i = 0 ; i < m ; i++)
            if (amiba[i][0] & 1)
                ans ^= amiba[i][1];
        
        cout << ((ans) ? "A-Mi-Ba": "B-Mi-Ba" ) << endl;
        
    }
}
