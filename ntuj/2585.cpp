#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, num;
    cin >> n;
    while(n--){
        cin >> num;
        if(num == 1)
            cout << 1 << endl;
        else {
            for (int i = 0; i < num - 2 ; i++)
                cout << "1 ";
            cout << num << " 2" << endl;
        }
    }
    
}
