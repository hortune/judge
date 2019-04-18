#include <bits/stdc++.h>
using namespace std;

int ind = 0;
int ans[120];
int main(){
    int n, a, b;
    cin >> n >> a >> b;
    queue<int> myQ;
    for (int i = 0; i < n ; i++){
        int tmp;
        cin >> tmp;
        while (myQ.size() > 0 && myQ.front() + b < tmp){
            int cur_size = myQ.size();
            int tfront = myQ.front();
            for (int j = 0 ; j < (cur_size + 1)/2 ;j++){ 
                myQ.pop();
                ans[ind++] = tfront + b;
            }
        }
        myQ.push(tmp);
        if (myQ.front() + b == tmp){
            int cur_size = myQ.size();
            int tfront = myQ.front();
            for (int j = 0 ; j < (cur_size + 1)/2 ;j++){ 
                myQ.pop();
                ans[ind++] = tfront + b;
            }
        }
        if (myQ.size() >= a){
            int cur_size = myQ.size();
            for (int j = 0 ; j < (cur_size + 1)/2 ;j++){ 
                myQ.pop();
                ans[ind++] = tmp;
            }
        }
    }

    while(!myQ.empty()){
        int gg = myQ.front();
        int cur_size = myQ.size();
        for (int i = 0 ; i < (cur_size+1)/2 ; i++){
            myQ.pop();
            ans[ind++] = gg + b;
        }
    }

    for (int i = 0; i < n ; i++)
        cout << ((i==0)?"":" ") << ans[i];
    cout << endl;
}
