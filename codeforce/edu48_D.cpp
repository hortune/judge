#include <bits/stdc++.h>
using namespace std;
int row[101], column[101];
int ans[101][101];

int main(){
    int n, m, tmp;
    cin >> n >> m;
    for (int i = 0 ; i < n ; i++)
        cin >> row[i];
    for (int i = 0 ; i < m ; i++)
        cin >> column[i];
    
    for (int i = 0 ; i < n ; i++)
       for (int j = 0 ; j < m ; j++)
       {
           tmp = row[i] & column[j];
           ans[i][j] = tmp;
           row[i] &= (~tmp);
           column[j] &= (~tmp);
       }
    
    bool done = true;
    for (int i = 0 ; i < n ; i++){
        for (int j = i+1 ; j < n ; j++)
            if (row[i]&row[j]){
                tmp = row[i] & row[j];
                row[i] &= (~tmp);
                row[j] &= (~tmp);
                
                int iter = 1;
                while(tmp){
                    if (tmp & 1){
                        ans[i][0] ^= iter;
                        ans[j][0] ^= iter;
                    }
                    tmp >>= 1;
                    iter <<= 1;
                }
            }
        if (row[i])
            done = false;
    }

    for (int i = 0 ; i < m ; i++){
        for (int j = i+1 ; j < m ; j++)
            if (column[i]&column[j]){
                tmp = column[i] & column[j];
                column[i] &= (~tmp);
                column[j] &= (~tmp);
                
                int iter = 1;
                while(tmp){
                    if (tmp & 1){
                        ans[0][i] ^= iter;
                        ans[0][j] ^= iter;
                    }
                    tmp >>= 1;
                    iter <<= 1;
                }
            }
        if (column[i])
            done = false;
    }
    if (done){
        cout << "YES" << endl;
        for (int i = 0 ; i < n ; i++)
            for (int j = 0 ; j < m ; j++){
                cout << ans[i][j] << (j == (m-1) ? "\n": " ");
            }
    } else {
        cout << "NO" << endl;
    }
}
