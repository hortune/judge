#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>

#define _USE_MATH_DEFINES

#include <cmath>

using namespace std;

long n;
int main() {
    cin >> n;
    // 0: right, 1: top, 2: left, 3: down

    long lk, tk;
    int dir = 0;
    int dirs[10005];
    int ans[10005];
    dirs[0] = 0;
    for (long i = 0; i < n; ++i) {
        cin >> lk >> tk;

        dirs[i+1] = (dirs[i] - tk) % 4;
    }
    
    long horLen = n;
    long verLen = n;
    long horAcc = 0;
    long verAcc = 0;



    for (long i = 0; i < n; ++i) {
        int j;
        for (j = i+1; j < n; ++j) {
            if ((dirs[i] % 2) == (dirs[j] % 2))
                break;
        }
        if (j == n || dirs[i] != dirs[j]) {
            if (dirs[i] % 2 == 0) {
                ans[i] = verLen - verAcc;
                verLen = n - i - 1;
                verAcc = 0;
            } else {
                ans[i] = horLen - horAcc;
                horLen = n - i - 1;
                horAcc = 0;
            }
        } else {
            if (dirs[i] % 2 == 0) {
                ans[i] = 1;
                verAcc++;
            } else {
                ans[i] = 1;
                horAcc++;
            }
        }
    }
    for (long i = 0; i < n; ++i)
        cout << ans[i] << endl;
}
