//
//  ntuj0059.c
//  fuck
//
//  Created by +u on 2015/10/21.
//  Copyright (c) 2015年 hortune. All rights reserved.
//

#include <iostream>
using namespace std;
#include <algorithm>
int main()
{
    int a[3]={},num[40]={};
    int b;
    while(cin>>b,b)
    {
        a[0]=a[1]=a[2]=0;
        for(int i=0;i<b;i++)
            cin>>num[i];
        sort(num,num+b);
        for(int i=b-1;i>-1;i--)
        {
            sort(a,a+3);
            a[0]+=num[i];
        }
        sort(a,a+3);
        cout<<a[2]<<endl;
    }
}