//  uva 有空格 -.-
//  10405 - Longest Common Subsequence .c
//  fuck
//
//  Created by +u on 2015/4/30.
//  Copyright (c) 2015年 hortune. All rights reserved.
//
#include <iostream>
#include <string>
using namespace std;
static int dp[1001][1001]={};
int main()
{
    string a,b;
    while(getline(cin,a)){
        if(cin.eof())break;
        getline(cin,b);
        for(int i=1;i<=a.size();i++)
            for(int j=1;j<=b.size();j++)
                if(a[i-1]==b[j-1])dp[i][j]=dp[i-1][j-1]+1;
                else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        cout<<dp[a.size()][b.size()]<<endl;
    }
}