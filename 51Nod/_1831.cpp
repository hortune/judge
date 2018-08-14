/*#include <iostream>
using namespace std;
int main(){
    int T, num;
    cin >> T;
    while(T--){
        cin >> num;
        if (num & 1){
            cout << "NIE" << endl;
        }
        else{
            cout << "TAK" << endl;
        }
    }
}
*/

#include <iostream>
using namespace std;
int sg[1000] = {};
int main(){
    sg[0] = 1;
    for (int i = 1; i < 100; i++){
        bool vis[1000] ={};
        vis[sg[i-1]] = true;
        for(int j = 2; j < i ; j++){
            if(i % j == 0){
                vis[sg[i/j]] = true;
            }
        }

        for (int j = 0; j <= 1000 ; j++)
            if(!vis[j]){
                sg[i] = j;
                break;
            }
    }

    for (int i = 0 ; i < 50 ; i++)
        cout << sg[i] << " ";
}
