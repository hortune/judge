#include <bits/stdc++.h>
using namespace std;
int trans[] = {10,11,12,13,14,15,16,17,34,18,19,20,21,22,35,23,24,25,26,27,28,29,32,30,31,33};
int main(){
    string str;
    while(cin>>str,!cin.eof()){
        int ans=0;
        int tmp_f = trans[str[0] - 'A'];
        ans += tmp_f / 10 + (tmp_f % 10)*9;
        for (int i = 1 ; i < str.size() ; i++){
            ans += (str[i] - '0') * (9-i);
        }
        ans += str[str.size() - 1] - '0';
        cout << ((ans % 10 == 0) ?  "real" : "fake") << endl;
    }
}
