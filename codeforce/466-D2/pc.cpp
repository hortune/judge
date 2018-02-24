#include <bits/stdc++.h>
using namespace std;
int main(){
    int m, n;
    string str;
    bool alpha[26] = {};
    char nalpha[256] = {};
    cin >> m >> n;
    cin >> str;
    for(int i = 0 ; i < m ; i++)
        alpha[str[i] - 'a'] = 1;
        
    char next = ' ';
    for(int i = 25 ; i >= 0 ; i-- )
        if(alpha[i]){
            nalpha[i + 'a'] = next;
            next = i + 'a';
        }
    
    
    if(n <= m){
        for(int i = n - 1 ; i >= 0 ; i--){
            if(nalpha[str[i]] != ' '){
                str[i] = nalpha[str[i]];
                for(int j = i + 1 ; j  < n ; j++)
                    str[j] = next;
                break;
            }
        }
        for(int i = 0 ; i < n ; i++)
            cout << str[i];
        cout << endl;
    }
    else{
        cout << str;
        for(int i = m ; i < n ; i++)
            cout << next;
        cout << endl;
    }
}
