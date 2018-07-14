//
//  ntuj 2329.c
//  fuck
//
//  Created by +u on 2015/7/18.
//  Copyright (c) 2015年 hortune. All rights reserved.
//

#include <iostream>
using namespace std;
int main()
{
    int a,b,c,d,num;
    char e;
    cin>>num;
    while(num--)
    {
        cin>>a;
        cin>>e;
        cin>>b;
        if(e=='-')b=-b;
        cin>>e;
        cin>>c;
        cin>>e;
        cin>>d;
        if(e=='-')d=-d;
        cin>>e;
        
        cout<<a+c;
        if(b+d>=0)cout<<"+";
        cout<<b+d<<"i"<<endl;
    }
}