#include <bits/stdc++.h>
using namespace std;
int current_pos(int x, int y){
    if(x - y > 0)
        return 1;
    else if (x - y < 0)
        return 2;
    return 0;
}
int main(){
    int n,x=0,y=0;
    cin>>n;
    int last = 0, count = 0, cur_pos;
    while(n--){
        char c;
        cin>>c;
        if(c == 'U'){
            y += 1;
        }
        else{
            x += 1;
        }
        cur_pos = current_pos(x,y);
        if(cur_pos + last == 3)
            count ++;
        last = (cur_pos == 0) ? last : cur_pos;
    }
    cout<<count ;
}
