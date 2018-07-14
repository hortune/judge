//
//  ntuj1580.c
//  fuck
//
//  Created by +u on 2015/7/6.
//  Copyright (c) 2015年 hortune. All rights reserved.
//


/*#include <iostream>
using namespace std;
int main()
{
    long long int a=1;
    cout<<(a<<49)<<endl;
}*/
#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int count[2010]={};
    long long int T,N,k,i,ans;
    cin>>T;
    while(T--)
    {
        for(i=0;i<2010;i++)
            count[i]=0;             //初始化
        cin>>N;
        for(i=0;i<N;i++)
        {
            cin>>k;
            count[1000+k]++;        //建表
        }
        ans=0;
        long long g=N;
        for(i=2000;i>=0;i--)
            while(count[i])
            {
                count[i]--;
                g--;
                if(g>=1)
                    ans*=2;
                ans+=(i-1000);
            }
        
        long long gg=1;
        N--;
        while(N--)
        {
            gg*=2;
        }
        //cout<<gg<<endl;
        if(ans<0){
            ans=-ans;
            cout<<'-';
        }
        //cout<<ans<<endl;
        cout<<(ans/gg)<<'.';
        ans%=gg;
        
        for(i=0;i<7;i++)
        {
            ans*=10;
            cout<<ans/gg;
            ans%=gg;
            if(ans==0)break;
        }
        cout<<endl;
     
    }
}