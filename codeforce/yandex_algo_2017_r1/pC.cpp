#include <bits/stdc++.h>
using namespace std;

vector<int> childs[200001];
int vis[1000]={};
int label[200001]={};
int main(){
    int m, n;
    int e,v;
    cin >> n >> m;
    for (int i = 0 ; i < m ; i++){
        cin >> e >> v;
        childs[e].push_back(v);
        childs[v].push_back(e);
    }
    
    int k = 0;

    for (int i = 1 ; i <= n ; i++){
        for (int g = 0 ; g < childs[i].size() ; g++){
            vis[label[childs[i][g]]] = i;
        }
        int gr = 0;
        for (int it = 1 ; it <= k ; it++){
            if (vis[it] < i){
                gr = it;
                break;
            }
        }
        if (gr == 0)
            label[i] = ++k;
        else
            label[i] = gr;
    }
    cout << k << endl;
    for (int i = 1 ;i <= n ; i++)
        cout << ((i == 1) ? "": " ") << label[i];
}
