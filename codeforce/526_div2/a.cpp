#include <bits/stdc++.h>
using namespace std;
int humans[101] = {};
int n;
int finals[101];
void calculate(int x){
    int ans = 0;
    for (int i = 1 ; i <= n ; i++){
        ans += ((x-1)*2 + abs(x-i)*2 + (i-1)*2)*humans[i];
    }
    finals[x] = ans;
}

int main(){
    int ans = 0;
    cin >> n;
    int counter = 0;
    for (int i = 1 ; i <= n ; i++){
        cin >> humans[i];
    }
    int fans = 2147483647;
    for (int i = 1 ; i <= n ; i++){
        calculate(i);
        if (finals[i] < fans)
            fans = finals[i];
    }

    cout << fans << endl;

}
