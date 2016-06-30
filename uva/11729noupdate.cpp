//
//  11729noupdate.c
//  fuck
//
//  Created by +u on 2014/5/26.
//  Copyright (c) 2014年 hortune. All rights reserved.
#include <iostream>
using namespace std;
#include <algorithm>
#include <vector>
struct haha
{
    int a,b;
    bool operator <(const haha& x)const{
        
        return b>x.b;
    };
}
int main()
{
    int a,k[1000][2];
    while(cin>>a,a)
    {
        for(int i=0;i<a;i++)
            cin>>k[i][0]>>k[i][1];
        
    
    }
}