
//
//  ntu1573 .c
//  fuck
//
//  Created by +u on 2015/7/6.
//  Copyright (c) 2015年 hortune. All rights reserved.
//

#include <iostream>
using namespace std;
#include <string>
#include <cstdio>
int main()
{
   
    int a;
    char h;
    cin>>a;
    getchar();
    while(a--)
    {
        string k;
        int ans=0;
        getline(cin,k);
        int num=0;
        for(int i=0;i<k.size();i++)
            if(k[i]=='(')num++;
            else
            {
                if(num>0)num--;
                else ans++;
            }
        cout<<ans+num<<endl;
    }
}