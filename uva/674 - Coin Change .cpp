// dp 
//  674 - Coin Change .c
//  fuck
//
//  Created by +u on 2015/4/30.
//  Copyright (c) 2015年 hortune. All rights reserved.
//

#include <iostream>
using namespace std;
int dp[8000]={},po[]={1,5,10,25,50};

int main()
{
    dp[0]=1;
    for(int j=0;j<5;j++)
        for(int i=1;i<8000;i++)
            if(i>=po[j])dp[i]+=dp[i-po[j]];
    int l;
    while(cin>>l)
        if(cin.eof())break;
        else cout<<dp[l]<<endl;
}
