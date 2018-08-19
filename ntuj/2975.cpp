#include <bits/stdc++.h>
using namespace std;
bool ans[1000002];
int main(){
    string str;
    cin >> str;

    set<int> k;
    set<int>::iterator it;
    int len = (int)str.length() + 1;
    for(unsigned int i = 0; i < str.length() ; i++)
        if (str[i] == '0')
            k.insert(i+1);
    k.insert(0);
    k.insert(str.length()+1);
    
    for(unsigned int i = 0; i < str.length() ; i++)
        if (str[i] == '2'){
            str[i] = '1';
            it = k.lower_bound(i+1);
            int r = *it;
            it--;
            int l = *it, next_zero = l+r - (i+1);
            
            if(str[next_zero-1] == '2')
                str[next_zero-1] = '1';
            else
                k.insert(next_zero);

            if (l != 0 && l != len)
                k.erase(l);
            if (r != 0 && r != len)
                k.erase(r);
            
        }
    for(set<int>::iterator _it = k.begin() ; _it!=k.end(); ++_it){
        ans[*_it] = true;
    }

    for(unsigned int i = 1 ; i <= str.length(); i++)
        printf("%d",!ans[i]);
    puts("");
}
