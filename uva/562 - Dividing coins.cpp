//
//  562 - Dividing coins.c
//  fuck
//
//  Created by +u on 2015/7/3.
//  Copyright (c) 2015年 hortune. All rights reserved.
//

#include <iostream>
using namespace std;
int main()
{
    bool dp[50001]={};
    int num,num1,number[505];
    cin>>num;
    int sum;
    while(num--)
    {
        sum=0;
        cin>>num1;
        for(int i=0;i<num1;i++){cin>>number[i];sum+=number[i];}
        for(int j=0;j<sum+1;j++)dp[j]=0;
        dp[0]=1;
        for(int i=0;i<num1;i++)
            for(int j=sum-number[i];j>=0;j--)
                if(dp[j])dp[j+number[i]]=1;

        for(int i=sum/2; i>=0; i--)
        if(dp[i])
        {
            cout << sum-2*i << endl;
            break;
        }
    }
}