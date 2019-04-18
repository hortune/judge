#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> childs[100010], fathers[100010];
int label[100010];
int k = 2147483;

int init(){
    for (int i = 0 ; i <= n ; i++)
        label[i] = -2147483;
}


bool dfs(int node, int color){
    if(label[node] != -2147483 && label[node] != color){
        if (k != 2147483){
            k = __gcd(k,abs(color - label[node]));
        } else{
            k = abs(color - label[node]);
        }
        return false;
    }

    if (label[node] != -2147483)
        return true;

    label[node] = color;

    for (int i = 0 ; i < childs[node].size() ; i++){
        dfs(childs[node][i], color+1);
    }
    
    for (int i = 0 ; i < fathers[node].size() ; i++){
        dfs(fathers[node][i], color-1);
    }
    return true;
}


bool vdfs(int node, int color){
    if(label[node] != -2147483 && label[node] != color){
        return false;
    }

    if (label[node] != -2147483)
        return true;

    label[node] = color;

    for (int i = 0 ; i < childs[node].size() ; i++){
        if (!vdfs(childs[node][i], (color+1) % k))
            return false;
    }
    
    for (int i = 0 ; i < fathers[node].size() ; i++){
        if (!vdfs(fathers[node][i], (color-1+k) % k))
            return false;
    }
    return true;
}

bool tdfs(int j ){
    init();
    k = j;
    for (int i = 1; i <= n ; i++){
        if (label[i] == -2147483){
            if(!vdfs(i,0)){
                return false;
            }
        }
    }
    return true;
}

int main(){
    scanf("%d %d",&n, &m);
    int a, b;
    init();
    for (int i = 0 ; i < m ; i++){
        scanf("%d %d",&a, &b);
        childs[a].push_back(b);
        fathers[b].push_back(a);
    }
    
    for (int i = 1; i <= n ; i++){
        if (label[i] == -2147483){
            dfs(i,0);
        }
    }
    if (k == 2147483)
        cout << n << endl;
    else{
        int bak = k;
        for (int i = bak ; i>=1 ; i--){
            if (bak % i == 0){
                if(tdfs(i)){
                    cout << i << endl;
                    return 0;
                }
            }
        }
    }
}
