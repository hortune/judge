#include <stack>
#include <vector>
#include <iostream>
#include <algorithm>
#include <utility>
using namespace std;


#define ll long long
ll cows[100010], N, M;
const ll MAX_M = 65536*2;
struct query{
    ll ans,index,l,r;
}queries[100010];

bool cmpR(query & a, query & b){
    if (a.r < b.r)
        return true;
    else if (a.r == b.r && a.l < b.l)
        return true;
    return false;
}

bool cmpI(query & a, query & b){
    if (a.index < b.index)
        return true;
    return false;
}

// use bit to mallain prefix sum
ll bit1[MAX_M+1]={}, bit2[MAX_M+1]={}, bit3[MAX_M+1]={};
ll sum(ll x, ll c[]){
    ll ans = 0;
    for (ll i = x; i > 0; i -= (i & (-i)))
        ans += c[i];
    return ans;
}

void modify(ll x, ll d, ll c[]){
    for (ll i = x; i <= M ; i += (i & (-i)))
        c[i] += d;
}

void solve(){
    // check the right sum
    sort(queries, queries+N, cmpR);
    stack<ll> rstack;

    ll currentR = 1;
    for (ll i = 0 ; i < N ; i++){
        while(currentR < queries[i].r){
            while(rstack.size() && cows[rstack.top()] < cows[currentR]) {
                    modify(rstack.top(),-1,bit3);
                    modify(rstack.top(),-rstack.top(),bit2);

                    modify(rstack.top(),currentR-rstack.top(), bit1);
                    rstack.pop();
            }
            rstack.push(currentR);
            modify(currentR,currentR,bit2);
            modify(currentR,1,bit3);
            currentR++;
        }
        ll index_sum = sum(queries[i].r,bit2) - sum(queries[i].l-1,bit2);
        ll alive = (sum(queries[i].r,bit3) - sum(queries[i].l-1,bit3));

        // add the stuff instack
        queries[i].ans += alive*queries[i].r - index_sum;
        // add the stuff out stack
        queries[i].ans += sum(queries[i].r, bit1) - sum(queries[i].l-1,bit1);
    }
}

int main(){
    ll T;
    cin >> T;
    while(T--){
        for(ll i = 0 ; i<100010 ; i++)
            bit1[i] = bit2[i] = bit3[i] =0;
        cin >> M >> N;

        for (ll i = 1 ; i <= M ; i++)
            cin >> cows[i];

        for (ll i = 0 ; i < N ; i++){
            cin >> queries[i].l >> queries[i].r;
            queries[i].index = i, queries[i].ans = 0;
        }

        solve();

        // swap queries?
        for (ll i = 0 ; i < N ; i++){
            ll tmp = queries[i].r;
            queries[i].r = M + 1 - queries[i].l;
            queries[i].l = M + 1 - tmp;
        }

        for (ll i = 1 ; i <= M/2 ; i++){
            ll tmp = cows[i];
            cows[i] = cows[M+1-i];
            cows[M+1-i] = tmp;
        }

        for(ll i = 0 ; i<100010 ; i++)
            bit1[i] = bit2[i] = bit3[i] =0;

        solve();
        sort(queries, queries+N, cmpI);
        for (ll i=0 ; i < N ; i++)
            cout << queries[i].ans + queries[i].r - queries[i].l +1  << endl;
    }
}
