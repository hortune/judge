//  完全背包 DP 不只格式ㄎㄅ 還有溢位 還有浮點數誤差 幹
//  147 - Dollars.c
//  fuck
//
//  Created by +u on 2015/4/30.
//  Copyright (c) 2015年 hortune. All rights reserved.
//
#include <iostream>
using namespace std;
int kind[]={5,10,20,50,100,200,500,1000,2000,5000,10000};
long long int dp[40000]={};
int how(long long int k)
{
    int i=0;
    while(k)
    {
        k/=10;
        i++;
    }
    if(!i)
        return 1;
    else
    return i;
}
int main()
{
    dp[0]=1;
    for(int i=0;i<11;i++)
        for(int j=0;j<40000;j++)
            if(j>=kind[i])dp[j]+=dp[j-kind[i]];
    int a,a1;
    char o;
    bool first=1;
    while(cin>>a>>o>>a1,a+a1)
    {
        //if(!first)cout<<endl;
        int k,b;
        k=a*100+a1;
        long long int ans=dp[k];
        if(how(k)<=3)b=2;
        else b=5-how(k);
        while(b--)cout<<" ";
        cout<<k/100<<"."<<(k%100)/10<<k%10;
        b=17-how(ans);
        while(b--)cout<<" ";
        cout<<ans<<endl;
        //first=0;
    }
}