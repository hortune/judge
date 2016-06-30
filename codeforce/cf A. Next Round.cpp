//
//  cf A. Next Round.c
//  fuck
//
//  Created by +u on 2015/7/21.
//  Copyright (c) 2015年 hortune. All rights reserved.
//

#include <iostream>
using namespace std;
int main()
{
    int a,b;
    cin>>a>>b;
    int ans;
    int ab[100000]={};
    for(int i=0;i<a;i++)
    {
        cin>>ab[i];
        
    }
    int stop;
    for(int i=0;i<a;i++)
    {
        if(ab[i]==0&&i<b)
        {
            ans=i;
            break;
        }
        if(i==(b-1))
            stop=ab[i];
        if(i>=b&&stop!=ab[i])
        {
            ans=i;
            break;
        }
        if(i==a-1)
            ans=a;
            
    }
    cout<<ans<<endl;
}