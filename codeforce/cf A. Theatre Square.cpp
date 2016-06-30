//
//  cf A. Theatre Square.c
//  fuck
//
//  Created by +u on 2015/7/21.
//  Copyright (c) 2015年 hortune. All rights reserved.
//

#include <iostream>
using namespace std;
int main()
{
    long long int a,b,t;
    while(cin>>a)
    {
        if(cin.eof())break;
        cin>>b>>t;
        long long int ans=(a-1)/t,ans1=(b-1)/t;
        cout<<(ans+1)*(ans1+1)<<endl;
    }
}