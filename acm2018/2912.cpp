#include <bits/stdc++.h>
using namespace std;

double eps = 1e-8;
typedef double type;
typedef pair<type,type> point;
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

type myacos(type x){
    return acos(max((type)-1, min((type)1, x)));
}

type distance(point a, point b){
    return sqrt((a - b)*(a - b));
}

bool equal(const point a, const point b){
    if (a.first == b.first and a.second == b.second)
        return true;
    return false;
}

bool insideline(point q, point p, point last){
    if ( ((q - p)^(q-last)) < eps and 
         ((q - p)^(q-last)) > -eps){
        type dist = distance(q,p) + distance(q,last);
        if (dist > distance(last,p) - eps && 
                dist < distance(last,p) + eps)
            return true;
    }
    return false;
}

char solve(vector<point> poly, vector<point> query){
    for( int i = 0 ; i < query.size() ; i++){
        point q = query[i];
        type angle = 0;
        point last = poly[poly.size()-1];
        bool e_flag = false;
        for (int j = 0 ; j < poly.size() ; j++){
            point p = poly[j];
            e_flag |= equal(q,p);
            //e_flag |= insideline(q,p,last);
            
            angle += myacos(((last-q)*(p-q))/(sqrt((p - q)*(p - q))*sqrt((last - q)*(last -q))));
            last = p;
        }
        cout << ((fabs(angle) <= M_PI) and (!e_flag) ? "F" : "D") << endl;
    }
}

int main(){
    int n, q;
    cin >> n >> q;
    vector<point> poly, query;
    for(int i = 0 ; i < n ; i++){
        type x, y;
        cin >> x >> y;
        poly.push_back(point(x,y)); 
    }

    for(int i = 0 ; i < q ; i++){
        type x, y;
        cin >> x >> y;
        query.push_back(point(x,y)); 
    }
    solve(poly,query);
}
