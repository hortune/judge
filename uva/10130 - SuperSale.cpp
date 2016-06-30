//
//  10130 - SuperSale.c
//  fuck
//
//  Created by +u on 2015/7/3.
//  Copyright (c) 2015年 hortune. All rights reserved.
//

#include <iostream>
using namespace std;
int main()
{
    int T,N,object[1001][2],ability[101],p_num,dp[50];
    cin>>T;
    while (T--) {
        cin>>N;
        for(int i=0;i<N;i++)cin>>object[i][0]>>object[i][1];
        cin>>p_num;
        for(int i=0;i<50;i++)dp[i]=0;
        for(int j=0;j<p_num;j++)cin>>ability[j];

        for(int i=0;i<N;i++)
            for(int j=49;j>=object[i][1];j--)
                dp[j]=max(dp[j-object[i][1]]+object[i][0],dp[j]);
        int sum=0;
        for(int i=0;i<p_num;i++)sum+=dp[ability[i]];
        cout<<sum<<endl;
    }
}