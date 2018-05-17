#include <bits/stdc++.h>
using namespace std;

typedef long long type;
typedef pair<type,type> point, Pt;
typedef pair<point,point> line;

point operator+(const point& a, const point& b){
    return {a.first + b.first, a.second + b.second};
}

point operator-(const point& a, const point& b){
    return {a.first - b.first, a.second - b.second};
}

type operator*(const point& a, const point& b){
    return a.first * b.first + a.second * b.second;
}

type operator^(const point& a, const point& b){
    return a.first * b.second - a.second * b.first;
}

point next(point a, char r){
    if (r == '8')
        return {a.first, a.second + 1};
    else if (r == '2')
        return {a.first, a.second - 1};
    else if (r == '6')
        return {a.first+1, a.second};
    else if (r == '4')
        return {a.first-1, a.second};
    else if (r == '1')
        return {a.first+1, a.second-1};
    else if (r == '3')
        return {a.first-1, a.second-1};
    else if (r == '7')
        return {a.first-1, a.second+1};
    else if (r == '9')
        return {a.first+1, a.second+1};
    else
        return a;
}

long long int solve(string path){
    if (path.size() < 3)
        return 0;

    point a(0,0), b(0,0);
    long long ans = 0;
    for(int i = 0; i < path.size() ; i++){
        if (path[i] == '5')
            break;
        
        a = next(b,path[i]);
        ans += a ^ b;
        
        point tmp = b;
        b = a;
        a = tmp;
    }
    return ans;
}

int main(){
    int n;
    cin>>n;
    while(n--){
        string path;
        cin >> path;
        long long ans = abs(solve(path));
        cout << ans / 2 <<"."<< (ans % 2 == 0?0:5) << endl;
    }
}
