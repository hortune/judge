#include <iostream>
#include <queue>
using namespace std;


int main(){
    int n ;
    while (cin >> n ){
        priority_queue <int, vector<int>, greater<int> > heap;
        
        int k;
        for (int i = 0 ; i < n ; i++){
            cin >> k;
            heap.push(k);
        }

        int ans = 0;
        for (int i = 0 ; i < n - 1 ; i++){
            int tmp = heap.top();
            heap.pop();
            tmp += heap.top();
            heap.pop();
            ans += tmp;
            heap.push(tmp);
        }
        cout << ans << endl;
    }
}
