#include <bits/stdc++.h>
using namespace std;
pair<long long int, long long int> qaq (long long int path,long long int size){
    if (size == 1){
        if (path == 0)
            return make_pair(0,0);
        else if (path == 1)
            return make_pair(0,1);
        else if (path == 2)
            return make_pair(1,1);
        else if (path == 3)
            return make_pair(1,0);
    }
    
    long long int total = 1<<(2*(size-1)); 
    long long int half = 1<<(size-1);
    pair<long long int, long long int> tmp;
    if (path < total){
        tmp = qaq(path,size-1);
        return make_pair(tmp.second, tmp.first);
    }
    else if (path < 2*total){
        path -= total;
        tmp = qaq(path,size-1);
        return make_pair(tmp.first,half+tmp.second);
    }
    else if (path < 3*total){
        path -= 2*total;
        tmp = qaq(path,size-1);
        return make_pair(half + tmp.first,half+tmp.second);
    }
    else {
        path -= 3*total;
        tmp = qaq(path,size-1);
        return make_pair(half*2 - 1 - tmp.second, half - tmp.first - 1);
    }
}


int main(){
    long long m, n;
    cin >> n >> m;
    int k = 1;
    while ((1<<k) != n){
       k++;  
    }
    
    pair<long long int, long long int> tmp;
    tmp = qaq(m-1,k);
    cout << tmp.first+1 << " " << tmp.second+1 << endl;
}
