#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int n;
    cin >> n;
    while(n--){
        int h, k, rest = 0, prev_stick, cur_stick, highest;
        bool impossible = false;
        cin >> h >> k >> prev_stick;
        
        h--;
        highest = k;

        while(h--){
            int cur_stick;
            cin >> cur_stick;

            int delta = abs(prev_stick - cur_stick);
            if(k >= delta){
                k -= delta;
            }
            else if (highest < delta){
                impossible = true;
                continue;
            }
            else{
                rest += 1;
                k = highest - delta;
            }
            prev_stick = cur_stick;

        }
        
        
        if (impossible){
            cout << "Impossible" << endl;
        }
        else{
            cout << rest << endl;
        }
    }
}
