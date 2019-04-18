#include <bits/stdc++.h>
using namespace std;
typedef long double ll;
int n;
ll x[10010], y[10010], z[10010];
ll sx, sy, sz;
ll vs, vp;
double eps = 1e-9;

double dists[10010], sdistance[10010];
double dist(ll x2, ll y2, ll z2, ll x1, ll y1, ll z1){
    double dx = double(x2)- double(x1);
    double dy = double(y2)- double(y1);
    double dz = double(z2)- double(z1);

    return sqrt(dx*dx + dy*dy + dz*dz);
}

bool equal(double a, double b){
    return (a + eps > b) && (a - eps < b);
}

int main(){
    cin >> n;
    for (int i = 0; i <= n ; i++)
        cin >> x[i] >> y[i] >> z[i];

    for (int i =  1; i <= n ; i++){
        dists[i] = dist(x[i],y[i],z[i],x[i-1],y[i-1],z[i-1]);
    }
    cin >> vp >> vs;
    cin >> sx >> sy >> sz;
    
    double t = 0;
    for (int i = 0 ; i < n ; i++){
        double l = 0, h = 1e9, mid;
        double ct = dist(x[i+1], y[i+1], z[i+1], x[i],y[i],z[i]) / vs;
        double nx, ny, nz;
        for (int j = 0 ; j <= 1000 ; j++){
            mid = (l + h) / 2;

            nx = (mid / ct)*(x[i+1]-x[i]) + x[i];
            ny = (mid / ct)*(y[i+1]-y[i]) + y[i];
            nz = (mid / ct)*(z[i+1]-z[i]) + z[i];
            if (dist(nx,ny,nz,sx,sy,sz) <= vp * (mid+t))
                h = mid;
            else
                l = mid;
        }
        if ( mid < ct + eps){
            cout << "YES" << endl;
            cout << fixed << setprecision(9) << mid + t << endl;
            cout << fixed << setprecision(9) << nx << " " << ny << " " << nz << endl;
            return 0;
        }
        t += ct;
    }
    cout << "NO" << endl;
}
