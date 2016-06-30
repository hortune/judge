//
//  ntuj2333.c
//  fuck
//
//  Created by +u on 2015/7/18.
//  Copyright (c) 2015年 hortune. All rights reserved.
//

#include <iostream>
#include <queue>
#include <vector>
using namespace std;
struct edge{int to,cost;};
typedef pair<int ,int > P;
int V, d[100001]={};
vector<edge> G[100001];
void dijkstra(int s)
{
    priority_queue<P, vector<P>, greater<P> > que;
    fill(d,d+V,2147483647);
    d[s]=0;
    que.push(P(0,s));
    while(!que.empty())
    {
        P p = que.top();que.pop();
        int v=p.second;
        if(d[v]<p.first)continue;
        for(int i=0;i<G[v].size();i++)
        {   edge e=G[v][i];
            if(d[e.to]>d[v]+e.cost)
            {
                d[e.to]=d[v]+e.cost;
                que.push(P(d[e.to],e.to));
            }
        }
    }
}
int main()
{
    int k,a;
    int ans[100001];
    cin>>a;
    while(a--)
    {
        cin>>V;
        int b,c,kkk;
        for(int i=1;i<V;i++)
        {
            cin>>b>>c>>kkk;
            G[b].push_back(edge{c,kkk});
            G[c].push_back(edge{b,kkk});
            
        }
        for(int i=0;i<100001;i++)
        ans[i]=0;
        for(int i=1;i<=k;i++)
        {
            dijkstra(i);
            for(int j=1;j<=V;j++)
                ans[j]+=d[j];
        }
        for(int i=1;i<=V;i++)
        cout<<ans[i]<<" ";
        cout<<endl;
    }
}