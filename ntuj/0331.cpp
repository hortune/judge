//
//  ntuj0331.c
//  fuck
//
//  Created by +u on 2015/6/2.
//  Copyright (c) 2015年 hortune. All rights reserved.
//

#include <iostream>
using namespace std;
#include <string>
#include <algorithm>
bool cmp(char a,char b)
{
    bool biga=0,bigb=0;
    if(a>='A'&&a<='Z'){biga=1;a=a-'A'+'a';}
    if(b>='A'&&b<='Z'){bigb=1;b=b-'A'+'a';}
    
    if(a==b)
        return biga;
    else
        return (int(a)<int(b));
}
int main()
{
    int num;
    string a;
    cin>>num;
    while(num--)
    {
        cin>>a;
        sort(a.begin(),a.end(),cmp);
        cout<<a<<endl;
        while(next_permutation(a.begin(),a.end()))
        {
            cout<<a<<endl;
        }
    }
}