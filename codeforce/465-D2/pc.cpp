#include <bits/stdc++.h>
using namespace std;
int main(){
    long double R, x1, y1, x2, y2;
    cin >> R >> x1 >> y1 >> x2 >> y2;
    long double r3,x3,y3;
    long double len = sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
    r3 = (R + len)/2.;
    x3 = (x1 - x2)/len*r3 + x2;
    y3 = (y1 - y2)/len*r3 + y2;
    
    if((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1) >= R*R)
        cout << x1 << " " << y1 << " " << R;
    else if (len == 0)
        cout << x1 + R/2 << " " << y1 << " " << R/2;
    else
        cout << setprecision(16) << x3 << " " << y3 << " " << r3;
    
}
