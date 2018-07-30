#include <cstdio>
#include <iostream>
using namespace std;

int main(){
    int n ;
    while(cin >> n ){
        if (cin.eof()) break;
        int num[1001];
        for (int i = 0 ; i < n ; i++)
            cin >> num[i];
        
        int ans = 0;
        for (int i = 0 ; i < n ; i++)
            for (int j = n - 1 ; j > i ; j--)
                if (num[j] < num[j-1]){
                    ans++;
                    int tmp = num[j-1];
                    num[j-1] = num[j];
                    num[j] = tmp;
                }
        cout << "Minimum exchange operations : " << ans << endl;
    }
}
