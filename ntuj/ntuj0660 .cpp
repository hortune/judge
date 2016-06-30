//
//  ntuj0660 .c
//  fuck
//
//  Created by +u on 2015/7/6.
//  Copyright (c) 2015年 hortune. All rights reserved.
//

#include <iostream>
using namespace std;
#include <vector>
#include <stack>
stack<int>k;
bool vis[100001]={};
vector<int> vec[100001];
bool dfs(int i)
{
    if(vec[i].empty())
        return 0;
    for(int g=0;g<vec[i].size();g++)
    {
        if(vis[vec[i][g]])
        {
            
        }
        k.push(vec[i][g]);
        
        dfs(vec[i][g]);
    }
    return 1;
};
int main()
{
    int a,b,c,d;
   
    while(cin>>a>>b,a+b)
    {
        for(int i=0;i<100001;i++)
            vis[i]=0;
       
        for(int i=0;i<b;i++)
        {
            cin>>c>>d;
            vec[c].push_back(d);
        }                         //存圖
        
        stack<int> k;
        for(int i=1;i<a;i++)
            if(!vis[i])
                dfs(i);
        
        
    }
    
}