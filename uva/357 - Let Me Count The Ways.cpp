//
//  357 - Let Me Count The Ways.c
//  fuck
//  long long = =  wtf
//  Created by +u on 2015/7/3.
//  Copyright (c) 2015年 hortune. All rights reserved.
//

#include <iostream>
using namespace std;
int main()
{
    long long int k[30100]={},j[]={1,5,10,25,50};
    
    
    k[0]=1;
    for(int p=0;p<5;p++)
        for(int i=0;i<=30001;i++)
            k[i+j[p]]+=k[i];
    int qwe;
    while(cin>>qwe)
    {
        if(cin.eof())break;
        
        if(k[qwe]==1)
        cout<<"There is only "<<k[qwe]<<" way to produce "<<qwe<<" cents change."<<endl;
        else
        cout<<"There are "<<k[qwe]<<" ways to produce "<<qwe<<" cents change."<<endl;
    }
}