#include <bits/stdc++.h>
using namespace std;
int trans[] = {10,11,12,13,14,15,16,17,34,18,19,20,21,22,35,23,24,25,26,27,28,29,32,30,31,33};
int main(){
    string str;
    while(cin>>str,!cin.eof()){
        int ans=0;
        string ans_str;
        /*
         先算好後面的和
         */
        
        for (int i = 0 ; i < str.size() ; i++){
            ans += (str[i] - '0') * (8-i);
        }
        ans += str[str.size() - 1] - '0';
        

        /*
         暴力搜尋 A - Z
         */
        for(int i = 0; i < 26 ; i++)
            if ((ans + trans[i]/10 + trans[i]%10*9) % 10 == 0)
                ans_str += i+'A';
        
        cout << ans_str << endl;
    }
}
