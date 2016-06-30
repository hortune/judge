//
//  ntuj2331.c
//  fuck
//
//  Created by +u on 2015/7/18.
//  Copyright (c) 2015年 hortune. All rights reserved.
//


//
//  ntuj2331.c
//  fuck
//
//  Created by +u on 2015/7/18.
//  Copyright (c) 2015年 hortune. All rights reserved.
//


#include <cstdio>
int main()
{

    
    int ans[26][26];
    //char str[500005]={};
    int a;
    char b;
    scanf("%d",&a);
    b=getchar();
    while(a--)
    {
        for(int i=0;i<26;i++)
            for(int j=0;j<26;j++)
                ans[i][j]=0;
        int g=0;
        while(1)
        {
            b=getchar();
            if(b=='\n')break;
            ans[g][b-'A']++;
            g++;
            if(g==26)g=0;
        };
        int sum=0,sum1=0;
        for(int i=0;i<26;i++)
        {
            sum=0;
            for(int j=0;j<26;j++)
                sum+=ans[j][((i+j)%26)];
            if(sum>sum1)sum1=sum;
        }
        printf("%d\n",sum1);
        
    }
}
/*#include <string>
 #include <cstdio>
 #include <iostream>
 using namespace std;
 
 int main()
 {
 int ans[26][26];
 int a;
 char b='A';
 cin.get(b);
 scanf("%d",&a);
 while(a--)
 {
 for(int i=0;i<26;i++)
 for(int j=0;j<26;j++)
 ans[i][j]=0;
 
 
 int g=0;
 while(1)
 {
 cin.get(b);
 if(b=='\n')break;
 ans[g][b-'A']++;
 g++;
 if(g==26)g=0;
 };
 
 for(int i=0;i<str.size();i++)
 ans[i%26][(str[i]-'A')]++;
 int sum=0,sum1=0;
 for(int i=0;i<26;i++)
 {
 sum=0;
 for(int j=0;j<26;j++)
 sum+=ans[j][((i+j)%26)];
 if(sum>sum1)sum1=sum;
 }
 printf("%d\n",sum1);
 
 }
 }*/