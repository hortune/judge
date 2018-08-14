#include <bits/stdc++.h>
using namespace std;

int len[100001] = {};
string ans (1200100,'0');
string mapping = "0123456789";
int main(){
    int T;
   
    bool has_prev = false; 
    int num = 1, prev = 0, length = 0;
    int wei_num = 1, w_num = 10;
    while(length <= 1200000){
        if (num >= w_num){
            w_num *= 10, wei_num++ ;
        } 
        for (int i = w_num / 10 ; i ; i /= 10){
            int digit = (num / i) % 10;
            if(has_prev){
                while(prev--)
                    ans[length++] = mapping[digit];
            } else {
                prev = digit;            
            }
            has_prev = 1 - has_prev; 
        }

        if (!has_prev)
            len[num] = length;
        num++;
    }

    cin >> T;
    while (T--){
        int n,m;
        cin >> n >> m;
        if (len[n] && (len[n] < m))
            cout << -1 << endl;
        else
            cout << ans[m-1] << endl;
    }
}
