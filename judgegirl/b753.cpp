#include <bits/stdc++.h>
using namespace std;

bool check_valid(string str){
    int trans[] = {10,11,12,13,14,15,16,17,34,18,19,20,21,22,35,23,24,25,26,27,28,29,32,30,31,33};
    int ans=0;
    int tmp_f = trans[str[0] - 'A'];
    ans += tmp_f / 10 + (tmp_f % 10)*9;
    for (int i = 1 ; i < str.size() ; i++){
        ans += (str[i] - '0') * (9-i);
    }
    ans += str[str.size() - 1] - '0';
    return (str[1] == '1' || str[1] == '2') ? ((ans % 10 == 0) ? true : false) : false;
}
int main(){
    int n;
    while(cin>>n, !cin.eof()){
        set<string> QQ;
        int T=0,O=0,F=0;
        for (int i = 0 ; i < n ; i++){
            string str;
            cin >> str;
            if (QQ.find(str) != QQ.end()){
                O += 1;
            }
            else{
                if(check_valid(str)){
                    T += 1;
                    QQ.insert(str);
                }
                else{
                    F += 1;
                }
            }
        }
        cout << T <<","<< O << "," << F << endl;
    }
}
