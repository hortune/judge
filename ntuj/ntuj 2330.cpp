//
//  ntuj 2330.c
//  fuck
//
//  Created by +u on 2015/7/18.
//  Copyright (c) 2015年 hortune. All rights reserved.

#include <iostream>
using namespace std;
int main()
{
    long long int a,b,sum;
    cin>>a;
    while(a--)
    {
        cin>>b;
        
        for(int i=2;i<b;i++)
        {
            long long int b1=b;
            sum=0;
            while(b1)
            {
                sum+=(b1%i);
                b1/=i;
            }
            cout<<sum<<" ";
        }
        cout<<endl;
        
    }
}