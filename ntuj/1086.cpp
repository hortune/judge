#include <bits/stdc++.h>
using namespace std;
int father[20002], value[20002], nums[16], n;
void init(){
    for(int i = 0; i <= n; i++)
        father[i] = i, value[i] = 0;
}

int find(int a){
    if (father[a] == a)
        return a;
    int tmp = father[a];
    father[a] = find(father[a]);
    value[a] = value[tmp] ^ value[a];
    return father[a];
}


int insert(int a, int b, int v){
    int x = find(a), y = find(b);
    if (x == y){
        // find 後保證單層
        if ((value[a]^value[b]) != v)
            return -1;
    } else {
        
        if (y == n){
            swap(a,b);
            swap(x,y);
        }
        father[y] = x;
        value[y] = v ^ value[a] ^ value[b];
    }
    return 1;
}

int main(){
    int q, t;
    int lines = 1;
    while(cin >> n >> q, n + q){
        if (lines != 1){
            cout << endl;
        }

        cout << "Case "<< lines++ <<":"<< endl;
        init();
        char str[1000];
        int suc = 0;
        while(q--){
            cin >> str;
            
            if (suc == -1){
                gets(str);
                continue;
            }
            if (str[0] == 'I'){
                gets(str); 
                int blank = 0, a, b, v;
                for(int i = 0; i< strlen(str); i++)
                    blank += (str[i]==' ');
                
                if (blank == 2){
                    sscanf(str,"%d %d",&b,&v);
                    a = n; 
                } else {
                    sscanf(str,"%d %d %d",&a,&b,&v); 
                }
                suc += 1;
                if (insert(a,b,v) == -1){
                    cout << "The first "<< suc << " facts are conflicting." << endl;
                    suc = -1;
                }
            }
            else{
                int ans = 0;
                cin >> t;
                for (int i = 0; i < t ; i++){
                    cin >> nums[i];
                }
                bool vis[20] = {};
                bool gg = false;
                for (int i = 0; i < t ; i++){
                    if (vis[i])
                        continue;
                    int fa = find(nums[i]);
                    if (fa == n){
                        ans ^= value[nums[i]];
                        vis[i] = 1;
                        continue;
                    }

                    for (int j = i+1 ; j < t ; j++){
                        if (vis[j])
                            continue;
                        
                        int fa1 = find(nums[j]);
                        
                        if (fa == fa1){
                            ans ^= value[nums[i]] ^ value[nums[j]];
                            vis[j] = vis[i] = 1;
                            break;
                        }
                    }
                    
                    if (!vis[i]){
                        gg =true;
                        break;
                    }
                }

                if (gg)
                    cout << "I don't know." << endl;
                else
                    cout << ans << endl;
            }
        }
    }
}
