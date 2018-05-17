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
double eps = 1e-8;

char solve(point a, point b,long long r1, long long r2){
    long long d_2 = (a - b)*(a - b);
    
    if (d_2 < r1*r1 and ( (sqrt(d_2) + r2) < (r1 - eps)) ){
        return 'I';
    }
    else if (d_2 < r2*r2 and ((sqrt(d_2) + r1) < (r2 - eps)) ){
        return 'I';
    }
    else if (d_2 <= r2*r2 and ((sqrt(d_2) + r1 > (r2 - eps))) 
            and (sqrt(d_2) + r1 < (r2 + eps))){
        return 'E';
    }
    else if (d_2 <= r1*r1 and ((sqrt(d_2) + r2 > (r1 - eps))) 
            and (sqrt(d_2) + r2 < (r1 + eps))){
        return 'E';
    }
    return 'O';
}

int main(){
    int n;
    cin >> n;
    while(n--){
        long long int x1,y1,r1,x2,y2,r2;
        cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
        point a(x1,y1), b(x2,y2);
        cout << solve(a,b,r1,r2) <<endl;
    }
}
