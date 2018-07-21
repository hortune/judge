#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
struct attr_child{
    int child;
    int cost;
};


map<string, int>  strmap;
int city_index = 0;
int get_id(string name){
    if(strmap.count(name) == 0){
        strmap[name] = city_index++;
    }
    return strmap[name];
}

vector<int> bfs (vector<vector<attr_child> >& g, int start){
    vector<int> d(g.size(), INF);
    d[start] = 0;
    priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > > pq;
    pq.push(make_pair(0,start));
    
    while(!pq.empty()){
        pair<int,int> item = pq.top();
        pq.pop();
        
        // if larger than origin distance ...
        if (d[item.second] == item.first){
            for (auto& edge : g[item.second]){
                if(d[edge.child] > d[item.second] + edge.cost){
                    d[edge.child] = d[item.second] + edge.cost;
                    pq.push(make_pair(d[edge.child], edge.child));
                }
            }
        }
    }

    return d;
}


int main(){
    int N, M, cap;
    while(cin >> N >> M >> cap, N+M+cap){
        cap *= 10;
        strmap.clear();
        city_index = 0;

        string start, end;
        cin >> start >> end;
        get_id(start), get_id(end);
        vector<vector<attr_child> > g1(6001);
        
        for (int i = 0; i < N ; i++){
            string city1, city2;
            int cost;
            cin >> city1 >> city2 >> cost;
            int x = get_id(city1), y = get_id(city2);
            g1[x].push_back( (attr_child) {.child = y, .cost = cost});
            g1[y].push_back( (attr_child) {.child = x, .cost = cost});
        }
        
        vector<int> restored_points = {0,1};
        for(int i = 0 ; i < M ; i++){
            string city;
            cin >> city;
            restored_points.push_back(get_id(city));
        }



        vector<vector<attr_child> > g2(restored_points.size());
        for (int i = 0; i < restored_points.size(); i++){
            auto distance = bfs(g1,restored_points[i]);
            for (int j = 0 ; j < restored_points.size() ; j++){
                if (distance[restored_points[j]] <= cap)
                    g2[i].push_back((attr_child) {.child = j, .cost = distance[restored_points[j]]});
            }
        }

        auto dd =  bfs(g2,0);
        cout << (dd[1] == INF ? -1 : dd[1]) << endl;

    }
}
