//
//  ntuj005.c
//  fuck
//
//  Created by +u on 2015/6/2.
//  Copyright (c) 2015年 hortune. All rights reserved.
//

//wrong need to use graph theory
#include <cstdio>
#include <cstring>
int max(int a,int b)
{
    if(a>b)
        return a;
    else
        return b;
}

int dp(char str[],char str1[])
{
    int dpf[17][17]={};
    int length_str=strlen(str);
    int length_str1=strlen(str1);
    for(int i=1;i<=length_str;i++)
        for(int j=1;j<=length_str1;j++)
            if(str[i-1]==str1[j-1])dpf[i][j]=dpf[i-1][j-1]+1;
            else dpf[i][j]=max(dpf[i][j-1],dpf[i-1][j]);
    return dpf[length_str][length_str1];
}

int main()
{
    int num,a;
    char str[200][17];
    while(scanf("%d",&a)!=EOF)
    {
        int sum=0;
        for(int i=0;i<a;i++)
            scanf("%s",&str[i]);
        for(int i=0;i<a;i++)
            for(int j=i+1;j<a;j++)
                sum=max(dp(str[i],str[j]),sum);
        printf("%d\n",sum);
    }
}