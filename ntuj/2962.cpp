#include <bits/stdc++.h>
using namespace std;
int father[100001], favorite[100001];

struct node {
    vector<int> child;
    map<int, int> *nums;
    int favorite;
    int father;
    int max_count = 0;
    int max_index = -1;
} nodes[100001];

void dfs(int index){
    if (!nodes[index].child.size()){
        nodes[index].nums = new map<int, int>(); 
    }
    int max_count = 0;
    int max_index = -1;
    bool first = true;

    for (unsigned int i = 0 ; i < nodes[index].child.size() ; i++){
        int child_index = nodes[index].child[i];
        dfs(child_index);
        if (first){
            nodes[index].nums = nodes[child_index].nums;
            max_count = nodes[child_index].max_count;
            max_index = nodes[child_index].max_index;
            first = false;
        }
        else {
            map<int, int> *larger, *smaller;
            if (nodes[index].nums->size() >= nodes[child_index].nums->size()){
                larger = nodes[index].nums;
                smaller = nodes[child_index].nums;  
                max_count = nodes[index].max_count;
                max_index = nodes[index].max_index;
            } else {
                larger = nodes[child_index].nums;
                smaller = nodes[index].nums;
                max_count = nodes[child_index].max_count;
                max_index = nodes[child_index].max_index;
            }
            // iter
            for (map<int,int>::iterator it=smaller->begin(); 
                    it != smaller->end();
                    ++it){
                if (larger->find(it->first) != larger->end()){
                    (*larger)[it->first] += it->second;
                } else{
                    (*larger)[it->first] = it->second;
                }      
                
                if ((*larger)[it->first] > max_count ||
                        ((*larger)[it->first] == max_count && it->first < max_index)){
                    max_index = it->first;
                    max_count = (*larger)[it->first];
                }
            }
            smaller->clear();
            delete(smaller);
            nodes[index].nums = larger;
            nodes[index].max_count = max_count;
            nodes[index].max_index = max_index;
        }
    }
    if ( nodes[index].nums->find(nodes[index].favorite) != nodes[index].nums->end()){
        (*nodes[index].nums)[nodes[index].favorite]++;
    } else {
        (*nodes[index].nums)[nodes[index].favorite] = 1;
    }

    if ((*nodes[index].nums)[nodes[index].favorite] > nodes[index].max_count ||
            ((*nodes[index].nums)[nodes[index].favorite] == nodes[index].max_count &&
             nodes[index].favorite < max_index)){
        nodes[index].max_count = (*nodes[index].nums)[nodes[index].favorite];
        nodes[index].max_index = nodes[index].favorite;
    }
    
};

int main(){
    int T;
    cin >> T;
    while (T--){
        int N;
        bool first = true;
        cin >> N;

        // initialize
        for (int i=0;i<N;i++)
            nodes[i].child.clear(), nodes[i].max_count = 0, nodes[i].max_index = -1;
        
        for (int i=0; i<N; i++){
            cin >> nodes[i].father;
            nodes[i].father--;
            if (nodes[i].father != -1)
                nodes[nodes[i].father].child.push_back(i);
        }

        for (int i=0; i<N; i++)
            cin >> nodes[i].favorite;
        
        for (int i=0; i<N; i++)
            if(nodes[i].father == -1){
                dfs(i);
                delete(nodes[i].nums);
            }
        
        for (int i=0; i<N; i++)
            if (first)
                cout << nodes[i].max_index, first = false;
            else
                cout << " " << nodes[i].max_index;
        cout << endl;
    }
}
