#include<bits/stdc++.h>
using namespace std;
struct node {
 int x,y;
};
node t;
node solve(int n,int m){
    if(n == 2){
        if(m==0){
            t.x = 1;t.y = 1;return t;
        }
        if(m == 1){
            t.x = 1;t.y = 2;return t;
        }
        if(m == 2){
            t.x = 2;t.y = 2;return t;
        }
        else{
            t.x = 2;t.y = 1;return t;
        }
    }
    int k = n/2;
    int x = m/(k*k);  //判斷在上一幅圖的哪一個區域
    if(x == 0){
        t = solve(k,m%(k*k));
        swap(t.x,t.y);
        return t;
    }
    if(x == 1){
        t = solve(k,m%(k*k));
        t.y += k;
        return t;
    }
    if(x == 2){
        t = solve(k,m%(k*k));
        t.x += k;t.y += k;
        return t;
    }
    if(x == 3){
        t = solve(k,m%(k*k));
        node t1 = t;
        t1.x = 2*k - t.y + 1;
        t1.y = k - t.x + 1;
        return t1;
    }
}

int main()
{
    int n,m;
    cin>>n>>m;
    m--;
    node p = solve(n,m);
    cout<<p.x<<" "<<p.y<<endl;
}
