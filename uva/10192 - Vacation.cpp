//
//  10192 - Vacation.c
//  fuck
//
//  Created by +u on 2015/4/30.
//  Copyright (c) 2015年 hortune. All rights reserved.
//
#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
int dp[200][200]={};
int main()
{
    string a,b;
    int i=1;
    while(getline(cin,a),a!="#")
    {
        getline(cin,b);
        for(int i=1;i<=a.size();i++)
            for(int j=1;j<=b.size();j++)
                if(a[i-1]==b[j-1])dp[i][j]=dp[i-1][j-1]+1;
                else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        cout<<"Case #"<<i<<": you can visit at most "<<dp[a.size()][b.size()]<<" cities."<<endl;
        i++;
    }
}