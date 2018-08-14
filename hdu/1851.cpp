/*
 遊戲是個簡單的nim包裝
 如果是後手勝，不論如何後手都可以以mod去包他...
 如果是先手勝，那麼當先手動完小nim上以後，就可以用mod包對方。
 */

#include <iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    while(n--){
        int m, k, l, ans = 0;
        cin >> m;
        while(m--){
            cin >> k >> l;
            ans ^= (k %(l+1));
        }

        if (ans)
            cout << "No" << endl;
        else
            cout << "Yes" << endl;
    }

}
