//
//  File.c
//  fuck
//
//  Created by +u on 2015/7/31.
//  Copyright (c) 2015年 hortune. All rights reserved.
//








#include <cstdio>
int main()
{
    int ele[1000000],ans[1000001]={};
    int a,b=0;
    scanf("%d",&a);
    for(int i=0;i<a;i++)
    {
        scanf("%d",&ele[i]);//cin>>ele[i];
        ans[ele[i]]++;
        if(ans[ele[i]]>b)b=ans[ele[i]];
        for(int j=2*ele[i];;j+=ele[i])
            if(j>1000000)break;
            else if(ans[ele[i]]>ans[j])
                ans[j]=ans[ele[i]];
        
    }
    printf("%d\n",b);
}