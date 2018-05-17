#include <bits/stdc++.h>
using namespace std;

typedef float type;
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

//Taylor Not O(1) , 0 - 2*pi
type myacos(type x){
    return acos(max((type)-1, min((type)1,x)));
}

bool between(Pt a, Pt b, Pt c){
    return (a-b)*(a-c) < 0;

//嚴格 < 0 ， 不嚴格 <= 0
//a in b c 線段
}


// a 在 b c 向量的哪邊
int ori(Pt a, Pt b, Pt c){
    type ret = (c-b) ^ (a-b);
    return (ret > 0) - (ret < 0);
}

bool banana(Pt a, Pt b, Pt c, Pt d){
    if((b-a)^(d-c)==0){
        if (((b-a)^(d-a)) != 0)
            return false;
        if (between(a,c,d) or 
            between(b,c,d) or 
            between(c,a,b) or 
            between(d,a,b))
            return true;
        return false;
    }
    return (ori(a,c,d)*ori(b,c,d)<0) and 
           (ori(c,a,b)*ori(d,a,b)<0);
}

bool in_poly(Pt a, vector<Pt> p){
    for(size_t i = 0 ; i < p.size(); i++)
        if (between(a, p[i].))
}

int main(){
    point a(1,2);
    point b(2,3);
    point c = a + b;

    cout << a * b ;
}
